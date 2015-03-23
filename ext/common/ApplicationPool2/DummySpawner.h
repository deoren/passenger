/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2011-2015 Phusion
 *
 *  "Phusion Passenger" is a trademark of Hongli Lai & Ninh Bui.
 *
 *  See LICENSE file for license information.
 */
#ifndef _PASSENGER_APPLICATION_POOL2_DUMMY_SPAWNER_H_
#define _PASSENGER_APPLICATION_POOL2_DUMMY_SPAWNER_H_

#include <ApplicationPool2/Spawner.h>

namespace Passenger {
namespace ApplicationPool2 {

using namespace std;
using namespace boost;
using namespace oxt;


class DummySpawner: public Spawner {
private:
	boost::mutex lock;
	unsigned int count;

public:
	unsigned int cleanCount;

	DummySpawner(const SpawnerConfigPtr &_config)
		: Spawner(_config)
	{
		count = 0;
		cleanCount = 0;
	}

	virtual SpawnObject spawn(const Options &options) {
		TRACE_POINT();
		possiblyRaiseInternalError(options);

		pid_t pid;
		{
			boost::lock_guard<boost::mutex> l(lock);
			count++;
			pid = count;
		}

		SocketPair adminSocket = createUnixSocketPair(__FILE__, __LINE__);
		SocketList sockets;
		sockets.add(pid, "main", "tcp://127.0.0.1:1234", "session", config->concurrency);
		syscalls::usleep(config->spawnTime);

		SpawnObject object;
		string gupid = "gupid-" + toString(pid);
		object.process = boost::make_shared<Process>(
			pid, gupid,
			adminSocket.second, FileDescriptor(), sockets,
			SystemTime::getUsec(), SystemTime::getUsec());
		object.process->dummy = true;
		return boost::move(object);
	}

	virtual bool cleanable() const {
		return true;
	}

	virtual void cleanup() {
		cleanCount++;
	}
};

typedef boost::shared_ptr<DummySpawner> DummySpawnerPtr;


} // namespace ApplicationPool2
} // namespace Passenger

#endif /* _PASSENGER_APPLICATION_POOL2_DUMMY_SPAWNER_H_ */

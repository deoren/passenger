/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2010-2017 Phusion Holding B.V.
 *
 *  "Passenger", "Phusion Passenger" and "Union Station" are registered
 *  trademarks of Phusion Holding B.V.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

/*
 * DirConfig/AutoGeneratedMergeFunction.cpp is automatically generated from DirConfig/AutoGeneratedMergeFunction.cpp.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/apache2/config_options.rb.
 * Edits to DirConfig/AutoGeneratedMergeFunction.cpp will be lost.
 *
 * To update DirConfig/AutoGeneratedMergeFunction.cpp:
 *   rake apache2
 *
 * To force regeneration of DirConfig/AutoGeneratedMergeFunction.cpp:
 *   rm -f src/apache2_module/DirConfig/AutoGeneratedMergeFunction.cpp
 *   rake src/apache2_module/DirConfig/AutoGeneratedMergeFunction.cpp
 */

namespace Passenger {
namespace Apache2Module {

static void
mergeDirConfig_autoGenerated(DirConfig *config, DirConfig *base, DirConfig *add) {
	config->mRuby =
		(!add->mRuby.empty())
		? add->mRuby
		: base->mRuby;
	config->mPython =
		(!add->mPython.empty())
		? add->mPython
		: base->mPython;
	config->mNodejs =
		(!add->mNodejs.empty())
		? add->mNodejs
		: base->mNodejs;
	config->mMeteorAppSettings =
		(!add->mMeteorAppSettings.empty())
		? add->mMeteorAppSettings
		: base->mMeteorAppSettings;
	config->mBaseURIs =
		(!add->mBaseURIs.empty())
		? add->mBaseURIs
		: base->mBaseURIs;
	config->mAppEnv =
		(!add->mAppEnv.empty())
		? add->mAppEnv
		: base->mAppEnv;
	config->mMinInstances =
		(add->mMinInstances != UNSET_INT_VALUE)
		? add->mMinInstances
		: base->mMinInstances;
	config->mMaxInstancesPerApp =
		(add->mMaxInstancesPerApp != UNSET_INT_VALUE)
		? add->mMaxInstancesPerApp
		: base->mMaxInstancesPerApp;
	config->mUser =
		(!add->mUser.empty())
		? add->mUser
		: base->mUser;
	config->mGroup =
		(!add->mGroup.empty())
		? add->mGroup
		: base->mGroup;
	config->mErrorOverride =
		(add->mErrorOverride != Apache2Module::UNSET)
		? add->mErrorOverride
		: base->mErrorOverride;
	config->mMaxRequests =
		(add->mMaxRequests != UNSET_INT_VALUE)
		? add->mMaxRequests
		: base->mMaxRequests;
	config->mStartTimeout =
		(add->mStartTimeout != UNSET_INT_VALUE)
		? add->mStartTimeout
		: base->mStartTimeout;
	config->mHighPerformance =
		(add->mHighPerformance != Apache2Module::UNSET)
		? add->mHighPerformance
		: base->mHighPerformance;
	config->mEnabled =
		(add->mEnabled != Apache2Module::UNSET)
		? add->mEnabled
		: base->mEnabled;
	config->mMaxRequestQueueSize =
		(add->mMaxRequestQueueSize != UNSET_INT_VALUE)
		? add->mMaxRequestQueueSize
		: base->mMaxRequestQueueSize;
	config->mMaxPreloaderIdleTime =
		(add->mMaxPreloaderIdleTime != UNSET_INT_VALUE)
		? add->mMaxPreloaderIdleTime
		: base->mMaxPreloaderIdleTime;
	config->mLoadShellEnvvars =
		(add->mLoadShellEnvvars != Apache2Module::UNSET)
		? add->mLoadShellEnvvars
		: base->mLoadShellEnvvars;
	config->mBufferUpload =
		(add->mBufferUpload != Apache2Module::UNSET)
		? add->mBufferUpload
		: base->mBufferUpload;
	config->mAppType =
		(!add->mAppType.empty())
		? add->mAppType
		: base->mAppType;
	config->mStartupFile =
		(!add->mStartupFile.empty())
		? add->mStartupFile
		: base->mStartupFile;
	config->mStickySessions =
		(add->mStickySessions != Apache2Module::UNSET)
		? add->mStickySessions
		: base->mStickySessions;
	config->mStickySessionsCookieName =
		(add->mStickySessionsCookieName != Apache2Module::UNSET)
		? add->mStickySessionsCookieName
		: base->mStickySessionsCookieName;
	config->mSpawnMethod =
		(!add->mSpawnMethod.empty())
		? add->mSpawnMethod
		: base->mSpawnMethod;
	config->mFriendlyErrorPages =
		(add->mFriendlyErrorPages != Apache2Module::UNSET)
		? add->mFriendlyErrorPages
		: base->mFriendlyErrorPages;
	config->mRestartDir =
		(!add->mRestartDir.empty())
		? add->mRestartDir
		: base->mRestartDir;
	config->mAppGroupName =
		(!add->mAppGroupName.empty())
		? add->mAppGroupName
		: base->mAppGroupName;
	config->mForceMaxConcurrentRequestsPerProcess =
		(add->mForceMaxConcurrentRequestsPerProcess != UNSET_INT_VALUE)
		? add->mForceMaxConcurrentRequestsPerProcess
		: base->mForceMaxConcurrentRequestsPerProcess;
	config->mLveMinUid =
		(add->mLveMinUid != UNSET_INT_VALUE)
		? add->mLveMinUid
		: base->mLveMinUid;
	config->mAppRoot =
		(!add->mAppRoot.empty())
		? add->mAppRoot
		: base->mAppRoot;
	config->mBufferResponse =
		(add->mBufferResponse != Apache2Module::UNSET)
		? add->mBufferResponse
		: base->mBufferResponse;
	config->mResolveSymlinksInDocumentRoot =
		(add->mResolveSymlinksInDocumentRoot != Apache2Module::UNSET)
		? add->mResolveSymlinksInDocumentRoot
		: base->mResolveSymlinksInDocumentRoot;
	config->mAllowEncodedSlashes =
		(add->mAllowEncodedSlashes != Apache2Module::UNSET)
		? add->mAllowEncodedSlashes
		: base->mAllowEncodedSlashes;
}


} // namespace Apache2Module
} // namespace Passenger
#  Phusion Passenger - https://www.phusionpassenger.com/
#  Copyright (C) 2008-2017  Phusion Holding B.V.
#
#  "Passenger", "Phusion Passenger" and "Union Station" are registered
#  trademarks of Phusion Holding B.V.
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; version 2 of the License.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License along
#  with this program; if not, write to the Free Software Foundation, Inc.,
#  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

require 'pathname'
SOURCE_ROOT = Pathname.new(File.expand_path(File.dirname(__FILE__)))
$LOAD_PATH.unshift(SOURCE_ROOT.to_s)
$LOAD_PATH.unshift("#{SOURCE_ROOT}/src/ruby_supportlib")

# Clean Bundler environment variables, preserve Rake environment variables.
# Otherwise all Ruby commands will take slightly longer to start, which messes up
# timing-sensitive tests like those in the C++ test suite.
if defined?(Bundler)
  clean_env = nil
  Bundler.with_clean_env do
    clean_env = ENV.to_hash
  end
  ENV.replace(clean_env)
  ARGV.each do |arg|
    if arg =~ /^(\w+)=(.*)$/m
      ENV[$1] = $2
    end
  end
end

def require_build_system_file(name)
  require "#{SOURCE_ROOT}/build/#{name}"
end

require("#{SOURCE_ROOT}/config") if File.exist?("#{SOURCE_ROOT}/config.rb")
require_build_system_file 'basics'
if boolean_option('ONLY_RUBY')
  require_build_system_file 'ruby_extension'
else
  require_build_system_file 'ruby_extension'
  require_build_system_file 'common_library'
  require_build_system_file 'agent'
  require_build_system_file 'apache2'
  require_build_system_file 'nginx'
  require_build_system_file 'packaging'
  require_build_system_file 'test_basics'
  require_build_system_file 'oxt_tests'
  require_build_system_file 'cxx_tests'
  require_build_system_file 'ruby_tests'
  require_build_system_file 'node_tests'
  require_build_system_file 'integration_tests'
  require_build_system_file 'misc'
end

#### Default tasks

task :default do
  abort "Please type one of:\n" +
    "  rake apache2\n" +
    "  rake nginx"
end

desc "Remove compiled files"
task :clean => 'clean:cache' do
  if OUTPUT_DIR == "buildout/"
    sh "rm -rf buildout"
  end
end

task 'common:clean' => 'clean:cache'
task 'clean:cache' do
  sh "rm -rf #{OUTPUT_DIR}cache"
end

desc "Remove all generated files"
task :clobber

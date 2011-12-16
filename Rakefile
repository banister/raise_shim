task :default do
  sh 'gcc -Wall -O2 -fpic -shared -ldl -g -I/home/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1/i686-linux -I/home/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1/ruby/backward -I/home/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1 -o raise_shim.so raise_shim.c'
end

namespace :osx do
  task :build do
    sh 'gcc -Wall -L/Users/john/.rvm/rubies/ruby-1.9.2-p290/lib/ -lruby -I/Users/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1/x86_64-darwin11.1.0  -I/Users/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1/ruby/backward -I/Users/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1 -o lib_overrides.dylib -dynamiclib ./raise_shim.c '
  end

  task :run do
    sh 'DYLD_FORCE_FLAT_NAMESPACE=1 DYLD_INSERT_LIBRARIES=lib_overrides.dylib pry'
  end
end

task :pry do
  sh "LD_PRELOAD=./raise_shim.so pry"
end

task :gdb do
  sh "gdb LD_PRELOAD=./raise_shim.so gdb --args ruby"
end


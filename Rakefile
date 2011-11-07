task :default do
  sh 'gcc -Wall -O2 -fpic -shared -ldl -g -I/home/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1/i686-linux -I/home/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1/ruby/backward -I/home/john/.rvm/rubies/ruby-1.9.2-p290/include/ruby-1.9.1 -o raise_shim.so raise_shim.c'
end

task :pry do
  sh "LD_PRELOAD=./raise_shim.so pry"
end

task :gdb do
  sh "gdb LD_PRELOAD=./raise_shim.so gdb --args ruby"
end


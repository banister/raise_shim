require 'pry_time'

PryTime.capture do |c|
  c.exception_type << ZeroDivisionError
end

def a
  1 / 0
end

a

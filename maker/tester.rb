require 'json'
require 'differ'


output = `rake test REPORTER=JsonReporter`

json = JSON.parse(output)
status = json['status']
puts "status: #{status}"

fails = json['fails']

fails.each do |f|
  puts "==== Failure ===="
  puts "Class: #{f['class']}"
  puts "Test: #{f['name']}"
  puts "Message: "
  lines = f['message'].split("\n")
  expected_line = "[unextracted]"
  actual_line = "[unextracted]"
  lines.each do |line|
    case line[0]
    when '-'
      expected_line = line
      expected_line[0] = ''
    when '+'
      actual_line = line
      actual_line[0] = ''
    end
  end
  puts "== Expected:"
  puts "#{expected_line}"
  puts "== Actual:"
  puts "#{actual_line}"
  puts "== Diff:"
  diff = Differ.diff_by_char expected_line, actual_line
  puts diff.format_as :color
  puts
  puts
end

require 'json'
require 'differ'


output = `rake test REPORTER=JsonReporter`

json = JSON.parse(output)

status = json['status']
puts "status: #{status}"

fails = json['fails']


yellow="\033[1;33m"
magenta="\033[1;95m"

# see the section "88/256 Colors" at https://misc.flogisoft.com/bash/tip_colors_and_formatting
orange="\033[38;5;208m"
good_red="\033[38;5;196m"
red="\033[1;31m"
reset_text="\033[0m"
style_underlined="\e[4m"
style_normal="\e[24m"


fails.each do |f|
  puts
  puts
  puts "#{good_red}==== Failure ====#{reset_text}"
  puts "#{yellow}#{f['location']}#{reset_text}"
  puts "#{yellow}#{f['name']}#{reset_text}"

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
  puts "#{orange}#{style_underlined}Expected#{style_normal}\n#{expected_line}#{reset_text}"
  puts "#{good_red}#{style_underlined}Actual#{style_normal}\n#{actual_line}#{reset_text}"
  puts "#{style_underlined}Diff#{style_normal}\n"#{actual_line}#{reset_text}"
  diff = Differ.diff_by_char actual_line, expected_line
  puts diff.format_as :color
end

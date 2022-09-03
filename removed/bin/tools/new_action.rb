


class String
  def underscore
    self.gsub(/::/, '/').
    gsub(/([A-Z]+)([A-Z][a-z])/,'\1_\2').
    gsub(/([a-z\d])([A-Z])/,'\1_\2').
    tr("-", "_").
    downcase
  end

  def camel_case
    return self if self !~ /_/ && self =~ /[A-Z]+.*/
    split('_').map{|e| e.capitalize}.join
  end
end



# get a arg for the class name
class_name = ARGV[0]
abort 'Please provide valid arguments' if class_name.nil?


# open the file
source_template_file = File.open('tools/templates/__action_template.cpp', 'r')
header_template_file = File.open('tools/templates/__action_template.h', 'r')


# read the contents to string
source_code = source_template_file.read
header_code = header_template_file.read


# create our strings for replacing

class_name_camel_case = class_name.camel_case
class_name_snake_case = class_name.underscore
class_name_constantized = class_name.underscore.upcase


# overwrite the template tokens
source_code.gsub!(/CLASS_NAME/, class_name_camel_case)
source_code.gsub!(/SNAKECASE_ACTION_NAME/, class_name_snake_case)
source_code.gsub!(/CONSTANTIZED_ACTION_NAME/, "#{class_name_constantized}_ACTION_IDENTIFIER")
header_code.gsub!(/CLASS_NAME/, class_name_camel_case)
header_code.gsub!(/SNAKECASE_ACTION_NAME/, class_name_snake_case)


# save the file with a new filename
source_filename = "../src/actions/#{class_name.underscore}_action.cpp"
header_filename = "../include/fullscore/actions/#{class_name.underscore}_action.h"
IO.write(source_filename, source_code)
IO.write(header_filename, header_code)


# output filenames generated
puts "generated #{source_filename}"
puts "generated #{header_filename}"


# write `git commit -m "Create source files for CLASS_NAME action"`
# `git reset`
# `git add #{source_filename}`
# `git add #{header_filename}`
# `git commit -m "Create source files for #{class_name.camel_case} action"`




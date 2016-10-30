


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



# open the file
source_template_file = File.open('tools/templates/__transform_action_template.cpp', 'r')
header_template_file = File.open('tools/templates/__transform_action_template.h', 'r')


# read the contents to string
source_code = source_template_file.read
header_code = header_template_file.read


# overwrite the template tokens
class_name = 'ThisIsClassName'
source_code.gsub!(/CLASS_NAME/, class_name.camel_case)
source_code.gsub!(/SNAKECASE_ACTION_NAME/, class_name.underscore)
header_code.gsub!(/CLASS_NAME/, class_name.camel_case)
header_code.gsub!(/SNAKECASE_ACTION_NAME/, class_name.underscore)


# save the file with a new filename
source_filename = "src/actions/transforms/#{class_name.underscore}_action.cpp"
header_filename = "include/fullscore/actions/transforms/#{class_name.underscore}_action.h"
IO.write(source_filename, source_code)
IO.write(header_filename, header_code)


# write `git commit -m "Create source files for CLASS_NAME action"`





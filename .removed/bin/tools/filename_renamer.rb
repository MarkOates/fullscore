## this script should run from base directory of the repo
require 'pathname'
require_relative 'helpers/file_renamer.rb'
require_relative 'helpers/include_line_generator.rb'
require_relative 'helpers/header_file_replacer.rb'


#----- rename the files

all_files = Dir['**/*']

cpp_files = all_files.select.grep(/src\/.+\.cpp/)
h_files = all_files.select.grep(/include\/fullscore\/.+\.h/)
test_files = all_files.select.grep(/tests\/.+\.cpp/)

files = cpp_files + h_files + test_files


files.each do |filename|
  renamer = FileRenamer.new(filename, FileRenamer::CAMEL_CASE)
  puts "Renaming #{filename} to #{renamer.transformed_filename}"
  puts renamer.rename
end


#----- replace the "#include <...>" header filenames in the files

all_files = Dir['**/*']

cpp_files = all_files.select.grep(/src\/.+\.cpp/)
h_files = all_files.select.grep(/include\/fullscore\/.+\.h/)
test_files = all_files.select.grep(/tests\/.+\.cpp/)

files = cpp_files + h_files + test_files

h_files.each do |filename|
  snake_case_include_line = IncludeLineGenerator.new(filename, IncludeLineGenerator::SNAKE_CASE).generate
  camel_case_include_line = IncludeLineGenerator.new(filename, IncludeLineGenerator::CAMEL_CASE).generate

  files.each do |file_name|
    puts file_name
    replacer = HeaderFilenameReplacer.new(file_name, snake_case_include_line, camel_case_include_line)
    replacer.replace
  end
end

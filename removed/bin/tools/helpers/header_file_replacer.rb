require 'pathname'

class HeaderFilenameReplacer
  attr_reader :file_name
  attr_reader :old_header_line
  attr_reader :new_header_line

  def initialize(file_name, old_header_line, new_header_line)
    @file_name = file_name
    @old_header_line = old_header_line
    @new_header_line = new_header_line
  end

  def replace
    text = File.read(file_name)
    new_contents = text.gsub(/#{old_header_line}/, new_header_line)
    File.open(file_name, "w") {|file| file.puts new_contents }
  end
end

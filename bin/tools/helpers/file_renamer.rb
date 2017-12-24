require 'pathname'

class FileRenamer
  CAMEL_CASE = 'camel_case'.freeze
  SNAKE_CASE = 'snake_case'.freeze

  attr_reader :filename
  attr_reader :transformation

  def initialize(filename, transformation)
    @filename = filename
    @transformation = transformation
  end

  def rename
    File.rename(filename, transformed_filename)
  end

  def transformed_filename
    @transformed_filename ||= begin
      pathname = Pathname.new(filename)
      transformed_filebase = transform(pathname.basename.sub_ext('').to_s)
      [pathname.dirname, [transformed_filebase, pathname.extname].join('')].join('/')
    end
  end

  private

  def transform(str)
    case transformation
    when CAMEL_CASE
      camel_case(str)
    when SNAKE_CASE
      underscore(str)
    end
  end

  def underscore(str)
    str.gsub(/::/, '/').
    gsub(/([A-Z]+)([A-Z][a-z])/,'\1_\2').
    gsub(/([a-z\d])([A-Z])/,'\1_\2').
    tr("-", "_").
    downcase
  end

  def camel_case(str)
    return str if str !~ /_/ && str =~ /[A-Z]+.*/
    str.split('_').map{|e| e.capitalize}.join
  end
end

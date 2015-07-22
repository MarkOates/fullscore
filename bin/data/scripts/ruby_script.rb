


class RubyClass
	def initialize name
		@name = name
	end
	def get_output_message
		"  This is my world, " + @name
	end
end

puts "This is the output of the Ruby Script"
puts "There are " + ARGV.length.to_s + " arguments provided when running the script."
puts "The output of the class is ..."

myclass = RubyClass.new ARGV.first

puts myclass.get_output_message


gem 'minitest', '~> 5.4'
require 'minitest/autorun'


case ENV['REPORTER']
when 'JsonReporter'
  require 'minitest/reporters/json_reporter'
  Minitest::Reporters.use! [ Minitest::Reporters::JsonReporter.new ]
when 'ProgressReporter'
  require "minitest/reporters"
  Minitest::Reporters.use!
when 'HtmlReporter'
  require 'minitest/reporters'
  Minitest::Reporters.use! [ Minitest::Reporters::HtmlReporter.new ]
else
  require 'minitest/reporters'
  Minitest::Reporters.use! [ Minitest::Reporters::DefaultReporter.new(:color => true) ]
end



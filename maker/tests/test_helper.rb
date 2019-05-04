gem 'minitest', '~> 5.4'
require 'minitest/autorun'


## will use the default reporter for the minitest-reporters gem, which is a progress bar
#require "minitest/reporters"
#Minitest::Reporters.use!


## will output test results a JSON string
#require 'minitest/reporters/json_reporter'
#Minitest::Reporters.use! [ Minitest::Reporters::JsonReporter.new ]


## will output an html report (looks nice) to test/html_reports/index.html
#require 'minitest/reporters'
#Minitest::Reporters.use! [ Minitest::Reporters::HtmlReporter.new ]


# will output the usual output, but colored green/red for success/failure
require 'minitest/reporters'
Minitest::Reporters.use! [Minitest::Reporters::DefaultReporter.new(:color => true)]

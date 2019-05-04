require 'json'

output = `rake test REPORTER=JsonReporter`

json = JSON.parse(output)
status = json['status']
puts "status: #{status}"

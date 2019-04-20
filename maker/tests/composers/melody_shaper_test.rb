gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/chord_notes'
require 'minitest/reporters'
Minitest::Reporters.use! [Minitest::Reporters::DefaultReporter.new(:color => true)]

class MelodyShaperTest < Minitest::Test
  def test_works
    assert true
  end
end

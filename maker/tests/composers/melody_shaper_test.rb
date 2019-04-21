gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../app/composers/melody_shaper'
require 'minitest/reporters'
Minitest::Reporters.use! [Minitest::Reporters::DefaultReporter.new(:color => true)]

class MelodyShaperTest < Minitest::Test
  def test_works
    assert true
  end
end

class DurationSubtractorTest < Minitest::Test
  def subtract_duration(duration1:, duration2:)
    DurationSubtractor.new(duration1: duration1, duration2: duration2).result
  end

  def test_subtracts_a_half_note_from_a_quarter_note
    assert_equal 2, subtract_duration(duration1: 1, duration2: 2)
  end

  def test_when_unable_to_subtract_durations_raises_an_exception
    assert_raises DurationSubtractor::UnknownSubtraction do
      subtract_duration(duration1: 8, duration2: 1)
    end
  end
end

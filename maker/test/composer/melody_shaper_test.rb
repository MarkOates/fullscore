require_relative '../../app/composer/melody_shaper'
require_relative '../test_helper'

class MelodyShaperTest < Minitest::Test
  def test_staves_returns_the_expected_hash
    melody_shaper = MelodyShaper.new

    assert melody_shaper.staves
  end
end

class DurationSubtractorTest < Minitest::Test
  def subtract_duration(duration1:, duration2:)
    DurationSubtractor.new(duration1: duration1, duration2: duration2).result
  end

  def test_subtracts_a_half_note_from_a_quarter_note
    assert_equal 2, subtract_duration(duration1: 1, duration2: 2)
  end

  def test_subtracts_a_eighth_note_from_a_half_note
    result = subtract_duration(duration1: 2, duration2: 8)

    assert_equal 4, result.duration
    assert_equal 1, result.duration_dots
  end

  def test_when_unable_to_subtract_durations_raises_an_exception
    assert_raises DurationSubtractor::UnknownSubtraction do
      subtract_duration(duration1: 8, duration2: 1)
    end
  end
end

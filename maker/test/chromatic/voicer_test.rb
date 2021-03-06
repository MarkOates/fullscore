require_relative '../../lib/chromatic/voicer'
require_relative '../test_helper'

module Chromatic
  class VoicerTest < Minitest::Test
    def test_high_range_voicer
      notes = [0, 4, 7]
      expected_notes = [12, 4+12, 7+12]
      assert_equal expected_notes, Voicer.new(notes).high_range
    end

    def test_low_range_voicer
      notes = [0, 4, 7]
      expected_notes = [-12, 4-12, 7-12]
      assert_equal expected_notes, Voicer.new(notes).low_range
    end

    def test_center_range_voicer
      notes = [0, 4, 7]
      expected_notes = notes
      assert_equal expected_notes, Voicer.new(notes).center_range
    end

    def test_ultra_high_range_voicer
      notes = [0, 4, 7]
      expected_notes = [24, 4+24, 7+24]
      assert_equal expected_notes, Voicer.new(notes).ultra_high_range
    end

    def test_ultra_low_range_voicer
      notes = [0, 4, 7]
      expected_notes = [-24, 4-24, 7-24]
      assert_equal expected_notes, Voicer.new(notes).ultra_low_range
    end

    def test_open_open_spaces_the_chord
      notes = [0, 4, 7]
      expected_notes = [0, 16, 7]
      assert_equal expected_notes, Voicer.new(notes).open
    end

    def test_properly_handles_rests
      notes = 'r'
      expected_notes = 'r'
      assert_equal expected_notes, Voicer.new(notes).open
    end
  end
end

gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../lib/chromatic/expander'

module Chromatic
  class ExpanderTest < Minitest::Test
    def test_open_retains_the_root
      notes = [0, 4, 7]
      expected_notes = [0, 7, 16]
      assert_equal expected_notes, Expander.new(notes).expand
    end

    def test_extrapolate_extrapolates_the_notes_upward
      notes = [0, 4, 7]
      expected_notes = [0, 4, 7, 12, 16, 19, 24, 28, 31]
      assert_equal expected_notes, Expander.new(notes).extrapolate(6)
    end

    def test_extrapolate_to_extrapolates_up_to_a_maximum_note_1
      notes = [0, 4, 7]
      expected_notes = [0, 4, 7, 12, 16, 19, 24, 28, 31, 36, 40, 43, 48]
      assert_equal expected_notes, Expander.new(notes).extrapolate_to(48)
    end

    def test_extrapolate_to_extrapolates_up_to_a_maximum_note_2
      notes = [0, 6]
      expected_notes = [0, 6, 12, 18, 24, 30, 36, 42, 48, 54]
      assert_equal expected_notes, Expander.new(notes).extrapolate_to(54)
    end
  end
end

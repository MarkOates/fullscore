gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../lib/diatonic/lily_diatonic_converter'

module Diatonic
  class LilyDiatonicConverterTest < Minitest::Test
    def test_parses_middle_c
      notes = [1]
      converter = LilyDiatonicConverter.new(notes: notes)
      expected_output = "c'"
      assert_equal expected_output, converter.convert
    end

    def test_parses_simple_example
      notes = [1, 2]
      converter = LilyDiatonicConverter.new(notes: notes)
      expected_output = "c' d'"
      assert_equal expected_output, converter.convert
    end

    def test_parses_longer_example
      notes = [1, 2, 4, 5, 7]
      converter = LilyDiatonicConverter.new(notes: notes)
      expected_output = "c' d' f' g' b'"
      assert_equal expected_output, converter.convert
    end

    def test_parses_notes_outside_of_the_scale
      notes = [1, 2, 4, 5, 7, 9]
      converter = LilyDiatonicConverter.new(notes: notes)
      expected_output = "c' d' f' g' b' d''"
      assert_equal expected_output, converter.convert
    end

    def test_with_an_unknown_note_number_raises_an_exception
      notes = ['n']
      assert_raises LilyDiatonicConverter::UnknownFramentType do
        LilyDiatonicConverter.new(notes: notes).convert
      end
    end

    def test_converts_a_chord
      notes = [[1, 4, 7], [5, 7, 9]]
      converter = LilyDiatonicConverter.new(notes: notes)
      expected_output = "<c' f' b'> <g' b' d''>"
      assert_equal expected_output, converter.convert
    end
  end
end

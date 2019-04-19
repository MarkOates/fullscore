gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../lib/chromatic/lily_converter'

module Chromatic
  class LilyConverterTest < Minitest::Test
    def test_parses_middle_c
      notes = [0]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c'"
      assert_equal expected_output, converter.convert
    end

    def test_parses_simple_example
      notes = [0, 2]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c' d'"
      assert_equal expected_output, converter.convert
    end

    def test_parses_longer_example
      notes = [0, 2, 4, 5, 7, 9]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c' d' e' f' g' a'"
      assert_equal expected_output, converter.convert
    end

    def test_with_an_unknown_note_number_raises_an_exception
      notes = ['n']
      assert_raises LilyConverter::UnknownFramentType do
        LilyConverter.new(notes: notes).convert
      end
    end

    def test_converts_a_chord
      notes = [[0, 4, 7], [5, 9, 2]]
      converter = LilyConverter.new(notes: notes)
      expected_output = "<c' e' g'> <f' a' d'>"
      assert_equal expected_output, converter.convert
    end

    def test_supports_notes_with_negative_values
      notes = [-12, [-24, -5]]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c <c, g>"
      assert_equal expected_output, converter.convert
    end
  end
end

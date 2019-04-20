gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../lib/chromatic/lily_converter'
require 'minitest/reporters'
Minitest::Reporters.use! [Minitest::Reporters::DefaultReporter.new(:color => true)]

module Chromatic
  class LilyConverterTest < Minitest::Test
    def test_parses_middle_c
      notes = [0]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c'4"
      assert_equal expected_output, converter.convert
    end

    def test_parses_simple_example
      notes = [0, 2]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c'4 d'4"
      assert_equal expected_output, converter.convert
    end

    def test_parses_longer_example
      notes = [0, 2, 4, 5, 7, 9]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c'4 d'4 e'4 f'4 g'4 a'4"
      assert_equal expected_output, converter.convert
    end

    def test_with_an_unknown_note_number_raises_an_exception
      notes = [ TrueClass ]
      assert_raises LilyConverter::UnknownFramentType do
        LilyConverter.new(notes: notes).convert
      end
    end

    def test_with_an_unknown_note_number_raises_an_exception
      notes = ['x']
      assert_raises LilyConverter::UnknownStringFragmentType do
        LilyConverter.new(notes: notes).convert
      end
    end

    def test_with_a_rest_returns_a_rest
      notes = ['r']
      expected_output = 'r4'
      assert_equal expected_output, LilyConverter.new(notes: notes).convert
    end

    def test_with_notes_including_a_rest
      notes = ['r', 12, 'r', 7]
      expected_output = "r4 c''4 r4 g'4"
      assert_equal expected_output, LilyConverter.new(notes: notes).convert
    end

    def test_converts_a_chord
      notes = [[0, 4, 7], [5, 9, 2]]
      converter = LilyConverter.new(notes: notes)
      expected_output = "<c' e' g'>4 <f' a' d'>4"
      assert_equal expected_output, converter.convert
    end

    def test_supports_notes_with_negative_values
      notes = [-12, [-24, -5]]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c4 <c, g>4"
      assert_equal expected_output, converter.convert
    end

    def test_supports_notes_extending_beyond_the_12_note_octave
      notes = [14, [24, 19]]
      converter = LilyConverter.new(notes: notes)
      expected_output = "d''4 <c''' g''>4"
      assert_equal expected_output, converter.convert
    end
  end
end

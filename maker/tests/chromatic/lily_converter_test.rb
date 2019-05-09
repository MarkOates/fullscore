require_relative '../../lib/chromatic/lily_converter'
require_relative '../test_helper'

require 'ostruct'

module Chromatic
  class LilyConverterTest < Minitest::Test
    class NoteWithPitches
      attr_reader :pitches

      def initialize(pitches: 3)
        @pitches = pitches
      end
    end

    class NoteWithArticulations
      attr_reader :articulations

      def initialize(articulations:)
        @articulations = articulations
      end

      def pitches
        [2, 4]
      end
    end

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

    def test_parses_example_with_pitch_message_sender
      notes = [0, Chromatic::LilyConverterTest::NoteWithPitches.new(pitches: 2)]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c'4 d'4"
      assert_equal expected_output, converter.convert
    end

    def test_with_an_articulation_will_convert
      notes = [0, Chromatic::LilyConverterTest::NoteWithArticulations.new(articulations: 'marcato')]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c'4 <d' e'>4\\marcato"
      assert_equal expected_output, converter.convert
    end

    def test_parses_longer_example
      notes = [0, 2, 4, 5, 7, 9]
      converter = LilyConverter.new(notes: notes)
      expected_output = "c'4 d'4 e'4 f'4 g'4 a'4"
      assert_equal expected_output, converter.convert
    end

    def test_with_an_unexpected_note_class_raises_an_exception
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

    def test_supports_full_measure_rests
      notes = ['R']
      expected_output = 'R4'
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

    def test_with_a_fragment_that_recieves_duration_uses_it_for_duration
      fragment = OpenStruct.new({
        pitches:       [0, 2, 4],
        duration:      8,
      })

      converter = LilyConverter.new(notes: [fragment])
      expected_output = "<c' d' e'>8"

      assert_equal expected_output, converter.convert
    end

    def test_with_a_fragment_that_recieves_duration_dots_will_include_it
      fragment = OpenStruct.new({
        pitches:       [0, 2, 4],
        duration:      2,
        duration_dots: 2,
      })

      converter = LilyConverter.new(notes: [fragment])
      expected_output = "<c' d' e'>2.."

      assert_equal expected_output, converter.convert
    end
  end
end

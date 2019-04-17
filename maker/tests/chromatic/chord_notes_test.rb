gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../lib/chromatic/chord_notes'

module Chromatic
  class ChordNotesTest < Minitest::Test
    def test_plots_notes_in_a_chord
      expcected = [0, 4, 7]
      actual = ChordNotes.new.chord_notes('I')
      assert_equal expcected, actual
    end

    def test_plots_notes_a_V_chord
      expcected = [7, 11, 14]
      actual = ChordNotes.new.chord_notes('V')
      assert_equal expcected, actual
    end

    def test_plots_notes_a_ii_chord
      expcected = [2, 5, 9]
      actual = ChordNotes.new.chord_notes('ii')
      assert_equal expcected, actual
    end

    def test_plots_notes_a_iii_chord
      expcected = [4, 7, 11]
      actual = ChordNotes.new.chord_notes('iii')
      assert_equal expcected, actual
    end

    def test_with_an_nuparsable_chord_symbol_raises_an_exception
      assert_raises Chromatic::ChordNotes::UnparsableChordNote do
        ChordNotes.new.chord_notes('xxx+')
      end
    end

    def test_plots_notes_a_IV_chord
      expcected = [5, 8, 12]
      actual = ChordNotes.new.chord_notes('IV')
      assert_equal expcected, actual
    end

    def test_plots_notes_a_vi_chord
      expcected = [9, 12, 16]
      actual = ChordNotes.new.chord_notes('vi')
      assert_equal expcected, actual
    end

    def test_returns_a_chord_progression
      skip
      progression = ['vi', 'I', 'V', 'I']
      expcected = [[6, 8, 10], [1, 3, 5], [5, 7, 9], [1, 3, 5]]
      actual = ChordNotes.progression(progression)
      assert_equal expcected, actual
    end

    def test_invert_inverts_a_chord
      skip
      chord_vi_expected = [8, 10, 13]
      chord_I_expected = [3, 5, 8]

      assert_equal chord_vi_expected, ChordNotes.new.invert('vi')
      assert_equal chord_I_expected, ChordNotes.new.invert('I')
    end

    def test_adapter_doo
      skip
      expected_notes = ['vi', 'V6', 'I']
      assert_equal expected_notes, ChordNotes.new.chords('ascending_bass')
    end

    def test_integraion_works_in_combination
      skip
      expected = [[6, 8, 10], [7, 9, 12], [1, 3, 5]]
      assert_equal expected, ChordNotes.notes_for('ascending_bass')
    end

    def test_circle_of_5ths
      skip
      expected = [[1, 3, 5], [4, 6, 8], [7, 9, 11], [3, 5, 7], [6, 8, 10], [2, 4, 6], [5, 7, 9]]
      assert_equal expected, ChordNotes.notes_for('circle_of_5ths')
    end

    def test_note_name_returns_the_name_of_the_note
      skip
      notes = [1, 2, 3, 4, 5, 6, 7]
      expected = ['c', 'd', 'e', 'f', 'g', 'a', 'b']
      assert_equal expected, ChordNotes.new.note_name(notes)
    end
  end
end

gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/chord_notes'

class ChordNotesTest < Minitest::Test
  def test_plots_notes_in_a_chord
    expcected = [1, 3, 5]
    actual = ChordNotes.new(I).notes
    assert_equal expcected, actual
  end

  def test_plots_notes_a_V_chord
    expcected = [5, 7, 9]
    actual = ChordNotes.new(V).notes
    assert_equal expcected, actual
  end

  def test_plots_notes_a_IV_chord
    expcected = [4, 6, 8]
    actual = ChordNotes.new(IV).notes
    assert_equal expcected, actual
  end

  def test_plots_notes_a_vi_chord
    expcected = [6, 8, 10]
    actual = ChordNotes.new('vi').notes
    assert_equal expcected, actual
  end

  def test_returns_a_chord_progression
    progression = ['vi', I, V, I]
    expcected = [[6, 8, 10], [1, 3, 5], [5, 7, 9], [1, 3, 5]]
    actual = ChordNotes.progression(progression)
    assert_equal expcected, actual
  end
end

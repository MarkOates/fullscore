gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../app/composers/path_follower'
require 'minitest/reporters'
Minitest::Reporters.use! [Minitest::Reporters::DefaultReporter.new(:color => true)]

class PathFollowerTest < Minitest::Test
  def test_returns_staves
    path_follower = PathFollower.new

    assert path_follower.staves
  end

  def test_transpose_up_ocate_works
    initial_notes = [0, 2, 4, 7, 12, 14]
    expected = [12, 14, 16, 19, 24, 26]

    result = PathFollower.new.transpose_up_octave(notes: initial_notes)
    assert_equal result, expected
  end

  def test_transpose_up_ocate_works
    initial_notes = [0, 2, 4, 7, 12, 14]
    expected = [12, 14, 16, 19, 24, 26]

    actual = PathFollower.new.transpose_up_octave(notes: initial_notes)
    assert_equal expected, actual
  end

  def test_transpose_down_ocate_works
    initial_notes = [0, 2, 4, 7, 12, 14]
    expected = [-12, -10, -8, -5, 0, 2]

    actual = PathFollower.new.transpose_down_octave(notes: initial_notes)
    assert_equal expected, actual
  end

  def test_normalize_within_octave
    initial_notes = [-24, -5, 0, 2, 16, 7, 12, 14]
    expected = [0, 7, 2, 4]

    actual = PathFollower.new.normalize_within_octave(notes: initial_notes)
    assert_equal expected, actual
  end

  def test_project_many_octaves
    initial_notes = [0, 4, 7]
    expected = [
      -24, -20, -17,
      -12, -8, -5,
      0, 4, 7,
      12, 16, 19,
      24, 28, 31
    ]

    actual = PathFollower.new.project_many_octaves(notes: initial_notes)
    assert_equal expected, actual
  end

  def test_resolve_melody_with_an_invalid_progression_and_start_note_raises
    path_follower = PathFollower.new

    raised_error = assert_raises PathFollower::UnresolvableMelody do
      path_follower.resolve_melody(
        progression: [[7, 11, 14, 17], [0, 4, 7]],
        start_note: 2,
      )
    end

    expected_error_message = "The start_note note #{2} must be present in the " \
      "first chord of the progression #{[[7, 11, 14, 17], [0, 4, 7]]}"

    assert_equal expected_error_message, raised_error.message
  end

  def test_resovle_pitch_returns_the_preferred_note_if_it_exists_in_the_chord
    path_follower = PathFollower.new

    expected_resolved_pitch = 4
    resolved_pitch = path_follower.resolve_pitch(chord: [0, 4, 7], note: 4)

    assert_equal expected_resolved_pitch, resolved_pitch
  end

  def test_resovle_pitch_returns_a_preferred_note_to_resolve_into_a_chord
    path_follower = PathFollower.new

    expected_resolved_pitch = 0
    resolved_pitch = path_follower.resolve_pitch(chord: [0, 4, 7], note: 2)

    assert_equal expected_resolved_pitch, resolved_pitch
  end

  def test_resovle_pitch_returns_a_preferred_note_to_resolve_into_a_chord_2
    path_follower = PathFollower.new

    expected_resolved_pitch = 2
    resolved_pitch = path_follower.resolve_pitch(chord: [0, 2, 4, 7, 9, 11], note: 3)

    assert_equal expected_resolved_pitch, resolved_pitch
  end

  def test_resovle_pitch_returns_a_preferred_note_to_resolve_with_preference_into_a_chord
    path_follower = PathFollower.new

    note = 3
    chord = [0, 4, 7, 9, 11]
    preference = [:matching, :upward, :downward]

    expected_resolved_pitch = 4
    resolved_pitch = path_follower.resolve_pitch(note: note, chord: chord, preference: preference)

    assert_equal expected_resolved_pitch, resolved_pitch
  end

  def test_resovle_melody_starts_the_melody_with_the_first_pitch__sanity_check
    path_follower = PathFollower.new

    progression = [[7, 11, 14], [0, 4, 7]]

    start_note = 7
    expected_first_note = start_note
    result_melody = path_follower.resolve_melody(progression: progression, start_note: start_note)

    assert_equal start_note, expected_first_note
  end

  def test_middle_note_returns_the_middle_note_of_a_chord
    path_follower = PathFollower.new
    chord = [0, 2, 4, 7, 9]
    expected_middle_note = 4
    actual_note = path_follower.middle_note(notes: chord)

    assert_equal expected_middle_note, actual_note
  end

  def test_middle_note_returns_the_middle_note_of_a_chord_with_an_offset
    path_follower = PathFollower.new
    chord = [0, 2, 4, 7, 9]
    expected_middle_note = 9
    actual_note = path_follower.middle_note(notes: chord, offset: 2)

    assert_equal expected_middle_note, actual_note
  end
end

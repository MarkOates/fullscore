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
end

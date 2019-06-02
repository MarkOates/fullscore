require_relative '../lib/vector'
require_relative 'test_helper'

class ChromaticVectorTest < Minitest::Test
  def chromatic_vector(direction:)
    @chromatic_vector ||= ChromaticVector.new(direction: direction)
  end

  def test_chromatic_vector_doenst_blow_up
    assert chromatic_vector(direction: 'i').render
  end

  def test_chromatic_vector_renders_the_expected_vector
    expected = { normalized: [ 9, 12, 16 ], root: 9 }
    actual = chromatic_vector(direction: 'vi').render

    assert_equal expected, actual
  end

  def test_chromatic_vector_renders_the_expected_vector_2
    expected = { normalized: [ 2, 6, 9 ], root: 2 }
    actual = chromatic_vector(direction: 'II').render

    assert_equal expected, actual
  end
end

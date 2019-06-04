require_relative '../../lib/chromatic/vector'
require_relative '../test_helper'

class ChromaticVectorTest < Minitest::Test
  def chromatic_vector(direction:)
    @chromatic_vector ||= ChromaticVector.new(direction: direction)
  end

  def test_chromatic_vector_doenst_blow_up
    assert chromatic_vector(direction: 'i').render
  end

  def test_chromatic_vector_renders_the_expected_vector
    expected = { normalized: [ 9, 12, 16 ], root: 9, quality: 'minor', name: [ 'vi' ] }
    actual = chromatic_vector(direction: 'vi').render

    assert_equal expected, actual
  end

  def test_chromatic_vector_renders_the_expected_vector_2
    expected = { normalized: [ 2, 6, 9 ], root: 2, quality: 'major', name: [ 'II' ] }
    actual = chromatic_vector(direction: 'II').render

    assert_equal expected, actual
  end

  def test_chromatic_vector_renders_the_expected_vector_3
    expected = { normalized: [ 3, 7, 11 ], root: 3, quality: 'augmented', name: [ 'bIII+' ] }
    actual = chromatic_vector(direction: 'bIII+').render

    assert_equal expected, actual
  end

  def test_chromatic_vector_renders_the_expected_vector_4
    expected = { normalized: [ 7, 11, 14 ], root: 7, quality: 'major', name: [ 'V' ] }
    actual = chromatic_vector(direction: 'V').render

    assert_equal expected, actual
  end

  def test_adding_two_vectors_works
    first_vector = ChromaticVector.new(direction: 'V')
    second_vector = ChromaticVector.new(direction: 'ii')

    # expected = { normalized: [ 9, 13, 14 ], root: 9, quality: 'minor', name: [ 'V', 'ii' ] }
    expected = { normalized: [ 9, 12, 16 ], root: 9, quality: 'minor', name: [ 'vi' ] }
    actual = (first_vector + second_vector).render

    assert_equal expected, actual
  end
end

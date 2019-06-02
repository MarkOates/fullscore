require_relative '../lib/vector'
require_relative 'test_helper'

class ChromaticVectorTest < Minitest::Test
  def chromatic_vector(direction:)
    @chromatic_vector ||= ChromaticVector.new(direction: direction)
  end

  def test_chromatic_vector_doenst_blow_up
    chromatic_vector(direction: 'i').render
  end

  def test_chromatic_vector_renders_the_expected_vector
    expected = {
      result: [ 9, 0+12, 4+12 ],
    }
    chromatic_vector(direction: 'vi').render
  end

  def test_chromatic_vector_renders_the_expected_vector
    expected = {
      result: [ 9, 0+12, 4+12 ],
    }
    chromatic_vector(direction: 'vi').render
  end
end

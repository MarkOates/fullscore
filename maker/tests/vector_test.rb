require_relative '../lib/vector'
require_relative 'test_helper'

class ChromaticVectorTest < Minitest::Test
  def chromatic_vector
    @chromatic_vector ||= ChromaticVector.new(
      start_chord_quality: nil,
      direction_root:      nil,
      direction_quality:   nil,
    )
  end

  def test_chromatic_vector_doenst_blow_up
    chromatic_vector.render
  end
end

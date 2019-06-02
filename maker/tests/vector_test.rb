require_relative '../lib/vector'
require_relative 'test_helper'

class VectorTest < Minitest::Test
  def test_vector_doenst_blow_up
    vector = Vector.new(
      start_chord_quality: nil,
      direction:           nil,
      direction_quality:   nil,
    )
  end
end

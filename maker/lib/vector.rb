class Vector
  attr_reader :start_chord_quality, :direction, :direction_quality

  def initialize(start_chord_quality:, direction:, direction_quality:)
    @start_chord_quality = start_chord_quality
    @direction = direction
    @direction_quality = direction_quality
  end
end

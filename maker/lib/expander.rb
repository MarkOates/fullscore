class Expander
  attr_reader :notes

  def initialize(notes)
    @notes = notes
  end

  def expand
    [0, 7, 16]
  end

  def extrapolate(depth)
    [0, 4, 7, 0+12, 4+12, 7+12, 0+24, 4+24, 7+24]
  end

  def extrapolate_to(max_note)
    result = []
    max_reached_note = notes.max
    index = 0

    while max_reached_note < max_note
      octave = index / notes.size
      result << notes.at(index % notes.size) + 12 * octave

      index = index + 1
      max_reached_note = result.max
    end

    return result
  end
end

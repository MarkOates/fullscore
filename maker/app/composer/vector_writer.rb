require_relative '../../lib/chromatic/vector'

class VectorWriter
  attr_accessor :root

  def initialize
    root = 0
  end

  def v(direction)
    ChromaticVector.new(direction: direction)
  end

  def progression_2
    [
      v('I'),
      v('bV'),
      v('I'),
      v('bV'),
    ].map(&:render)
  end

  def progression
    [
      v('V') + v('iii') + v('bV'),
      v('V') + v('iii'),
      v('V') + v('iii') + v('bV'),
      v('V') + v('iii'),
      v('V') + v('vi'),
      v('V') + v('ii'),
      v('V') + v('V'),
      v('V'),
      v('I'),
    ].map(&:render)
  end

  def transpose_up_octave(notes:, num_octaves: 1)
    notes.map { |note| note + 12*num_octaves }
  end

  def transpose_down_octave(notes:, num_octaves: 1)
    notes.map { |note| note - 12*num_octaves }
  end

  def normalize_within_octave(notes:, uniq: true)
    result = notes.map { |note| note % 12 }
    result.uniq! if uniq == true
    result
  end

  def project_many_octaves(notes:)
    source_notes = normalize_within_octave(notes: notes, uniq: true)
    source_notes = transpose_down_octave(notes: source_notes, num_octaves: 2)
    5.times.map do |i|
      transpose_up_octave(notes: source_notes, num_octaves: i)
    end.flatten
  end

  def floodfill(noteses:)
    noteses.map do |notes|
      project_many_octaves(notes: notes)
    end
  end

  def composition
    {
      staves: [
        {
          instrument: { name: { full: 'Piano', abbreviated: 'Pf', } },
          notes: progression.map { |vector| vector[:normalized] },
        },
        {
          instrument: { clef: 'bass', name: { full: 'Bass', } },
          notes: progression.map { |vector| vector[:root] },
        },
        {
          instrument: { clef: 'bass', name: { full: 'Floodfill', } },
          notes: floodfill(noteses: progression.map { |vector| vector[:normalized] }),
        }
      ]
    }
  end
end

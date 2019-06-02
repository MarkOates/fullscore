require_relative '../../lib/chromatic/vector'

class VectorWriter
  attr_accessor :root

  def initialize
    root = 0
  end

  def v(direction, root: root)
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
        }
      ]
    }
  end
end

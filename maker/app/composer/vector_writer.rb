require_relative '../../lib/chromatic/vector'

class VectorWriter
  attr_accessor :root

  def initialize
    root = 0
  end

  def v(direction, root: root)
    ChromaticVector.new(direction: direction).render
  end

  def progression
    [
      v('V') + v('V'),
      v('V'),
      v('I'),
    ]
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

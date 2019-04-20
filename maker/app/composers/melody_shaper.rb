require_relative '../composer_base'

class Flute
  def self.as_json
    {
      name: {
        full: 'Flute',
        abbreviated: 'Fl.',
      },
    }
  end
end

class Note
  attr_reader :duration, :pitches

  def initialize(duration:, pitches:)
    @duration = duration
    @pitches = pitches
  end

  def /(divisor)
    pitches / divisor
  end

  def %(divisor)
    pitches % divisor
  end
end

class MelodyShaper < ComposerBase
  def rest
    'r'
  end

  def prefix
  end

  def set_duration_to_half_notes
  end

  def staves
    base = [0, Note.new(duration: 2, pitches: 2), 7]

    [
      {
        instrument: Flute.as_json,
        notes: base,
      }
    ]
  end
end

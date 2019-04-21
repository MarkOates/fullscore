require_relative '../composer_base'
require_relative '../../lib/chromatic/chord_notes'

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

class PathFollower < ComposerBase
  def n(pitches, duration, dots = 0)
    Note.new(duration: duration, duration_dots: 0, pitches: pitches)
  end

  def circle_of_5ths
    Chromatic::ChordNotes.notes_for('circle_of_5ths')
  end

  def transpose_up_octave(notes:)
    notes.map { |note| note + 12 }
  end

  def transpose_down_octave(notes:)
    notes.map { |note| note - 12 }
  end

  def normalize_within_octave(notes:)
    notes.map { |note| note % 12 }.uniq
  end

  def staves
    [
      {
        instrument: Flute.as_json,
        notes: circle_of_5ths,
      }
    ]
  end
end

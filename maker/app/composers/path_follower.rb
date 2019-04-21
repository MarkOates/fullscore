require_relative '../composer_base'
require_relative '../../lib/chromatic/chord_notes'

class PathFollower < ComposerBase
  def n(pitches, duration, dots = 0)
    Note.new(duration: duration, duration_dots: 0, pitches: pitches)
  end

  def circle_of_5ths
    Chromatic::ChordNotes.notes_for('circle_of_5ths')
  end

  def perfect_major_circle_of_5ths
    Chromatic::ChordNotes.new.perfect_major_circle_of_5ths(iterations: 4)
  end

  def transpose_up_octave(notes:, num_octaves: 1)
    notes.map { |note| note + 12*num_octaves }
  end

  def transpose_down_octave(notes:, num_octaves: 1)
    notes.map { |note| note - 12*num_octaves }
  end

  def normalize_within_octave(notes:)
    notes.map { |note| note % 12 }.uniq
  end

  def project_many_octaves(notes:)
    source_notes = normalize_within_octave(notes: notes)
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

  def staves
    [
      {
        notes: floodfill(noteses: perfect_major_circle_of_5ths.reverse),
      }
    ]
  end
end

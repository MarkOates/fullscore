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

  def resolve_pitch(chord:, note:) # has preference for
    sort_hash = chord.sort.group_by { |chord_note| chord_note <=> note }

    # preference: matching, lower, upper
    sort_hash[0]&.first || sort_hash[-1]&.last || sort_hash[1]&.first # => 8
  end

  class UnresolvableMelody < StandardError; end

  def resolve_melody(progression:, destination:)
    ## validate that destination is in the final chord of the progression,
    ## otherwise it is an invalid resolver

    unless progression&.last&.include?(destination)
      error_message = "The destinaion note #{destination} must be present in the " \
        "final chord of the progression #{progression}"
      raise UnresolvableMelody.new(error_message)
    end
  end

  def staves
    progression = perfect_major_circle_of_5ths.reverse
    root_notes = progression.map { |note| note.first }
    top_notes = normalize_within_octave(notes: progression.map { |note| note.sample })

    [
      {
        instrument: { name: { full: 'Extracted Melody' }, },
        notes: top_notes,
      },
      {
        notes: floodfill(noteses: progression),
      },
      {
        instrument: { name: { full: 'Root Notes' }, clef: 'bass' },
        notes: transpose_down_octave(notes: normalize_within_octave(notes: root_notes)),
      }
    ]
  end
end

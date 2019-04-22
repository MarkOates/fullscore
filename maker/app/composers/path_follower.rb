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

  def resolve_pitch(chord:, note:, preference: [:matching, :lower, :upper]) # has preference for
    sort_hash = chord.sort.group_by { |chord_note| chord_note <=> note }

    case preference
    when [:matching, :lower, :upper]
      sort_hash[0]&.first || sort_hash[-1]&.last || sort_hash[1]&.first
    when [:matching, :upper, :lower]
      sort_hash[0]&.first || sort_hash[1]&.first || sort_hash[-1]&.last
    end
  end

  def middle_note(notes:, offset: 0)
    notes[notes.size / 2 + offset]
  end

  class UnresolvableMelody < StandardError; end

  def resolve_melody(progression:, start_note:)
    ## validate that start_note is in the first chord of the progression,
    ## otherwise it is an invalid resolver

    unless progression&.first&.include?(start_note)
      error_message = "The start_note note #{start_note} must be present in the " \
        "first chord of the progression #{progression}"
      raise UnresolvableMelody.new(error_message)
    end

    current_melody_note = start_note
    progression.each.map do |chord|
      resolved_pitch = resolve_pitch(chord: chord, note: current_melody_note)
      current_melody_note = resolved_pitch
    end
  end

  def staves
    progression = perfect_major_circle_of_5ths.reverse
    root_notes = progression.map { |note| note.first }
    top_notes = normalize_within_octave(notes: progression.map { |note| note.last })
    sampled_notes = normalize_within_octave(notes: progression.map { |note| note.sample })
    fill = floodfill(noteses: progression)

    calculated_melody_1 = resolve_melody(progression: fill, start_note: middle_note(notes: fill.first))
    calculated_melody_2 = resolve_melody(progression: fill, start_note: middle_note(notes: fill.first, offset: 1))

    [
      {
        instrument: { name: { full: "Resolve Melody 1" }, },
        notes: transpose_up_octave(notes: calculated_melody_1),
      },
      {
        instrument: { name: { full: "Resolve Melody 2" }, },
        notes: transpose_up_octave(notes: calculated_melody_2),
      },
      {
        instrument: { name: { full: 'Top Notes' }, },
        notes: top_notes,
      },
      {
        instrument: { name: { full: 'Random'}, },
        notes: sampled_notes,
      },
      {
        instrument: { name: { full: 'Floodfill'}, },
        notes: fill,
      },
      {
        instrument: { name: { full: 'Root Notes' }, clef: 'bass' },
        notes: transpose_down_octave(notes: normalize_within_octave(notes: root_notes)),
      }
    ]
  end
end

require_relative '../composer_base'
require_relative '../../lib/chromatic/chord_notes'
require_relative '../../lib/chromatic/lily_converter'

class PathFollower < ComposerBase
  def n(pitches, duration, dots = 0)
    Note.new(duration: duration, duration_dots: 0, pitches: pitches)
  end

  def circle_of_5ths
    Chromatic::ChordNotes.notes_for('circle_of_5ths')
  end

  def perfect_major_circle_of_5ths
    Chromatic::ChordNotes.new.perfect_major_circle_of_5ths(iterations: 8)
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

  def resolve_pitch(chord:, note:, preference: [:matching, :downward, :upward])
    sort_hash = chord.sort.group_by { |chord_note| chord_note <=> note }

    case preference
    when [:matching, :downward, :upward]
      sort_hash[0]&.first || sort_hash[-1]&.last || sort_hash[1]&.first
    when [:matching, :upward, :downward]
      sort_hash[0]&.first || sort_hash[1]&.first || sort_hash[-1]&.last
    end
  end

  def middle_note(notes:, offset: 0)
    notes[notes.size / 2 + offset]
  end

  class UnresolvableMelody < StandardError; end

  def resolve_melody(progression:, start_note:, preference: [:matching, :downward, :upward])
    ## validate that start_note is in the first chord of the progression,
    ## otherwise it is an invalid resolver

    unless progression&.first&.include?(start_note)
      error_message = "The start_note note #{start_note} must be present in the " \
        "first chord of the progression #{progression}"
      raise UnresolvableMelody.new(error_message)
    end

    current_melody_note = start_note
    progression.each.map do |chord|
      resolved_pitch = resolve_pitch(chord: chord, note: current_melody_note, preference: preference)
      current_melody_note = resolved_pitch
    end
  end

  def reverse_resolve_melody(progression:, end_note:)
    progression.reverse

    preference = [:matching, :upward, :downward]
    result_melody = resolve_melody(progression: progression.reverse, start_note: end_note, preference: preference)
    result_melody.reverse
  end

  def staves
    progression = Chromatic::ChordNotes.progression(['I', 'vi', 'ii', 'V', 'I', 'vi', 'ii', 'V', 'I'])
    root_notes = progression.map { |note| note.first }
    top_notes = normalize_within_octave(notes: progression.map { |note| note.last }, uniq: false)
    sampled_notes = normalize_within_octave(notes: progression.map { |note| note.sample }, uniq: false)
    fill = floodfill(noteses: progression)

    resolve_forward_1 = resolve_melody(progression: fill, start_note: middle_note(notes: fill.first))
    resolve_forward_2 = resolve_melody(progression: fill, start_note: middle_note(notes: fill.first, offset: 1))
    resolve_forward_3 = resolve_melody(progression: fill, start_note: middle_note(notes: fill.first, offset: 2))

    reverse_resolve_end_note = 0
    reverse_resolve = reverse_resolve_melody(progression: fill, end_note: reverse_resolve_end_note)
    reverse_resolve_end_note_ly = Chromatic::LilyConverter.new(notes: [reverse_resolve_end_note]).convert

    [
      {
        instrument: { name: { full: "Resolve Forward #3" }, },
        notes: transpose_up_octave(notes: resolve_forward_3),
      },
      {
        instrument: { name: { full: "Resolve Forward #2" }, },
        notes: transpose_up_octave(notes: resolve_forward_2),
      },
      {
        instrument: { name: { full: "Resolve Forward #1" }, },
        notes: transpose_up_octave(notes: resolve_forward_1),
      },
      {
        instrument: { name: { full: "Reverse (End on #{reverse_resolve_end_note_ly})" }, },
        notes: transpose_up_octave(notes: reverse_resolve),
      },
      {
        instrument: { name: { full: 'Floodfill'}, },
        notes: fill,
      },
      {
        instrument: { name: { full: 'Root Notes' }, clef: 'bass' },
        notes: transpose_down_octave(notes: normalize_within_octave(notes: root_notes, uniq: false)),
      }
    ]
  end
end

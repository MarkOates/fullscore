require_relative '../composers/base'
require_relative 'path_follower'

class Note
  attr_accessor :duration, :duration_dots, :pitches

  def self.eighth_rest
    Note.new(duration: 8, pitches: 'r')
  end

  def initialize(duration: 4, duration_dots: 0, pitches:)
    @duration = duration
    @duration_dots = duration_dots
    @pitches = pitches
  end

  def /(divisor)
    pitches / divisor
  end

  def %(divisor)
    pitches % divisor
  end
end

class Texturer < Composer::Base
  def eighth_every_strong_beat(notes:)
    result_notes = []
    notes.each do |note|
      result_notes << Note.new(pitches: note, duration: 8)
      result_notes << Note.new(pitches: 'r', duration: 8)
      #result_notes << Note.new(pitches: 'r', duration: 4)
    end
    result_notes
  end

  def interject(notes:, interjection:)
    return notes if notes.empty?
    return notes if notes.size == 1

    result = []
    result << notes[0]

    for i in 1...notes.size
      left_note = notes[i-1]
      right_note = notes[i]

      result << Note.new(duration: 16, pitches: left_note.pitches + 1)
      result << Note.new(duration: 16, pitches: right_note.pitches - 1)
      result << notes[i]
    end

    result
  end

  def join_with_pickups(notes:)
    result_notes = []
    notes.each do |note|
      result_notes << Note.new(pitches: note, duration: 8)
      #result_notes << Note.new(pitches: note, duration: 4, duration_dots: 1)
    end
    result_notes = interject(notes: result_notes, interjection: Note.new(pitches: 'r', duration: 8))
    result_notes.last.duration = 2
    result_notes.last.duration_dots = 0
    result_notes
  end

  def texturize(notes:)
    return join_with_pickups(notes: notes)

    #result_notes = []
    #notes.each do |note|
      #result_notes << Note.new(pitches: note, duration: 4, duration_dots: 1)
      #result_notes << Note.new(pitches: note-1, duration: 8)
    #end
    #result_notes
  end

  def normalize_chord_within_octave(notes:, uniq: true)
    notes.map do |note_set|
      note_set.map { |note| note % 12 }
    end
  end

  def composition
    path_follower_composition = PathFollower.new.composition

    #return path_follower_composition
    progression = path_follower_composition[:staves].find do |staff|
      staff[:instrument][:name][:full] == 'Progression'
    end
    root_notes = path_follower_composition[:staves].find do |staff|
      staff[:instrument][:name][:full] == 'Root Notes'
    end

    melody = texturize(notes: path_follower_composition[:staves].first[:notes])

    result = {
      staves: [
        {
          instrument: { name: { full: 'Flute', abbreviated: 'Fl.', } },
          notes: melody,
        },
        {
          instrument: { name: { full: 'Piano RH', abbreviated: 'Pf.', } },
          notes: eighth_every_strong_beat(notes: normalize_chord_within_octave(notes: progression[:notes])),
        },
        {
          instrument: { name: { full: 'Piano LH', abbreviated: 'Pf.', }, clef: 'bass' },
          notes: eighth_every_strong_beat(notes: root_notes[:notes]),
        },
      ],
    }
  end
end

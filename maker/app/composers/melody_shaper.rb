require_relative '../composer_base'
require 'ostruct'

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

class Piano
  def self.rh_as_json
    {
      name: {
        full: 'Piano (R.H.)',
        abbreviated: 'Pf (R.H.)',
      },
    }
  end

  def self.lh_as_json
    {
      name: {
        full: 'Piano (L.H.)',
        abbreviated: 'Pf (L.H.)',
      },
      clef: 'bass',
    }
  end
end

class DurationSubtractor
  class UnknownSubtraction < StandardError; end

  attr_reader :duration1, :duration2

  def initialize(duration1:, duration2:)
    @duration1 = duration1
    @duration2 = duration2
  end

  def result
    pair = [duration1, duration2]
    case pair
    when [1, 2]
      2
    when [2, 8]
      OpenStruct.new(duration: 4, duration_dots: 1)
    else
      raise UnknownSubtraction.new("Unknown subtraction for pair #{pair}")
    end
  end
end

class Note
  attr_accessor :duration, :duration_dots, :pitches

  def initialize(duration:, duration_dots: 0, pitches:)
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

class MelodyShaper < ComposerBase
  def n(pitches, duration)
    Note.new(duration: duration, pitches: pitches)
  end

  def jumper
    [-12, -5, 0, 2, 7, 12, 14]
  end

  def join_with_jumper_notes(notes:)
    notes.each.map do |fragment|
      p = pitch(fragment)
      #d = duration(fragment)
      #dd = duration_dots(fragment)
      first_jumper_note = jumper[jumper.find_index(p) - 2]
      second_jumper_note = jumper[jumper.find_index(p) - 1]

      #jumper_notes = [jump
      [
        Note.new(pitches: first_jumper_note, duration: 16),
        Note.new(pitches: second_jumper_note, duration: 16),
        Note.new(pitches: p, duration: 4, duration_dots: 1),
      ]
    end.flatten
  end

  def subtract_duration(duration1:, duration2:)
    DurationSubtractor.new(duration1: duration1, duration2: duration2).result
  end

  def add_duration(duration1:, duration2:)
    pair = [duration1, duration2]
    case pair
    when [16, 16]
      8
    else
      raise UnknownSubtraction.new("Unknown subtraction for pair #{pair}")
    end
  end

  def pitch(fragment)
    fragment.respond_to?(:pitches) ? fragment.pitches : fragment
  end

  def duration(fragment)
    fragment.respond_to?(:duration) ? fragment.duration : 4
  end

  def duration_dots(fragment)
    fragment.respond_to?(:duration_dots) ? fragment.duration_dots : 0
  end

  def set_to_half_notes(notes:)
    notes.each.map do |fragment|
      p = pitch(fragment)
      Note.new(pitches: p, duration: 2)
    end
  end

  def melody
    base = [0, 2, 7]
    base = set_to_half_notes(notes: base)
    shorter_duration = subtract_duration(duration1: base[0].duration, duration2: 8)
    base[0].duration = shorter_duration.duration
    base[0].duration_dots = shorter_duration.duration_dots

    melody = [base[0]].concat(join_with_jumper_notes(notes: base.drop(1)))
    melody.last.duration = 2
    melody.last.duration_dots = 0
    melody << Note.new(pitches: 'r', duration: 4)
    melody << Note.new(pitches: 12, duration: 8)
    melody << Note.new(pitches: 11, duration: 8)

    melody
  end

  def flute
    [
      {
        instrument: Flute.as_json,
        notes: melody,
      }
    ]
  end

  def piano_harmonization
    [
      {
        instrument: Piano.rh_as_json,
        notes: [Note.new(duration: 1, pitches: 'R')] * 2,
      },
      {
        instrument: Piano.lh_as_json,
        notes: [Note.new(duration: 1, pitches: 'R')] * 2,
      }
    ]
  end

  def staves
    flute.concat(piano_harmonization)
  end
end

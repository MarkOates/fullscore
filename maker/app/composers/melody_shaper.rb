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
  attr_reader :duration, :duration_dots, :pitches

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
      first_jumper_note = jumper[jumper.find_index(p) - 2]
      second_jumper_note = jumper[jumper.find_index(p) - 1]

      #jumper_notes = [jump
      [
        Note.new(pitches: first_jumper_note, duration: 16),
        Note.new(pitches: second_jumper_note, duration: 16),
        Note.new(pitches: p, duration: 2),
      ]
    end.flatten
  end

  def subtract_duration(duration1:, duration2:)
    DurationSubtractor.new(duration1: duration1, duration2: duration2).result
  end

  def pitch(fragment)
    fragment.respond_to?(:pitches) ? fragment.pitches : fragment
  end

  def duration(fragment)
    fragment.respond_to?(:duration) ? convert_duration(duration: fragment.duration) : 4
  end

  def set_to_half_notes(notes:)
    notes.each.map do |fragment|
      p = pitch(fragment)
      Note.new(pitches: p, duration: 2)
    end
  end

  def staves
    base = [0, 2, 7]
    base = set_to_half_notes(notes: base)
    base = [base[0]].concat(join_with_jumper_notes(notes: base.drop(1)))

    [
      {
        instrument: Flute.as_json,
        notes: base,
      }
    ]
  end
end

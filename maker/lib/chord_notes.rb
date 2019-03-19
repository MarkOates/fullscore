class Chromatisizer
  attr_reader :notes

  def initialize(notes)
    @notes = notes
  end

  def chromatics
    notes.map { |note| chromatic(note) }
  end

  private

  def chromatic(diatonic)
    case diatonic
    when 1
      0
    when 2
      2
    when 3
      4
    when 4
      5
    when 5
      7
    when 6
      9
    when 7
      11
    when 8
      13
    when 9
      15
    else
      throw StandardError.new("unknown diatonic value")
    end
  end
end

class ChordNotes
  def self.notes_for(progression)
    chords = ChordNotes.new.chords(progression)
    self.progression(chords)
  end

  def self.progression(chords)
    chords.map { |chord| ChordNotes.new.chord_notes(chord) }
  end

  def chords(progression)
    case progression
    when 'circle_of_5ths'
      ['I', 'IV', 'viio', 'iii', 'vi', 'ii', 'V']
    when 'ascending_bass'
      ['vi', 'V6', 'I']
    end
  end

  def invert(chord)
    notes = chord_notes(chord).rotate
    notes[-1] = notes.last + 7
    notes
  end

  def chord_notes(chord)
    case chord
    when 'I'
      [1, 3, 5]
    when 'iii'
      [3, 5, 7]
    when 'ii'
      [2, 4, 6]
    when 'IV'
      [4, 6, 8]
    when 'V'
      [5, 7, 9]
    when 'V6'
      [7, 9, 12]
    when 'vi'
      [6, 8, 10]
    when 'viio'
      [7, 9, 11]
    end
  end
end

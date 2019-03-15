I = 'I'
ii = 'ii'
IV = 'IV'
V = 'V'
V6 = 'V6'
vi = 'vi'

class ChordNotes
  def self.notes_for(progression:)
    chords = ChordNotes.new.chords(progression)
    self.progression(chords)
  end

  def self.progression(chords)
    chords.map { |chord| ChordNotes.new.chord_notes(chord) }
  end

  def chords(progression)
    case progression
    when 'ascending_bass'
      ['vi', V6, I]
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
    when 'ii'
      [2, 4, 6]
    when 'IV'
      [4, 6, 8]
    when 'V'
      [5, 7, 9]
    when 'V6'
      [7, 9, 5+7]
    when 'vi'
      [6, 8, 10]
    end
  end
end

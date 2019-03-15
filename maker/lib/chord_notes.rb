I = 'I'
IV = 'IV'
V = 'V'
vi = 'vi'

class ChordNotes
  attr_reader :chord

  def self.progression(chords)
    chords.map { |chord| ChordNotes.new(chord).notes }
  end

  def initialize(chord)
    @chord = chord
  end

  def notes
    case chord
    when 'I'
      [1, 3, 5]
    when 'IV'
      [4, 6, 8]
    when 'V'
      [5, 7, 9]
    when 'vi'
      [6, 8, 10]
    end
  end
end

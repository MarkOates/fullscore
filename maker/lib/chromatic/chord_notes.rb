module Chromatic
  class ChordNotes
    class UnparsableChordNote < StandardError; end

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
        ['I', 'IV', 'viio', 'iii', 'vi', 'ii', 'V', 'I']
      when 'ascending_bass'
        ['vi', 'V6', 'I']
      end
    end

    def perfect_major_circle_of_5ths(iterations: 3)
      major_chord = major_projection(root: 0)
      iterations.times.map do |i|
        major_chord.map { |note| note + 7 * i }
      end
    end

    def note_name(notes)
      notes.map do |note|
        case note
        when 0
          'c'
        when 2
          'd'
        when 4
          'e'
        when 5
          'f'
        when 7
          'g'
        when 9
          'a'
        when 11
          'b'
        end
      end
    end

    def invert(chord)
      notes = chord_notes(chord).rotate
      notes[-1] = notes.last + 12
      notes
    end

    def chord_notes(chord)
      case chord
      when 'I'
        major_projection(root: 0)
      when 'V'
        major_projection(root: 7)
      when 'ii'
        minor_projection(root: 2)
      when 'iii'
        minor_projection(root: 4)
      when 'IV'
        major_projection(root: 5)
      when 'vi'
        minor_projection(root: 9)
      when 'V6'
        invert('V')
      #when 'V6'
        #[7, 9, 12]
      when 'viio'
        diminished_projection(root: 11)
      else
        raise UnparsableChordNote.new("Cannot parse chord note \"#{chord}\"")
      end
    end

    private

    def major_projection(root:)
      [root, root+4, root+7]
    end

    def minor_projection(root:)
      [root, root+3, root+7]
    end

    def diminished_projection(root:)
      [root, root+3, root+6]
    end
  end
end

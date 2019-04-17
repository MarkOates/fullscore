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
        major_projection(root: 0)
      when 'V'
        major_projection(root: 7)
      when 'ii'
        minor_projection(root: 2)
      when 'iii'
        minor_projection(root: 4)
      when 'IV'
        minor_projection(root: 5)
      when 'vi'
        minor_projection(root: 9)
      #when 'V6'
        #[7, 9, 12]
      #when 'viio'
        #[7, 9, 11]
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
  end
end

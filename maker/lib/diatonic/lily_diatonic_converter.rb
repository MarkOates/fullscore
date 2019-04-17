class Diatonic
  class LilyDiatonicConverter
    class UnknownNote < StandardError; end
    class UnknownFramentType < StandardError; end

    SHARP = 'is'
    FLAT = 'es'

    attr_reader :notes

    def initialize(notes:)
      @notes = notes
    end

    def convert
      notes.map do |fragment|
        if fragment.is_a?(Integer)
          convert_note(note: fragment)
        elsif fragment.is_a?(Array)
          convert_chord(chord: fragment)
        else
          raise UnknownFramentType.new("Fragment type #{fragment.class}")
        end
      end.join(' ')
    end

    private

    def convert_chord(chord:)
      lily_notes = chord.map do |note|
        convert_note(note: note)
      end.join(' ')

      "<#{lily_notes}>"
    end

    def convert_note(note:)
      convert_note_name(note: note) + convert_octaves(note: note)
    end

    def convert_octaves(note:)
      octaves = ((note-1) / 7 + 1)
      if octaves > 0
        "'" * octaves
      elsif octaves < 0
        "," * (-octaves)
      end
    end

    def convert_note_name(note:)
      relative_to_1 = ((note-1) % 7) + 1

      case relative_to_1
      when 1
        "c"
      when 2
        "d"
      when 3
        "e"
      when 4
        "f"
      when 5
        "g"
      when 6
        "a"
      when 7
        "b"
      else
        raise UnknownNote.new("Note number #{relative_to_0} is not parsable")
      end
    end
  end
end

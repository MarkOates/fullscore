module Chromatic
  class LilyConverter
    class UnknownNote < StandardError; end
    class UnknownFramentType < StandardError; end
    class UnknownStringFragmentType < StandardError; end

    SHARP = 'is'
    FLAT = 'es'

    attr_reader :notes

    def initialize(notes:)
      @notes = notes
    end

    def convert
      notes.map do |fragment|
        fragment_component = fragment
        fragment_duration = fragment.respond_to?(:duration) ? convert_duration(duration: fragment.duration) : 4

        if fragment_component.is_a?(Integer)
          convert_note(note: fragment)
        elsif fragment_component.is_a?(Array)
          convert_chord(chord: fragment)
        elsif fragment_component.is_a?(String)
          if fragment_component == 'r'
            'r'
          else
            raise UnknownStringFragmentType.new("String fragment \"#{fragment}\" not known")
          end
        else
          raise UnknownFramentType.new("Fragment type #{fragment.class}")
        end + fragment_duration.to_s
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

    def convert_duration(duration:)
      return 8.to_s
    end

    def convert_octaves(note:)
      octaves = (note / 12 + 1)
      if octaves > 0
        "'" * octaves
      elsif octaves < 0
        "," * (-octaves)
      else
        ''
      end
    end

    def convert_note_name(note:)
      relative_to_0 = note % 12

      case relative_to_0
      when 0
        "c"
      when 2
        "d"
      when 4
        "e"
      when 5
        "f"
      when 7
        "g"
      when 8
        "a#{FLAT}"
      when 9
        "a"
      when 11
        "b"
      else
        raise UnknownNote.new("Note number #{relative_to_0} is not parsable")
      end
    end
  end
end

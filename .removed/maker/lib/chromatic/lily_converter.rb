class Array
  def self.wrap(object)
    if object.nil?
      []
    elsif object.respond_to?(:to_ary)
      object.to_ary || [object]
    else
      [object]
    end
  end
end

module Chromatic
  class LilyConverter
    class UnknownNote < StandardError; end
    class UnknownFramentType < StandardError; end
    class UnknownStringFragmentType < StandardError; end
    class UnrecognizedArticulation < StandardError; end
    class UnallowedArticulationType < StandardError; end

    SHARP = 'is'
    FLAT = 'es'

    ALLOWED_ARTICULATIONS = [
      'staccato',
      'accent',
      'marcato',
    ]

    attr_reader :notes

    def initialize(notes:)
      @notes = notes
    end

    def convert
      notes.map do |fragment|
        fragment_component = fragment.respond_to?(:pitches) ? fragment.pitches : fragment
        fragment_duration = get_fragment_duration(fragment: fragment)
        fragment_articulations = get_fragment_articulation(fragment: fragment)

        if fragment_component.is_a?(Integer)
          convert_note(note: fragment_component)
        elsif fragment_component.is_a?(Array)
          convert_chord(chord: fragment_component)
        elsif fragment_component.is_a?(String)
          if fragment_component.downcase == 'r'
            fragment_component
          else
            raise UnknownStringFragmentType.new("String fragment \"#{fragment_component}\" not known")
          end
        else
          raise UnknownFramentType.new("Fragment type #{fragment.class}")
        end + fragment_duration.to_s + fragment_articulations
      end.join(' ')
    end

    private

    def get_fragment_articulation(fragment:)
      fragment_articulation = fragment.respond_to?(:articulations) ? fragment.articulations : nil

      return '' if fragment_articulation == nil || fragment_articulation.empty?

      fragment_articulations = Array.wrap(fragment_articulation)

      '\\' + fragment_articulations.map { |articulation| filter_individual_articulation(articulation: articulation) }.join('\\')
    end

    def filter_individual_articulation(articulation:)
      raise UnallowedArticulationType.new("Articulation type not allowed: type: \"#{articulation.class}\", to_s: \"#{articulation}\"") unless articulation.is_a?(String)
      raise UnrecognizedArticulation.new("Unknown articulation called \"#{articulation}\"") unless ALLOWED_ARTICULATIONS.include?(articulation)
      articulation
    end

    def get_fragment_duration(fragment:)
      duration = fragment.respond_to?(:duration) ? convert_duration(duration: fragment.duration) : 4
      duration_dots = fragment.respond_to?(:duration_dots) ? fragment.duration_dots : 0

      "#{duration}#{'.' * duration_dots}"
    end

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
      duration
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
      when 1
        "c#{SHARP}"
      when 2
        "d"
      when 3
        "e#{FLAT}"
      when 4
        "e"
      when 5
        "f"
      when 6
        "f#{SHARP}"
      when 7
        "g"
      when 8
        "a#{FLAT}"
      when 9
        "a"
      when 10
        "b#{FLAT}"
      when 11
        "b"
      else
        raise UnknownNote.new("Note number #{relative_to_0} is not parsable")
      end
    end
  end
end

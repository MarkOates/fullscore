class LilyConverter
  class UnknownNote < StandardError; end

  SHARP = 'is'
  FLAT = 'es'

  attr_reader :notes

  def initialize(notes:)
    @notes = notes
  end

  def convert
    notes.map do |note|
      convert_note(note: note)
    end.join(' ')
  end

  private

  def convert_note(note:)
    convert_note_name(note: note) + convert_octaves(note: note)
  end

  def convert_octaves(note:)
    octaves = (note / 12 + 1)
    if octaves > 0
      "'" * octaves
    elsif octaves < 0
      "," * (-octaves)
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

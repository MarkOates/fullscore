class LilyConverter
  class UnknownNote < StandardError; end

  attr_reader :notes

  def initialize(notes:)
    @notes = notes
  end

  def convert
    convert_note(note: notes[0])
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

    case note
    when 0
      "c"
    when 2
      "c"
    when 4
      "c"
    when 5
      "c"
    when 7
      "c"
    when 9
      "c"
    when 11
      "c"
    else
      raise UnknownNote, "note"
    end
  end
end

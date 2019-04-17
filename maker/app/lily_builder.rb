TEMPLATE_FILE = 'templates/lilypond-template.ly'
OUTPUT_FILE = 'output-lily.ly'

require_relative '../lib/lily_converter'
require_relative '../lib/voicer'


# todo, ellaborate this class
class NoteBuilder
  def ly_notes
    notes = [0, [2, 4, 5], 8, 11, 4]
    #notes = Voicer.new(notes).high_range

    score = [
      staff_1: {
        notes: [0, [2, 4, 5], 8, 11, 4],
      },
      staff_2: {
        notes: [2, 8, 11, 4],
      },
    ]

    LilyConverter.new(notes: notes).convert
    #"<c' d' e' f'> <c' e' a>"
  end
end

ly_notes_to_write = NoteBuilder.new.ly_notes

template = IO.read(TEMPLATE_FILE)
template.sub!('%%%INSERT_NOTE_CONTENTS_HERE%%%', ly_notes_to_write)

File.open(OUTPUT_FILE, 'w') do |f|
  f.write(template)
end

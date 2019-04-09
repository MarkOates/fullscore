TEMPLATE_FILE = 'templates/lilypond-template.ly'

# todo, ellaborate this class
class NoteBuilder
  def ly_notes
    "<c' d' e' f'> <c' e' a>"
  end
end

ly_notes_to_write = NoteBuilder.new.ly_notes

template = IO.read(TEMPLATE_FILE)
template.sub!('%%%INSERT_NOTE_CONTENTS_HERE%%%', ly_notes_to_write)

File.write('../../output-lily.ly', template)

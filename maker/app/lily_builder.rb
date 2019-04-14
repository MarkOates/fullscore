TEMPLATE_FILE = 'templates/lilypond-template.ly'

require_relative '../../maker/lib/lily_converter'
require_relative '../../maker/lib/voicer'

# todo, ellaborate this class
class NoteBuilder
  def ly_notes
    notes = [0, 2, 4, 5, 8, 11, 0]
    notes = Voicer.new(notes).high_range
    LilyConverter.new(notes: notes).convert
    #"<c' d' e' f'> <c' e' a>"
  end
end

ly_notes_to_write = NoteBuilder.new.ly_notes

template = IO.read(TEMPLATE_FILE)
template.sub!('%%%INSERT_NOTE_CONTENTS_HERE%%%', ly_notes_to_write)

File.write('../../output-lily.ly', template)

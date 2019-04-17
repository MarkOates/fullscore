TEMPLATE_FILE = 'templates/lilypond-template.ly'
OUTPUT_FILE = 'output-lily.ly'

require_relative '../lib/chromatic/lily_converter'
require_relative '../lib/template_stuffer'
require_relative '../lib/chromatic/voicer'
require_relative '../lib/chromatic/composer'


composition = Chromatic::Composer.new.composition
#notes = composition[:staves].first[:notes]
#staves_notes = {}

staves_notes = composition[:staves].map do |staff|
  ly_notes_to_write = Chromatic::LilyConverter.new(notes: staff[:notes]).convert
end


#ly_notes_to_write = Chromatic::LilyConverter.new(notes: notes).convert
template_stuffs_to_stuff = TemplateStuffer.stuff(staves_notes: staves_notes)

template = IO.read(TEMPLATE_FILE)
ly_notes_to_write = "c' d''"
template.sub!('%%%INSERT_NOTE_CONTENTS_HERE%%%', ly_notes_to_write)
template.sub!('%%%INSERT_ADDITIONAL_STAVES_HERE%%%', template_stuffs_to_stuff)

File.open(OUTPUT_FILE, 'w') do |f|
  f.write(template)
end

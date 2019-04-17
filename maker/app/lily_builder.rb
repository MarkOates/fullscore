require_relative '../lib/chromatic/lily_converter'
require_relative '../lib/template_stuffer'
require_relative '../lib/chromatic/composer'

class LilyBuilder
  TEMPLATE_FILE = 'templates/lilypond-template.ly'
  OUTPUT_FILE = 'output-lily.ly'

  attr_reader :composer

  def initialize(composer:)
    @composer = composer
  end

  def staves
    @staves ||= composition[:staves]
  end

  def composition
    @composition ||= composer.composition
  end

  def staves_ly_notes
    @staves_ly_notes ||= staves.map do |staff|
      Chromatic::LilyConverter.new(notes: staff[:notes]).convert
    end
  end

  def build
    first_staff_notes_to_write = staves_ly_notes.first
    staves_notes = staves_ly_notes.drop(1)

    template_stuffs_to_stuff = TemplateStuffer.stuff(staves_notes: staves_notes)

    template = IO.read(TEMPLATE_FILE)
    template.sub!('%%%INSERT_NOTE_CONTENTS_HERE%%%', first_staff_notes_to_write)
    template.sub!('%%%INSERT_ADDITIONAL_STAVES_HERE%%%', template_stuffs_to_stuff)

    File.open(OUTPUT_FILE, 'w') do |f|
      f.write(template)
    end
  end
end

LilyBuilder.new(composer: Chromatic::Composer.new).build

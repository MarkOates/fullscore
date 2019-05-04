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

  def build
    template_stuffs_to_stuff = TemplateStuffer.stuff(
      staves_contents: staves_contents,
    )

    template = IO.read(TEMPLATE_FILE)
    template.sub!('%%%INSERT_ADDITIONAL_STAVES_HERE%%%', template_stuffs_to_stuff)

    File.open(OUTPUT_FILE, 'w') { |file| file.write(template) }
  end

  private

  def staves_contents
    @staves_contents ||= staves.map do |staff|
      {
        instrument: staff[:instrument],
        notes: Chromatic::LilyConverter.new(notes: staff[:notes]).convert,
      }
    end
  end

  def staves
    @staves ||= composition[:staves]
  end

  def composition
    @composition ||= composer.composition
  end
end

require_relative 'composer/texturer'

LilyBuilder.new(composer: Texturer.new).build

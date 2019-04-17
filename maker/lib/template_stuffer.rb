class TemplateStuffer
  TEMPLATE_FILENAME = 'lilypond-template.ly'
  STAFF_PARTIAL = <<~CONTENT
    \new Staff
    {
      %%%INSERT_NOTE_CONTENTS_HERE%%%
    }
  CONTENT

  attr_reader :staves, :converter

  def initialize(staves:, converter:)
    @staves = staves
    @converter = converter
  end

  def stuffed
    staves.map do |staff|
      #converter.new(notes: staff[:notes])
      staff_partial(body: staff[:notes])
    end
  end

  private

  def staff_partial(body:)
    STAFF_PARTIAL.gsub('INSERT_NOTE_CONTENTS_HERE', body)
  end
end

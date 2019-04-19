class TemplateStuffer
  STAFF_PARTIAL = <<-CONTENT
    \\new Staff %%%INSERT_THE_WITH_META_INFO_HERE%%%
    {
      %%%INSERT_STAFF_CONTENTS_HERE%%%
    }
  CONTENT

  attr_reader :staff_notes, :instrument_name_full, :instrument_name_abbreviated

  def self.staves_content_temp_default_arg
    [
      {
        instrument: {
          name: {
            full: 'Flute',
            abbreviated: 'Fl.',
          }
        },
        notes: "c' d'' e'",
      },
      {
        notes: "c' d'' e'".split(' ').reverse.join(' '),
      }
    ]
  end

  def self.stuff(staves_notes:, staves_contents: staves_content_temp_default_arg)
    staves_contents.map do |staff_contents|
      TemplateStuffer.new(
        staff_notes: staff_contents[:notes],
        instrument_name_full: staff_contents.dig(:instrument, :name, :full),
        instrument_name_abbreviated: staff_contents.dig(:instrument, :name, :abbreviated),
      ).staff_partial
    end.join("")
  end

  def initialize(staff_notes:, instrument_name_full: nil, instrument_name_abbreviated: nil)
    @staff_notes = staff_notes
    @instrument_name_full = instrument_name_full
    @instrument_name_abbreviated = instrument_name_abbreviated
  end

  def staff_partial
    @staff_partial ||= _staff_partial
  end

  def instrument_name_partial
    @instrument_name_partial ||= _instrument_name_partial
  end

  private

  def _instrument_name_partial
    [
      instrument_name_full ? 'instrumentName = #"TOK"'.gsub('TOK', instrument_name_full) : nil,
      instrument_name_abbreviated ? 'shortInstrumentName = #"TOK"'.gsub('TOK', instrument_name_abbreviated) : nil,
    ].compact.join("\n")
    #shortInstrumentName = #"Vln. "
  end

  def get_instrument_name_fragment
    '\with {
      TOK
    }'.gsub('TOK', instrument_name_partial)
  end

  def get_extra_staff_sections_postfix
    nil
  end

  def staff_contents
    [
      staff_notes,
      get_extra_staff_sections_postfix,
    ].compact.join("\n")
  end

  def _staff_partial
    partial = STAFF_PARTIAL
    partial = partial.gsub('%%%INSERT_STAFF_CONTENTS_HERE%%%', staff_contents)
    partial = partial.gsub('%%%INSERT_THE_WITH_META_INFO_HERE%%%', get_instrument_name_fragment)
    partial
  end
end

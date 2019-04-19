class TemplateStuffer
  STAFF_PARTIAL = <<-CONTENT
    \\new Staff %%%INSERT_THE_WITH_META_INFO_HERE%%%
    {
      %%%INSERT_STAFF_CONTENTS_HERE%%%
    }
  CONTENT
  BLACK_BACKGROUND_PARTIAL = <<-CONTENT
      % This section sets the background to near-black, by drawing a large box
      % over the score.  This technique was taken from:
      % http://lsr.di.unimi.it/LSR/Snippet?id=699
      -\\tweak layer #-1
      -\\markup {
        \\with-dimensions #'(0 . 0) #'(0 . 0)
        % specify color
        \\with-color #(rgb-color 0.05 0.05 0.05)
        % specify size
        \\filled-box #'(-1000 . 1000) #'(-1000 . 4000) #0
      }
  CONTENT

  def self.stuff(staves_contents:, use_black_background: true)
    staves_contents.each_with_index.map do |staff_contents, i|
      TemplateStuffer.new(
        staff_notes: staff_contents[:notes],
        instrument_name_full: staff_contents.dig(:instrument, :name, :full),
        instrument_name_abbreviated: staff_contents.dig(:instrument, :name, :abbreviated),
        clef: staff_contents.dig(:instrument, :clef),
      ).staff_partial(include_black_background_postfix: i == 0 && use_black_background)
    end.join("")
  end

  attr_reader :staff_notes, :instrument_name_full, :instrument_name_abbreviated, :clef

  def initialize(staff_notes:, instrument_name_full: nil, instrument_name_abbreviated: nil, clef: 'treble')
    @clef = clef
    @staff_notes = staff_notes
    @instrument_name_full = instrument_name_full
    @instrument_name_abbreviated = instrument_name_abbreviated
  end

  def staff_partial(include_black_background_postfix:)
    @staff_partial ||= _staff_partial(include_black_background_postfix: include_black_background_postfix)
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

  def clef_definition
    '\clef "TOK"'.gsub('TOK', clef) if clef && clef != 'treble'
  end

  def get_extra_staff_sections_postfix
    BLACK_BACKGROUND_PARTIAL
  end

  def staff_contents(include_black_background_postfix:)
    [
      clef_definition,
      staff_notes,
      include_black_background_postfix ? get_extra_staff_sections_postfix : nil,
    ].compact.join("\n")
  end

  def _staff_partial(include_black_background_postfix:)
    partial = STAFF_PARTIAL
    partial = partial.gsub('%%%INSERT_STAFF_CONTENTS_HERE%%%', staff_contents(include_black_background_postfix: include_black_background_postfix))
    partial = partial.gsub('%%%INSERT_THE_WITH_META_INFO_HERE%%%', get_instrument_name_fragment)
    partial
  end
end

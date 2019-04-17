class TemplateStuffer
  STAFF_PARTIAL = <<-CONTENT
    \\new Staff %%%INSERT_THE_WITH_META_INFO_HERE%%%
    {
      %%%INSERT_NOTE_CONTENTS_HERE%%%
    }
  CONTENT

  attr_reader :staff_notes

  def self.stuff(staves_notes:)
    staves_notes.map do |staff_notes|
      TemplateStuffer.new(staff_notes: staff_notes).staff_partial
    end.join("")
  end

  def initialize(staff_notes:)
    @staff_notes = staff_notes
  end

  def staff_partial
    @staff_partial ||= _staff_partial
  end

  private

  def get_instrument_name_fragment
    '\with {}'
  end

  def _staff_partial
    partial = STAFF_PARTIAL
    partial = partial.gsub('%%%INSERT_NOTE_CONTENTS_HERE%%%', staff_notes)
    partial = partial.gsub('%%%INSERT_THE_WITH_META_INFO_HERE%%%', get_instrument_name_fragment)
    partial
  end
end

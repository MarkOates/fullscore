class TemplateStuffer
  STAFF_PARTIAL = <<-CONTENT
    \\new Staff
    {
      %%%INSERT_NOTE_CONTENTS_HERE%%%
    }
  CONTENT

  attr_reader :staff_notes

  def self.stuff(staves_notes:)
    staves_notes.map do |staff_notes|
      TemplateStuffer.new(staff_notes: staff_notes).get_staff_partial
    end.join("")
  end

  def initialize(staff_notes:)
    @staff_notes = staff_notes
  end

  def get_staff_partial
    STAFF_PARTIAL.gsub('%%%INSERT_NOTE_CONTENTS_HERE%%%', staff_notes)
  end
end

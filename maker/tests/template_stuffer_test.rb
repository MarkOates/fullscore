gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/template_stuffer'

class TemplateStufferTest < Minitest::Test
  def staff_notes
    "c' d' e' ges''"
  end

  def test_creates_a_partial
    template_stuffer = TemplateStuffer.new(staff_notes: staff_notes)
    expected_staff_partial = <<-CONTENT
    \\new Staff \\with {
      
    }
    {
      c' d' e' ges''
    }
    CONTENT

    assert_equal expected_staff_partial, template_stuffer.staff_partial
  end

  def test_creates_an_array_of_partials
    staves_notes = [
      "c' d' e' ges''",
      "g'' a' c' d''",
    ]

    expected_staff_partial = <<-CONTENT
    \\new Staff \\with {
      
    }
    {
      c' d' e' ges''
    }
    \\new Staff \\with {
      
    }
    {
      g'' a' c' d''
    }
    CONTENT
    stuffed_template = TemplateStuffer.stuff(staves_notes: staves_notes)

    assert_equal expected_staff_partial, stuffed_template
  end
end

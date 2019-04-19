gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/template_stuffer'
require 'minitest/reporters'
Minitest::Reporters.use! [Minitest::Reporters::DefaultReporter.new(:color => true)]

class TemplateStufferTest < Minitest::Test
  def staves_content_temp_default_arg
    [
      {
        instrument: {
          name: {
            full: 'Trombone',
            abbreviated: 'Tbn.',
          }
        },
        notes: "c' d'' e'",
      },
      {
        notes: "c' d'' e'".split(' ').reverse.join(' '),
      }
    ]
  end

  def test_creates_a_partial
    template_stuffer = TemplateStuffer.new(
      staff_notes: "c' d' e' ges''",
    )
    expected_staff_partial = <<-CONTENT
    \\new Staff \\with {
      
    }
    {
      c' d' e' ges''
    }
    CONTENT

    assert_equal expected_staff_partial, template_stuffer.staff_partial(include_black_background_postfix: false)
  end

  def test_creates_an_array_of_partials
    expected_staff_partial = <<-CONTENT
    \\new Staff \\with {
      instrumentName = #"Trombone"
shortInstrumentName = #"Tbn."
    }
    {
      c' d'' e'
    }
    \\new Staff \\with {
      
    }
    {
      e' d'' c'
    }
    CONTENT
    stuffed_template = TemplateStuffer.stuff(staves_contents: staves_content_temp_default_arg, use_black_background: false)

    assert_equal expected_staff_partial, stuffed_template
  end

  def test_includes_staff_names
    expected_staff_partial = <<-CONTENT
    \\new Staff \\with {
      instrumentName = #"Trombone"
shortInstrumentName = #"Tbn."
    }
    {
      c' d'' e'
    }
    \\new Staff \\with {
      
    }
    {
      e' d'' c'
    }
    CONTENT
    stuffed_template = TemplateStuffer.stuff(staves_contents: staves_content_temp_default_arg, use_black_background: false)

    assert_equal expected_staff_partial, stuffed_template
  end
end

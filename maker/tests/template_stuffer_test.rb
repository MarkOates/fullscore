gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/template_stuffer'

class Converter
  def convert
    [0, 2, 4, 6]
  end
end

class TemplateStufferTest < Minitest::Test
  def staves
    {}
  end

  def converter
    Converter.new
  end

  def test_does_thing
    template_stuffer = TemplateStuffer.new(staves: staves, converter: converter)
    expected_output = "asdf"
    template_stuffer
  end
end

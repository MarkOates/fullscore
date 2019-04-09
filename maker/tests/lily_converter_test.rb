gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/lily_converter'

class LilyConverterTest < Minitest::Test
  def test_parses_middle_c
    notes = [0]
    converter = LilyConverter.new(notes: notes)
    expected_output = "c'"
    assert_equal expected_output, converter.convert
  end

  def test_parses_simple_example
    notes = [0, 2]
    converter = LilyConverter.new(notes: notes)
    expected_output = "c' d'"
    assert_equal expected_output, converter.convert
  end

  def test_parses_longer_example
    notes = [0, 2, 4, 5, 7, 9]
    converter = LilyConverter.new(notes: notes)
    expected_output = "c' d' e' f' g' a'"
  end
end

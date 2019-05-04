gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/chromatisizer'

class ChromatisizerTest < Minitest::Test
  def test_converts_diatonic_note_to_chromatic
    source_notes = [1, 3, 5]
    expected_notes = [0, 4, 7]
    assert_equal expected_notes, Chromatisizer.new(source_notes).chromatics
  end
end

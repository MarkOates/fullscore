require_relative '../../lib/chromatic/chord_builder'
require_relative '../test_helper'

module Chromatic
  class ChordBuilderTest < Minitest::Test
    def test_plots_notes_in_a_minor_chord
      builder = ChordBuilder.new(root: 0, quality: 'minor')

      expcected = 'i'
      actual = builder.build

      assert_equal expcected, actual
    end

    def test_plots_notes_in_a_major_chord
      builder = ChordBuilder.new(root: 0, quality: 'major')

      expcected = 'I'
      actual = builder.build

      assert_equal expcected, actual
    end
  end
end


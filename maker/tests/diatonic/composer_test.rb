gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../lib/diatonic/composer'

module Diatonic
  class ComposerTest < Minitest::Test
    def test_works
      composition = Composer.new.composition
      expected_composition = {
        chordal_projections: [
          [1, 3, 5],
          [6, 8, 10],
          [4, 6, 8],
          [5, 7, 9],
          [1, 3, 5],
        ],
      }

      assert_equal expected_composition, composition
    end
  end
end

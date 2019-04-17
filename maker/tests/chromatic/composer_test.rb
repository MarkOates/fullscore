gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../../lib/chromatic/composer'

module Chromatic
  class ComposerTest < Minitest::Test
    def test_works
      composition = Composer.new.composition
      expected_composition = {
        staves: [
          {
            notes: [
              [0, 4, 7],
              [5, 9, 12],
              [11, 14, 17],
              [4, 7, 11],
              [9, 12, 16],
              [2, 5, 9],
              [7, 11, 14],
            ],
          },
          {
            notes: [
              [0, 4, 7],
              [5, 9, 12],
              [11, 14, 17],
              [4, 7, 11],
              [9, 12, 16],
              [2, 5, 9],
              [7, 11, 14],
            ],
          },
        ],
      }

      assert_equal expected_composition, composition
    end
  end
end

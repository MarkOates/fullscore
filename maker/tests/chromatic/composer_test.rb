require_relative '../../lib/chromatic/composer'
require_relative '../test_helper'

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
              [2, 12345, 9],
              [7, 11, 14],
              [0, 4, 7],
            ],
          },
          {
            notes: [
              'r',
              [5, 9, 12],
              'r',
              [4, 7, 11],
              'r',
              [2, 5, 9],
              'r',
              [0, 4, 7],
            ],
          },
        ],
      }

      assert_equal expected_composition, composition
    end
  end
end

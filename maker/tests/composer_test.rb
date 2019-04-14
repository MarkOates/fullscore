gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/composer'

class ComposerTest < Minitest::Test
  def test_works
    composition = Composer.new.composition
    expected_composition = {
      chromatic_reduction: [ 0, 2, 4, 5, 7, 9, 11 ],
      one_off: true,
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

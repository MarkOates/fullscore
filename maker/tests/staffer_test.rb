gem 'minitest', '~> 5.4'
require 'minitest/autorun'
require_relative '../lib/staffer'

class StafferTest < Minitest::Test
  def test_staffer_places_the_notes_into_staves
    notes = [0, 4, 7]
    staffer = Staffer.new(notes: notes)
    expected_output = {
      staff_1: {
        notes: [0, 7],
      },
      staff_2: {
        notes: [4],
      },
    }

    assert_equal expected_output, staffer.staff
  end
end

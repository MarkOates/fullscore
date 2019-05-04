require_relative '../lib/staffer'
require_relative 'test_helper'

class StafferTest < Minitest::Test
  def test_staffer_places_the_notes_into_staves
    notes = [0, 4, 7, 9, 10, 6 ]
    staffer = Staffer.new(notes: notes)
    expected_output = {
      staff_1: {
        notes: [0, 7, 10],
      },
      staff_2: {
        notes: [4, 9, 6],
      },
    }

    assert_equal expected_output, staffer.staff
  end
end

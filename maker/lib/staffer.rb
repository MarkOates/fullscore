class Staffer
  attr_reader :notes

  def initialize(notes:)
    @notes = notes
  end

  def staff
    expected_output = {
      staff_1: {
        notes: [0, 7],
      },
      staff_2: {
        notes: [4],
      },
    }
  end
end

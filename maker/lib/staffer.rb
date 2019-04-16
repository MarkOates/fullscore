class Staffer
  STAVES_COUNT = 2
  attr_reader :notes

  def initialize(notes:)
    @notes = notes
  end

  def staff
    expected_output = {}

    notes.each_with_index do |note, index|
      staff_num = index % STAVES_COUNT
      staff_key_sym = "staff_#{staff_num+1}".to_sym
      expected_output[staff_key_sym] ||= { notes: [] }

      expected_output[staff_key_sym][:notes] << note
    end

    expected_output
  end
end

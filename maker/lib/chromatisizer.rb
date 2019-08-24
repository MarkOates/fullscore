class Chromatisizer
  attr_reader :notes

  def initialize(notes)
    @notes = notes
  end

  def chromatics
    notes.map { |note| chromatic(note) }
  end

  private

  def chromatic(diatonic)
    case diatonic
    when 1
      0
    when 2
      2
    when 3
      4
    when 4
      5
    when 5
      7
    when 6
      9
    when 7
      11
    when 8
      13
    when 9
      15
    else
      throw StandardError.new("unknown diatonic value")
    end
  end
end

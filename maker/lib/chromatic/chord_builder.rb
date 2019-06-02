class ChordBuilder
  attr_reader :root, :quality

  def initialize(root:, quality:)
    @root = root
    @quality = quality
  end

  def build
    base_string = get_base_string

    case quality
    when 'minor'
      base_string
    when 'major'
      base_string.upcase
    else
      raise UnknownChordQuality, "chord quality not recognized: \"#{qualith}\""
    end
  end

  private

  def get_base_string
    case root
    when 0
      'i'
    when 2
      'ii'
    when 4
      'iii'
    when 5
      'iv'
    when 7
      'v'
    when 9
      'vi'
    when 11
      'vii'
    else
      raise StandardError
    end
  end
end

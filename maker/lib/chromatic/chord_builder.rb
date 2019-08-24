class ChordBuilder
  attr_reader :root, :quality

  def initialize(root:, quality:)
    @root = root
    @quality = quality
  end

  def build
    case quality
    when 'minor'
      accidental + base_string
    when 'major'
      accidental + base_string.upcase
    when 'augmented'
      accidental + base_string.upcase + '+'
    when 'diminished'
      accidental + base_string + 'o'
    else
      raise UnknownChordQuality, "chord quality not recognized: \"#{qualith}\""
    end
  end

  private

  def accidental
    modded_root = root % 12

    case modded_root
    when 0, 2, 4, 5, 7, 9, 11
      ''
    when 1, 3, 6, 8, 10
      'b'
    else
      raise StandardError, "unknown modded root #{modded_root} for root #{root}"
    end
  end

  def base_string
    modded_root = root % 12

    case modded_root
    when 0
      'i'
    when 1, 2
      'ii'
    when 3, 4
      'iii'
    when 5
      'iv'
    when 6, 7
      'v'
    when 8, 9
      'vi'
    when 10, 11
      'vii'
    else
      raise StandardError
    end
  end
end

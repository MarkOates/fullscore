class ChordBuilder
  attr_reader :root, :quality

  def initialize(root:, quality:)
    @root = root
    @quality = quality
  end

  def build
    get_base_string
  end

  def get_base_string
    case root
    when 0
      'i'
    else
      raise StandardError
    end
  end
end

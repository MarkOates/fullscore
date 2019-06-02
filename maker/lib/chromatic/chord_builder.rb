class ChordBuilder
  attr_reader :root

  def initialize(root:)
    @root = root
  end

  def build
    case root
    when 0
      'i'
    else
      raise StandardError
    end
  end
end

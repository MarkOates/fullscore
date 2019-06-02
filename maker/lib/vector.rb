class ChromaticVector
  attr_reader :direction

  def initialize(direction:)
    @direction = direction
  end

  def render
    case direction
    when 'i'
      [ 9, 12, 16 ]
    end
  end

  private

  def minor_from(root:)
    [ root, root + 3, root + 7 ]
  end

  def major_from(root:)
    [ root, root + 4, root + 7 ]
  end

  def augmented_from(root:)
    [ root, root + 4, root + 8 ]
  end

  def diminished_from(root:)
    [ root, root + 3, root + 6 ]
  end
end

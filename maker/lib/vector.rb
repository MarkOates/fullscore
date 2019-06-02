class ChromaticVector
  class UnrecognizedTriadQuality < StandardError; end

  ROOTS = {
      'i'   => 0,
      'ii'  => 2,
      'iii' => 4,
      'iv'  => 5,
      'v'   => 7,
      'vi'  => 9,
      'vii' => 11,
    }

  attr_reader :direction

  def initialize(direction:)
    @direction = direction
  end

  def render
    root = extract_root(string: direction)
    quality = extract_quality(string: direction)

    {
      normalized: render_triad(root: root, quality: quality),
      root: root,
    }
  end

  private

  def extract_quality(string:)
    string.downcase == string ? :minor : :major
  end

  def extract_root(string:)
    ROOTS[string.downcase]
  end

  def render_triad(root:, quality:)
    case quality
    when :major
      major_from(root: root)
    when :minor
      minor_from(root: root)
    when :augmented
      augmented_from(root: root)
    when :diminished
      diminished_from(root: root)
    else
      raise UnrecognizedTriadQuality, "quality: \"#{quality}\""
    end
  end

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

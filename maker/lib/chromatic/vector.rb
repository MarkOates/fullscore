class ChromaticVector
  class UnrecognizedTriadQuality < StandardError; end

  ROOTS = {
        'bi'   => 11,
      'i'      => 0,
        '#i'   => 1,
        'bii'  => 1,
      'ii'     => 2,
        '#ii'  => 3,
        'biii' => 3,
      'iii'    => 4,
        '#iii' => 5,
        'biv'  => 3,
      'iv'     => 5,
        '#iv'  => 6,
        'bv'   => 6,
      'v'      => 7,
        '#v'   => 8,
        'bvi'  => 8,
      'vi'     => 9,
        '#vi'  => 9,
        'bvi'  => 10,
      'vii'    => 11,
        '#vii' => 0,
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
      name: [ direction ],
    }
  end

  private

  def extract_quality(string:)
    case string.downcase == string
    when true # minor-like
      string[-1] == 'o' ? :diminished : :minor
    when false # major-like
      string[-1] == '+' ? :augmented : :major
    end
  end

  def extract_root(string:)
    key = keyafy(key: string)
    ROOTS[key]
  end

  def keyafy(key:)
    key.downcase.gsub(/[\+o]/, '')
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

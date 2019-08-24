require_relative '../../lib/chromatic/chord_notes'
require_relative '../../lib/chromatic/melody_extractor'
require_relative '../../lib/chromatic/voicer'

module Composer
  class Base
    def staves
      []
    end

    def composition
      {
        staves: staves,
      }
    end
  end
end

module Diatonic
  class Composer
    def composition
      foundations = [ 1, 6, 4, 5, 1 ]
      harmonic_projection = diatonic_projection(foundations)
    end

    def diatonic_projection(foundations)
      chordal_projections = foundations.map do |foundation|
        [foundation, foundation + 2, foundation + 4]
      end

      result = {
        chordal_projections: chordal_projections,
      }
    end
  end
end

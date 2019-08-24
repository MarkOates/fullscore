module Chromatic
  class MelodyExtractor
    RESOLUTIONS = [
      [9, 7], # ^6 to ^5
      [2, 0], # ^2 to ^1
      [5, 4], # ^4 to ^3
      [11, 12], # ^7 to ^1+
      [-1, 0], # ^7 to ^1+
    ]

    def self.resolves?(from:, to:)
      # can be used to make decisions about
      # melodic direction
    end

    def self.something_else_i_cant_label
      # melodic jump can be made to an anticipation
    end

    def self.random(projections:)
      #projections = ChordNotes.notes_for('circle_of_5ths')
      rng1 = Random.new(3461234)
      projections.map do |projection|
        index = rng1.rand(projection.size)
        projection[index]
      end
    end

    def self.least_leaps
    end

    def self.most_leaps
    end

    def self.suspend_upward
    end

    def self.just_not(other_extraction)
    end
  end
end

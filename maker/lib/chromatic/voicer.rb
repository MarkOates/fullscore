module Chromatic
  class Voicer
    attr_reader :notes

    def initialize(notes)
      @notes = notes
    end

    def ultra_low_range
      notes.map { |note| note - 24 }
    end

    def low_range
      notes.map { |note| note - 12 }
    end

    def center_range
      notes
    end

    def high_range
      notes.map { |note| note + 12 }
    end

    def ultra_high_range
      notes.map { |note| note + 24 }
    end

    def open # untested
      notes.each_with_index.map { |note, index| index.even? ? note : note + 12 }
    end
  end
end

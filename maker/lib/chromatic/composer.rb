require_relative 'chord_notes'
require_relative 'voicer'

module Chromatic
  class Composer
    def composition
      projections = ChordNotes.notes_for('circle_of_5ths')

      result = {
        staves: [
          {
            notes: projections.map { |projection| projection.last },
          },
          {
            notes: projections.map { |projection| Voicer.new(projection).open },
          },
          {
            notes: projections.map { |projection| projection.first },
          }
        ]
      }
    end
  end
end

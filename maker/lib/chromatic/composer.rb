require_relative 'chord_notes'

module Chromatic
  class Composer
    def composition
      projections = ChordNotes.notes_for('circle_of_5ths')

      result = {
        staves: [
          {
            notes: projections,
          },
          {
            notes: projections,
          }
        ]
      }
    end
  end
end

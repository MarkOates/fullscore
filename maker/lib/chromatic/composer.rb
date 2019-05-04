require_relative 'chord_notes'
require_relative 'melody_extractor'
require_relative 'voicer'

module Chromatic
  class Composer
    def composition
      projections = ChordNotes.notes_for('circle_of_5ths')
      #projections << ChordNotes.new.chord_notes('I')


      #melody = MelodyExtractor.random(projections: projections)
      #melody.pop
      #melody << 12  # make sure it ends on tonic

      {
        staves: [
          {
            notes: projections,
          },
          {
            notes: projections.each_with_index.map { |projection, index| index.even? ? 'r' : projection },
          },
        ]
      }
    end
  end
end

require_relative 'chord_notes'
require_relative 'melody_extractor'
require_relative 'voicer'

module Chromatic
  class Composer
    def composition
      projections = ChordNotes.notes_for('circle_of_5ths')
      projections << ChordNotes.new.chord_notes('I')


      melody = MelodyExtractor.random(projections: projections)
      melody.pop
      melody << 12  # make sure it ends on tonic

      result = {
        staves: [
          {
            notes: melody,
          },
          {
            notes: projections.map { |projection| Voicer.new(projection).open },
          },
          {
            notes: projections.map { |projection| projection.first },
          },
        ]
      }
    end
  end
end

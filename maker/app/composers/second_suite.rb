require_relative '../composer_base'

class SecondSuite < ComposerBase
  def composition
    projections = Chromatic::ChordNotes.notes_for('circle_of_5ths')
    projections << Chromatic::ChordNotes.new.chord_notes('I')


    melody = Chromatic::MelodyExtractor.random(projections: projections)
    melody.pop
    melody << 12  # make sure it ends on tonic

    result = {
      staves: [
        {
          notes: melody,
        },
        {
          notes: projections.map { |projection| Chromatic::Voicer.new(projection).open },
        },
        {
          notes: projections.map { |projection| projection.first },
        },
        {
          notes: projections.map { |projection| projection.first },
        },
        {
          notes: projections.map { |projection| projection.first },
        },
      ]
    }
  end
end

require_relative '../composer_base'

class SecondSuite < ComposerBase
  def composition
    projections = Chromatic::ChordNotes.notes_for('circle_of_5ths')
    projections.concat(Chromatic::ChordNotes.notes_for('ascending_bass'))
    projections << Chromatic::ChordNotes.new.chord_notes('I')


    melody = Chromatic::MelodyExtractor.random(projections: projections)
    melody.pop
    melody << 12  # make sure it ends on tonic

    result = {
      staves: [
        {
          instrument: { name: { full: 'Flute', abbreviated: 'Fl.', } },
          notes: melody.map { |value| value + 12 },
        },
        {
          instrument: { name: { full: 'Oboe', abbreviated: 'Ob.', } },
          notes: melody.each_with_index.map { |projection, index| index.even? ? 'r' : projection },
          #notes: melody,
        },
        {
          instrument: { name: { full: 'Clarinet in Bb', abbreviated: 'Cl.', } },
          notes: projections.map { |projection| Chromatic::Voicer.new(projection).open },
        },
        {
          instrument: { name: { full: 'Horn in F', abbreviated: 'F Hn.', } },
          notes: projections.map { |projection| projection.first },
        },
        {
          instrument: { name: { full: 'Bassoon', abbreviated: 'Bsn.', }, clef: 'bass', },
          notes: projections.map { |projection| projection.first - 12 },
        },
      ]
    }
  end
end

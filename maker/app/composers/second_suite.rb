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
          instrument: { name: { full: 'Flute', abbreviated: 'Fl.', } },
          notes: melody,
        },
        {
          instrument: { name: { full: 'Clarinet in Bb', abbreviated: 'Cl.', } },
          notes: projections.map { |projection| Chromatic::Voicer.new(projection).open },
        },
        {
          instrument: { name: { full: 'Oboe', abbreviated: 'Ob.', } },
          notes: projections.map { |projection| projection.first },
        },
        {
          instrument: { name: { full: 'Horn in F', abbreviated: 'F Hn.', } },
          notes: projections.map { |projection| projection.first },
        },
        {
          instrument: { name: { full: 'Bassoon', abbreviated: 'Bsn.', }, clef: 'bass', },
          notes: projections.map { |projection| projection.first },
        },
      ]
    }
  end
end

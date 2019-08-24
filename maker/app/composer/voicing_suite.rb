require_relative '../composer/base'

class VoicingSuite < Composer::Base
  DIATONIC = [0, 2, 4, 5, 7, 9, 11]

  def next_diatonic(chromatic:, interval: 1)
    index = DIATONIC.find_index(chromatic)
    DIATONIC[index + interval]
  end

  def ascend_sequence(cell:)
    3.times.map do |i|
      [next_diatonic(chromatic: 0, interval: i),
       next_diatonic(chromatic: 4, interval: i),
       next_diatonic(chromatic: 2, interval: i),
       'r']
    end.flatten
  end

  def octave_transpose(cell)
    cell.map do |value|
      if value == 'r'
        'r'
      else
        value + 12
      end
    end
  end

  def octave_transpose_down(cell)
    cell.map do |value|
      if value == 'r'
        'r'
      else
        value - 12
      end
    end
  end

  def first_chord_note(cell)
    cell.map do |value|
      if value == 'r'
        'r'
      else
        value.first
      end
    end
  end

  def append_rest(cell:)
    cell << 'r'
  end

  def harmonize_in_3rds(cell:)
    cell.each_with_index.map do |value, index|
      if value == 'r'
        'r'
      else
        [
          value,
          next_diatonic(chromatic: value, interval: 2),
        ]
      end
    end
  end

  def composition
    projections = Chromatic::ChordNotes.notes_for('circle_of_5ths')
    projections.concat(Chromatic::ChordNotes.notes_for('ascending_bass'))
    projections << Chromatic::ChordNotes.new.chord_notes('I')
    projections << 'r'

    melody = Chromatic::MelodyExtractor.random(projections: projections)
    melody.pop
    melody << 12  # make sure it ends on tonic

    cell = [0, 4, 2, 'r']

    result = {
      staves: [
        {
          instrument: { name: { full: 'Flute', abbreviated: 'Fl.', } },
          notes: octave_transpose(melody),
        },
        {
          instrument: { name: { full: 'Oboe', abbreviated: 'Ob.', } },
          notes: melody,
          #notes: melody.each_with_index.map { |projection, index| index.even? ? 'r' : projection },
        },
        {
          instrument: { name: { full: 'Clarinet in Bb', abbreviated: 'Cl.', } },
          #notes: [0, 4, 2, 'r', Note(duration: 2, pitches: [0, 4, 7])] #projections.map { |projection| Chromatic::Voicer.new(projection).open },
          notes: harmonize_in_3rds(cell: ascend_sequence(cell: cell)),
          #notes: projections.map { |projection| Chromatic::Voicer.new(projection).open },
        },
        {
          instrument: { name: { full: 'Horn in F', abbreviated: 'F Hn.', } },
          notes: first_chord_note(projections),
        },
        {
          instrument: { name: { full: 'Bassoon', abbreviated: 'Bsn.', }, clef: 'bass', },
          notes: octave_transpose_down(first_chord_note(projections)),
        },
        {
          instrument: { name: { full: 'Piano (R.H.)', abbreviated: 'Pf-R.', }, },
          notes: projections.map { |projection| Chromatic::Voicer.new(projection).open },
          #notes: projections.map { |projection| projection.first - 12 },
        },
      ]
    }
  end
end

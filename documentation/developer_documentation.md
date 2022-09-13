# Fullscore Developer Documentation

## Core Models

[to write]


## Measures

- Basic - A simple stand-alone measure.  There's nothing unique about this type
  of measure.
- Plotted - Plotted measures are measures that are the direct result of a calculation done
by a plotter.  A plotted measure is dynamic.  If you modify the plotter, then
the measure should be updtated dynamically.
- ReferenceById - ReferenceById measures are quite simple.  They're direct mirror copies of other
measures.  There are no transforms applied to these measures and any changes to
the original source will be reflected in the ReferenceById measure.  In this case, the ID of the measure is what is used to identify the measure to
copy.  In some past cases, a measure may have been referenced by its coordinates, but these types of references are more fragile and so referencing by ID was added.
- Stack - This is a measure composed of multiple transformations.  Rather than a set list
of notes, these
- Static - A static measure is a type of "constant" measure.  There are a few
  preset static measures, like certain types of scales, for example.  They're usually used as source material for
  building and crafting other material.  The defining characteristic of a Static
  measure is that it can't be modified.

## Plotters

Plotters are powerful tools that can place one or multiple measures into the
grid.  Their functionality is very generic and depends on the implementation and
the needs of the plotting.  Plotters must override a plot() method, but otherwise do not have any more
ellaborate usages, unless the drived adds more complex behavior and/or requirements.

Plotters might be used to distribute the voicing of a chord across several instruments, they could be used to fill chords into a staff given
a HarmonicAnalysisSymbol, and in really ellaborate cases, they could even be be responsible for writing an entire piece into the score. Some plotters
might be ephemerial (used once and disposed of), while others might maintain a list of its plotted measures so it can destroy and replot them.
Plotting in situations like this can get complicated, when other measures (ReferenceById, Stack) can potentially be referencing plotted measures and
need to be re-linked. It's up to you to figure this out depending on your needs in the score.


## Transforms

Transforms are the transformations that can be applied to a note, measure, or
sequence of notes or sequences of measures.  These exist in the "transforms/"
folder, and consist of transforms like:

- AddDot - adds a dot to a note (or set of notes)
- AppendNote - appends a not after a note (or set of notes)
- Ascend - on a set of notes, ascends each subsequent note by a scale step from
  the previous
- ClearMeasure - removes all the notes
- Descend - on a set of notes, descends each subsequent note by a scale step from the previous
- DoubleDuration - doubles the duration of a note (or set of notes)
- EraseNote - removes a note from a set of notes (by its index position)
- HalfDuration - halves the duration of a note (or set of notes)
- InsertNote - inserts a note into a set of notes at a given position
- Invert - inverts a note (or set of notes) along an axis
- NotesAt - given a set of notes and a set of indexes, returns a new set of notes from indexes
- Octatonic1 - will transfor the notes into a octatonic scale starting at 0
- RemoveDot - will remove a single dot from a note (or set of notes).  Note that
  notes cannot have "negative dots", so if some notes from the set of notes have
  their dots removed, then adding another dots after will apply the same number
  of dots to all the notes in the set
- Retrograde - will reverse the order of notes in the set
- SplitNote - will take a note (or set of notes) and halve its duration and
  duplicate it.
- Stack - a set of transforms will be applied to the note (or set of notes).
- ToggleRest - given a note (or set of notes), will toggle if it is a rest or
  not.
- Transpose - will transpose a note by an integer value.  Note that
  transpositions are whole numbers only.

## Actions

Actions are the individual explicit instructions that can be executed on the system.  Some are really simple, like "move cursor down", but it should be worth noting that most Transforms have corellated actions as well.

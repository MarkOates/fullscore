## Lily Builder

The Lily Builder can be used to automatically assemble musical notation output for content generated through the maker.  Two steps are required to have a complete comprehensive setup.

## Setup

### Step 1) Have Rerun running

Have rerun running in a separate instance with the following command:

```
rerun bin/scripts/lilypond output-lily.ly -p "*.ly"
```

This will cause `rerun` to be watching in the background and will run the `lilypond` script to generate the output from the `output-lily.ly` file that exists in the root of the `fullscore/` project directory any time it (or any other `.ly` file) is
modified.

### Step 2) Generate New Notes

When in the directory `fullscore/bin/scripts`, setup a `rerun` to run the command `ruby lily_builder.rb` any time it is modified.  This script should be adapted to be responsible for generating the file, but to rerun it directly:

```
rerun ruby lily_builder.rb -p "lily_builder.rb"
```

It is helpful to keep the `output-lily.pdf` file open in the Finder preview, as it is expected to automatically refresh when the notes change.

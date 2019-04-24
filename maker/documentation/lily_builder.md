## Lily Builder

The Lily Builder can be used to automatically assemble musical notation output for content generated through the maker.  Two steps are required to have a complete comprehensive setup.  All the commands should be run from `fullscore/maker/`.

## Setup

### Step 1) Generate new notes with your composer

Have another rerun running in a separate terminal instance with the following command:

```
rerun "ruby app/lily_builder.rb" -p "{app/lily_builder.rb,templates/lilypond-template.ly}" -c
```

This will cause `ruby lily_builder.rb` to be rerun anytime it's modified, which should be generating the `output-lily.ly` file, that gets picked up by the next command.


### Step 2) Have Rerun running to compile lilypoind output to PDF

Have rerun running in a separate terminal instance with the following command:

```
rerun "bin/scripts/lilypond -dbackend=svg output-lily.ly" -p "output-lily.ly" -c
```

This will cause `rerun` to watch in the background for any changes to the `output-lily.ly` file, that will cause the `lilypond` script to convert the `output-lily.ly` file to a PDF.  This PDF can be viewed in MacOS preview (through Finder), and will automaticaly refresh on the changes.

### Step 3) Copy the newly output file to HomeServer

```
rerun "cp output-lily.svg ~/Repos/HomeServer/db/files/output-lily.svg" -p "output-lily.svg" -c
```

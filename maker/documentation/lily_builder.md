## Lily Builder

The Lily Builder can be used to automatically assemble musical notation output for content generated through the maker.  Two steps are required to have a complete comprehensive setup.  All the commands should be run from `fullscore/maker/`.

## Setup

In a separate terminal session, do the following steps:

### Step 1) Navigate to the maker Directory

```
cd ~/Repos/fullscore/maker
```

### Step 2) Run the Compile and Output Script

```
./bin/scripts/compile_and_output
```

This script will initialize a `rerun` that will assemble and build your
composition, then copy the output to the `HomeServer`.  If the HomeServer is
running, your composition should be visible at `https://stradivarious.ngrok.io`.

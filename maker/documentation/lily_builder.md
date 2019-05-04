## Lily Builder

The Lily Builder can be used to automatically assemble musical notation output for content generated through the maker.  Two steps are required to have a complete comprehensive setup.  All the commands should be run from `fullscore/maker/`.

## Setup

### Step 1) Run the Compile and Output Script

In a separate terminal session, run the following commands:

```
cd ~/Repos/fullscore/maker
./bin/scripts/compile_and_output
```

This script will initialize a `rerun` that will assemble and build your
composition, then copy the output to the `HomeServer`.  If the HomeServer is
running, your composition should be visible at `https://stradivarious.ngrok.io`.


### Step 2) Run the automated tests on rerun

In a separate terminal session, run the following commands:

```
cd ~/Repos/fullscore/maker
./smart_test
```

This will run automated tests continually as you modify your code and create new
tests.

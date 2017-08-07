# Fullscore

Fullscore is music composition software with 2 design priorities:

1. Let the composer focus on the processes and techniques of modern music composition, theoretical concepts, structures, patterns, transformations, sets, cells, etc.
2. Allow music to be edited and transformed as quickly and robustly as possible, either at the low-level or the high-level, regardless of the required learning curve.

### How to get

There are no binary releases yet so you will have to build from source.

### Build Instructions

#### Dependencies

Fullscore is written in C++ and requires AllegroFlare.  If you're building with `gcc` or `clang`
you should be able to compile Fullscore by first getting the dependencies AllegroFlare and Google Test.  (AllegroFlare is dependent on Allegro 5.)

#### Building Fullscore

1. from the terminal clone the git repo:

```
$ git clone https://github.com/MarkOates/fullscore.git
```

2. enter into the `fullscore/` directory:

```
$ cd fullscore
```

3. update the following constants in the `Makefile` to point to the location of the dependencies on your system.  The values shown are the default for my mac:

```
LIBS_ROOT=/Users/markoates/Repos
ALLEGRO_DIR=$(LIBS_ROOT)/allegro5/build
ALLEGRO_FLARE_DIR=$(LIBS_ROOT)/allegro_flare
GOOGLE_TEST_DIR=$(LIBS_ROOT)/googletest
GOOGLE_TEST_LIB_DIR=$(GOOGLE_TEST_DIR)/build/googlemock/gtest
GOOGLE_TEST_INCLUDE_DIR=$(GOOGLE_TEST_DIR)/googletest/include
```

4. build with make:

```
$ make
```

5. run the program! :tada:

```
$ ./bin/fullscore
```

#### Building Tests

You can also build the tests with the following command:

```
$ make tests
```

And run them all with:

```
$ make run_tests
```

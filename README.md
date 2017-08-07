# Fullscore

![alt](https://camo.githubusercontent.com/a35caaa2feff7ba82209a75c4eb0371347350698/68747470733a2f2f707265766965772e6962622e636f2f673961524b762f495f6d5f6a7573745f686176696e675f66756e5f64726177696e675f73747566665f66756c6c73636f72655f323031375f30385f30355f30335f32365f33392e706e67)

Fullscore is music composition software with 2 design priorities:

1. Let the composer focus on the processes and techniques of modern music composition, theoretical concepts, structures, patterns, transformations, sets, cells, etc.
2. Allow music to be edited and transformed as quickly and robustly as possible, either at the low-level or the high-level, regardless of the required learning curve.

### How to get

There are no binary releases yet so you will have to build from source.

### Build Instructions

#### Dependencies

Fullscore is written in C++ and requires AllegroFlare.  If you're building with `gcc` or `clang`
you should be able to compile Fullscore by first getting the dependencies AllegroFlare and Google Test, and then following the build instructions below.  (AllegroFlare is dependent on Allegro 5.)

#### Building Fullscore

1. from the terminal, clone the git repo:

```
$ git clone https://github.com/MarkOates/fullscore.git
```

2. enter into the `fullscore/` directory:

```
$ cd fullscore
```

3. update the following constants in the `Makefile` to point to the location of the dependencies on your system.  The values shown are the default for my Mac:

```make
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

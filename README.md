# Matlab wrapper for libLBFGS

This is nothing more than a wrapper around native C functions for L-BFGS from https://github.com/chokkan/liblbfgs

Nothing fancy, for the documentation, refer to the C library, I dunno shit.

## HOWTO

### Requirements
 - a decent `git` version (min. `2.23`)
 - a recent `cmake` (at least 3.25)
 - a decent `gcc` version (tested with `4.8.5`)

#### Compile
`cd` into your working directory, then clone this repo with:

```
git clone https://github.com/giupo/mlbfgs
cd mlbfgs
mkdir build && cd build
```

It's important that you tell `cmake` where your Matlab installation is:

```
cmake .. -DMatlab_DIR_ROOT=/path_to/Matlab
make
```


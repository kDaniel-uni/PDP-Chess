# PDP project : chess

Programmation project of a chess game.

## Goal

With this project, we aim for testing multiple algorithms of tree search like minmax or negascout on a chess game. Everything is coded with the c++ language.

## Prerequisite

This project can be launched with any Ubuntu version over 18.04.

- CMake minimum version 3.13
```bash
sudo apt-get install cmake
```
or
```bash
sudo apt-get upgrade
```
-  Jsoncpp library
```bash
sudo apt-get install libjsoncpp-dev
```


## Installation

You first need to clone the project.

```bash
git clone git@gitlab.emi.u-bordeaux.fr:username/pdp-echec.git
cd pdp-echec
```

In order to launch this project, you need to be placed inside the "pdp-echec/src" folder then use the following commands :

  ```bash
  mkdir build
  cd build
  cmake ..
  make
 ```

## How to use

To launch the tests, use :

```bash
ctest
```
or
```bash
make test
```

To launch the app, use :

```bash
./pdp_chess <path_to_json_file> <1|2>
```

A template of json file can be found in the "pdp_echec/src/json_exemple" folder.
The second parameter represents the engine version, 1 should be preferred.

## Usable parameters

- Player Type :
    - Human
    - Random
    - AlphaBeta
    - NegaMax
    - NegaScout

- Heuristic Type :
    - Pawns
    - Rooks
    - Bishops
    - Knights
    - Queen
    - King
    - Backward
    - Forward
    - Doubled
    - Isolated
    - Legal

## Authors

Rossignon Morgan

Daniel Karl

Salomode Florian

Beites Marvin

Zucchelli Thomas

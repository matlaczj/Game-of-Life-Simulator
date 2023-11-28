# Game of Life Simulator

<p align="center">
  <img src="logo.png" alt="Logo" width="400"/>
</p>

## Overview

This project is a simulation of John Conway's Game of Life, a cellular automaton that demonstrates how simple rules can lead to complex and interesting patterns. The simulator is implemented in C and provides features such as visualization, file I/O, and various customization options.

## Table of Contents

- [Introduction](#introduction)
- [Rules of the Game](#rules-of-the-game)
- [Implementation Details](#implementation-details)
- [Usage](#usage)
- [Program Structure](#program-structure)
- [Features](#features)
- [Building and Running](#building-and-running)
- [Examples](#examples)
- [Testing](#testing)
- [Contributing](#contributing)

## Introduction

The Game of Life is a cellular automaton devised by John Conway. This simulator aims to showcase the fascinating patterns that emerge from a grid of cells following simple rules.

## Rules of the Game

- A cell can be in one of two states: alive or dead.
- Each cell interacts with its eight neighbors.
- The next state of a cell is determined by the following rules:
  1. A dead cell with exactly three live neighbors becomes alive.
  2. A live cell with two or three live neighbors survives.
  3. A live cell with fewer than two or more than three live neighbors dies.

## Implementation Details

The simulator is implemented in C and uses a two-dimensional array to represent the cell grid. The code is organized into modules, each responsible for specific functionalities such as updating the cell states, file I/O, and visualization.

## Usage

To use the simulator, follow the instructions outlined in the [Usage section](#usage) of this document. You can specify the initial configuration, the number of generations to simulate, and other parameters.

## Program Structure

The project is structured into several modules, each handling a specific aspect of the simulation. The key modules include:
- `main.c`: Contains the main function.
- `service.h`: Header file with macros, structure definition, and function prototypes.
- `prepare_space.c`: Initializes the game board.
- `update_space.c`: Updates the state of each cell.

## Features

- Visualization of each generation in the terminal.
- Saving simulation states to PNG images for later analysis.
- Loading and saving states using `.life` files.

## Building and Running

To build the simulator, use the provided `Makefile`. Execute the following commands:

```bash
make
```

To run the simulator, use the following command:

```bash
./exec [arguments]
```

For detailed information on command-line arguments, refer to the report catalog.

## Examples

Here are some examples of how to run the simulator:

```bash
./exec example.life 100 10
./exec custom.life 50 5 output_folder
```

## Testing

We have conducted various tests to ensure the correctness of the simulator. 

## Contributing

Contributions are welcome! If you find any issues or have ideas for improvements, please submit an issue or a pull request.
![dino_gif](https://github.com/BrandonCanCode/client-server-dino-game.git/assets/dino.gif)
# Dino
This repository contains a rendering of the popular chrome dinosaur game on the terminal, in C++ and curses.

## Requirements

### CMake
You will need cmake to create and use the build system.

### ncurses library

You will need to install the ncurses library using the package manager available to you in your operating system.

Ubuntu:
`sudo apt-get install libncurses5-dev libncursesw5-dev`

Arch Linux:
`sudo pacman -S ncurses`

## Installation

To install this program, clone this repository onto your local machine using the following command:

`$ git clone https://github.com/BrandonCanCode/client-server-dino-game.git`

Once you have cloned the repository, you can navigate to the repository directory.

`$ cd client-server-dino-game`

You will need to create a directory where the build files will be placed, preferably outside the project repository tree, and run the CMake command to generate the build system as follows:

`$ mkdir ../client-server-dino-game-build`
`$ cmake -B ../client-server-dino-game-build`

In order to compile the program you will need to run the following command:

`$ cmake --build ../client-server-dino-game-build`

To Run the game, the build system should create a link to the running binary in the current directory so you should be able to run the game with the following command:

`$ ./dinosaur_game`

In case that doesn't work on your system, the actual program is in the build directory so you can run it via the following command:
`$ ../chrome-dinosaur-terminal-build/dinosaur_game`

Enjoy!

## Credits

Thanks to [fundamelon](https://github.com/fundamelon/terminal-game-tutorial) and their terminal game tutorial for an intro to terminal game development.

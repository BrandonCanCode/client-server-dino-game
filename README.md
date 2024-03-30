![dino_gif](https://github.com/BrandonCanCode/client-server-dino-game.git/assets/dino.gif)
# Dino
This repository contains a rendering of the popular chrome dinosaur game on the terminal, in C++ and curses.
This project has been modified from the original to work as a client and server application.
Works great as a latency networking demo.

## Requirements
### ncurses library
Ubuntu:
`sudo apt-get install libncurses5-dev libncursesw5-dev`

## Installation
`$ make`

## Running
Run the server on your server node
`$ ./server`
Run client on your client node and input the server address
`$ ./dinosaur_game <ip4-address>`

## Credits
[wldfngrs](https://github.com/wldfngrs/chrome-dinosaur-terminal) created the original version of this game. 
I only modified it to work with a client and server.

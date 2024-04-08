CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -lncurses -lpthread

all: dinosaur_game server

dinosaur_game: src/main.cpp src/game.cpp src/obstacles.cpp src/player.cpp src/game_client.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

server: src/game_server.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f dinosaur_game server

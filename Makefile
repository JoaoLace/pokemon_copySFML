all:
	sudo rm main
	g++ -g -std=c++14 -Wall -I/usr/include src/main.cpp src/game.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
	./main
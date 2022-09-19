#include "Game.h"

void Game::printBoard() {
	std::cout << " \t";
	for(int i = 1; i < width; i++){
		std::cout << i << "\t";
	}
	std::cout << "\n";

	for (int i = 1; i < width; i++) {
		std::cout << char(64 + i) << "\t";
		for (int j = 1; j < width; j++) {
			std::cout << gameBoard.getField(i,j) << "\t";
		}
		std::cout << "\n";
	}
}

Game::Game() {
	std::cout << "Please enter heigth: ";
	std::cin >> this->heigth;
	std::cout << "Please enter width: ";
	std::cin >> this->width;

	Player firstPlayer;
	Player secondPlayer;
	
	firstPlayer.setIcon(1);
	secondPlayer.setIcon(2);

	player1 = firstPlayer;
	player2 = secondPlayer;

	round = 1;

	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->heigth; j++) {
			gameBoard.setField(0,i,j);
		}
	}
}

bool Game::runTime()
{
	this->printBoard();
	std::cout << "Player " << ((round == 1)? player1.getName() : player2.getName()) << "'s move.\n";
	int chooseX, chooseY;
	bool isValid=1;
	std::string input;
	do {
		if (!isValid) {
			std::cout << "Input invalid try again!\n";
		}
		std::cout << "X: ";
		std::cin >> input;
		isValid = isStringInt(input) && stoi(input) >= 1 && stoi(input) <= this->width;

	} while (isValid);
	chooseX = stoi(input);

	do {
		if (!isValid) {
			std::cout << "Input invalid try again!\n";
		}
		std::cout << "Y: ";
		std::cin >> input;
		isValid = isStringInt(input) && stoi(input) >= 1 && stoi(input) <= this->heigth;

	} while (isValid);
	chooseY = stoi(input);

	gameBoard.setField(round,chooseX, chooseY);

	if (round == 1) {
		round = 2;
	}
	else
		round = 1;

	return 0;
}

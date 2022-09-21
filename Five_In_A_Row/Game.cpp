#include "Game.h"

void Game::printBoard() {
	std::cout << " \t";
	for(int i = 1; i <= width; i++){
		std::cout << i << "\t";
	}
	std::cout << "\n";

	for (int i = 0; i < heigth; i++) {
		std::cout << char(65 + i) << "\t";
		for (int j = 0; j < width; j++) {
			switch (gameBoard[j][i]) {
			case 0:
				std::cout << ".\t";
				break;
			case 1:
				std::cout << player1.getIcon() << "\t";
				break;
			case 2:
				std::cout << player2.getIcon() << "\t";
				break;
			default:
					std::cout << "E\t";
					break;
			}
		}
		std::cout << "\n";
	}
}

Game::Game() {
	std::cout << "Please enter heigth: ";
	std::cin >> this->heigth;
	std::cout << "Please enter width: ";
	std::cin >> this->width;

	player1.setIcon(1);
	player2.setIcon(2);

	round = 1;

	Board board(this->width, this->heigth);
	this->gameBoard = board;
}

bool Game::runTime()
{
	this->printBoard();
	std::cout << "Player " << ((round == 1)? player1.getName() : player2.getName()) << "'s move.\n";
	int chooseX, chooseY;
	bool isValid=1;
	std::string input;
	do {
		do {
			if (!isValid) {
				std::cout << "Input invalid try again!\n";
			}
			std::cout << "X: ";
			std::cin >> input;
			if (input == "quit") {
				return 1;
			}
			isValid = isStringInt(input) && stoi(input) >= 1 && stoi(input) <= this->width;


		} while (!isValid);
		chooseX = stoi(input) - 1;

		do {
			if (!isValid) {
				std::cout << "Input invalid try again!\n";
			}
			std::cout << "Y: ";
			std::cin >> input;
			if (input == "quit") {
				return 1;
			}
			isValid = (input[0] >= 65 && input[0] <= 64 + this->heigth) || (input[0] >= 97 && input[0] <= 96 + this->heigth);

		} while (!isValid);
		chooseY = (input[0] < 97) ? input[0] - 65 : input[0] - 97;
		if (gameBoard[chooseX][chooseY] != 0) {
			std::cout << "Field taken, try again.\n";
		}
	} while (gameBoard[chooseX][chooseY] != 0);
	gameBoard[chooseX][chooseY] = round;

	if (round == 1) {
		round = 2;
	}
	else
		round = 1;

	std::cout << "\x1B[2J\x1B[H";
	return 0;
}

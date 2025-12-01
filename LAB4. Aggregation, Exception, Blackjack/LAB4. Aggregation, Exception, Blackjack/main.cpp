#include <iostream>
#include "Card.h"
#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Dealer.h"
#include "DeckClassAdapter.h"
#include "DeckObjectAdapter.h"
#include "IFormattable.h"
#include "Global.h"
int main() {
	setlocale(LC_ALL, "rus");
	int choice;
	std::cout << "Введите № задания:\n1 - Задание №1; " << std::endl
		<< "2 - Задание №2: ";
	std::cin >> choice;
	switch (choice) {
	case 1: {
		Game game;
		game.start();
		break;
	}
	case 2: {
		Deck mydeck(4, 52);
		DeckClassAdapter classAdapter(mydeck);
		prettyPrint(classAdapter);
		DeckObjectAdapter objectAdapter(mydeck);
		prettyPrint(objectAdapter);
	}
	}
}
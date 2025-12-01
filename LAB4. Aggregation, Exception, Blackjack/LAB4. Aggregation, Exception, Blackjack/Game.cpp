#include "Game.h"
#include <iostream>
#include <stdexcept>

Game::Game() : deck(4, 52) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    deck.shuffle();
}
void Game::showDeckStatus() {
    std::vector<int> counts = deck.cardsLeftEach();
    std::cout << "Колоды:";
    for (size_t i = 0; i < counts.size(); ++i) {
        std::cout << " [" << counts[i] << "]";
    }
    std::cout << std::endl;
}
void Game::start() {
    std::cout << static_cast<char>(16) << "Тип: базовый\n";
    std::cout << static_cast<char>(16) << "Доп. правила: сплит\n";
    std::cout << static_cast<char>(16) << "Баланс:" << playerMoney << std::endl << std::endl;
    while (playerMoney > 0) {
        bet = getPlayerBet();
        player.clear();
        dealer.clear();
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        player.addCard(deck.dealCard());
        dealer.addCard(deck.dealCard());
        showDeckStatus();
        showStatus();
        try {
            playerTurn();
            dealerTurn();
            processResult();
        }
        catch (const std::overflow_error& e) {
            playerMoney -= bet;
            std::cout << "Перебор! Вы проиграли! Ваш проигрыш: " << bet << ". Остаток: " << playerMoney << ".\n";
        }
        std::cout << "Ваши деньги: " << playerMoney << "\n\n";
        if (playerMoney <= 0) {
            std::cout << "У вас закончились деньги. Игра окончена.\n";
            break;
        }
    }
}

int Game::getPlayerBet() {
    int b = 0;
    while (true) {
        std::cout << "Ваша ставка? ";
        std::cin >> b;
        if (b > 0 && b <= playerMoney) {
            break;
        }
        std::cout << "Некорректная ставка. Попробуйте ещё раз.\n";
    }
    return b;
}

void Game::showStatus(bool showDealerFull) {
    std::cout << "Дилер: ";
    if (showDealerFull) {
        dealer.showHand(std::cout);
    }
    else {
        dealer.showInitialHand(std::cout);
    }
    std::cout << "\n";

    std::cout << "Вы: ";
    const auto& hand = player.getHand();
    for (size_t i = 0; i < hand.size(); ++i) {
        std::cout << hand[i].toString() << " ";
    }
    std::cout << "\n" << std::endl;
}

void Game::playerTurn() {
    while (true) {
        std::cout << "1. Хватит\n2. Еще\nВыберите действие: " << std::endl;
        int choice = 0;
        std::cin >> choice;

        if (choice == 1) {
            break;
        }
        else if (choice == 2) {
            player.addCard(deck.dealCard());
            showDeckStatus();
            showStatus();
            try {
                player.getPoints();
            }
            catch (const std::overflow_error&) {
                throw;
            }
        }
        else {
            std::cout << "Неверный выбор. Попробуйте ещё раз.\n";
        }
    }
}

void Game::dealerTurn() {
    dealer.play(deck);
    showStatus(true);
}
void Game::processResult() {

    int playerPoints = player.getPoints();
    int dealerPoints = dealer.getPoints();
    bool playerBlackjack = player.isBlackjack();
    bool dealerBlackjack = dealer.isBlackjack();

    if (playerBlackjack && dealerBlackjack) {
        std::cout << "Оба — блекджек! Ничья.\n";
    }
    else if (playerBlackjack) {
        playerMoney += bet;
        std::cout << "У вас блекджек! Вы выиграли: " << bet << ". Всего: " << playerMoney << ".\n";
    }
    else if (dealerBlackjack) {
        playerMoney -= bet;
        std::cout << "У дилера блекджек. Вы проиграли: " << bet << ". Остаток: " << playerMoney << ".\n";
    }
    else if (playerPoints > 21) {
        playerMoney -= bet;
        std::cout << "Перебор! Вы проиграли: " << bet << ". Остаток: " << playerMoney << ".\n";
    }
    else if (dealerPoints > 21) {
        playerMoney += bet;
        std::cout << "Дилер перебрал! Вы выиграли: " << bet << ". Всего: " << playerMoney << ".\n";
    }
    else if (playerPoints > dealerPoints) {
        playerMoney += bet;
        std::cout << "Вы выиграли! Выигрыш: " << bet << ". Всего: " << playerMoney << ".\n";
    }
    else if (playerPoints < dealerPoints) {
        playerMoney -= bet;
        std::cout << "Вы проиграли: " << bet << ". Остаток: " << playerMoney << ".\n";
    }
    else {
        std::cout << "Ничья.\n";
    }
}
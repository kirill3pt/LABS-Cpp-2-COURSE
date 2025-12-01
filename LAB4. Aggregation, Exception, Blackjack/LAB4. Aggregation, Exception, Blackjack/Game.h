#pragma once
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include <iostream>

class Game {
private:
    Deck deck; // game владеет deck (т.е. колодой), композиция
    Player player;
    Dealer dealer;
    int playerMoney = 100000; // стартовые деньги
    int bet = 0;
public:
    Game();
    void start();
    void showDeckStatus();
private:
    void playerTurn();
    void dealerTurn();
    void showStatus(bool showDealerFull = false);
    void processResult();
    int getPlayerBet();
};
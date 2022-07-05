#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <random>

#define DEFAULT 32
#define X 'x'
#define CIRCLE 'o'
#define ASCII_0 48
#define ASCII_9 57


enum GameResult : unsigned char {
    XWin,
    CircleWin,
    Tie
};

class TicTacToe {
public:
    TicTacToe();
    void run();
    
private:
    char m_board[9];
    bool m_running;
    bool m_turn;
    bool m_using_ai;
    void print();
    bool isNumber(const std::string& num);
    char getTurn(bool turn);
    bool didWin(char board[9]);
    bool didTie(char board[9]);
    void runAI();
    int getRandomFreeSpace(char board[9]);
};

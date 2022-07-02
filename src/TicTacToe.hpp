#pragma once
#include <string>

#define DEFAULT 32
#define X 'x'
#define CIRCLE 'o'
#define ASCII_0 48
#define ASCII_9 57
#define BOARD_SIZE 9

class TicTacToe {
public:
    TicTacToe();
    void run();
    
private:
    char m_board[BOARD_SIZE];
    bool m_running;
    bool m_turn;
    bool m_using_ai;
    void print();
    bool isNumber(const std::string& num);
    char getTurn();
    bool didWin();
};

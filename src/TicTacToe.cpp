#include "TicTacToe.hpp"


TicTacToe::TicTacToe() {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        m_board[i] = DEFAULT;
    }
    m_running = true;
    m_turn = false; 
    m_using_ai = false;
}

void TicTacToe::run() {
    while (m_running) {
        std::string input;
        int number = 0;
        std::cout << "number 1-9: ";
        std::cin >> input;       
        if (isNumber(input)) {
            number = std::stoi(input);
        } 
        else {
            std::cout << "please input a valid number\n";
            continue;
        }
        
        if (number <= 0 && number > BOARD_SIZE) {
            std::cout << "please keep the number between 1 and 9\n";
            continue;
        }
        number--;
        if (m_board[number] == DEFAULT) {
            m_board[number] = getTurn();
        }
        else {
            std::cout << "please select a square that wasn't already selected\n";
            continue;
        }
        print();
        if (didWin(m_board)) {
            std::cout << getTurn() << " Won the game!\n";
            m_running = false;
        }
        else if (didTie(m_board)) {
            std::cout << "Tie!\n";
            m_running = false;
            break;
        }
        m_turn = !m_turn;
        
        if (!m_using_ai) {
            continue; // play game normally
        }
        runAI();
    }
}

void TicTacToe::runAI() {
    // create copy of board
    int index = 0;
    bool currentTurn = m_turn;
    miniMax(m_board, &index);
    m_turn = currentTurn;
    m_board[index] = getTurn();
}

Result TicTacToe::miniMax(char board[BOARD_SIZE], int *index) {
    
}

bool TicTacToe::isNumber(const std::string& num) {
    for (const auto& char_ : num) {
        // if char is not numeric
        if (!isdigit(char_)) {
            return false;
        }
    }
    return true;
}

void TicTacToe::print() {
    for (int i = 1; i < BOARD_SIZE+1; i++) {
        if (m_board[i-1] == DEFAULT) {
            std::cout << i;
        }
        else {
            std::cout << m_board[i-1];
        }
        std::cout << " ";
        if (i % 3 == 0 && i) {
            std::cout << std::endl;
        }
    }
}

char TicTacToe::getTurn() {
    return m_turn ? X : CIRCLE;
}


bool TicTacToe::didWin(char board[BOARD_SIZE]) {
    // horizontal
    for (int i = 0; i < 9; i+=3) {
        if (m_board[i] == m_board[i+1] && m_board[i] == m_board[i+2] && m_board[i] != DEFAULT) {
            return true;
        }
    }
    // vertical
    for (int i = 0; i < 3; i++) {
        if (m_board[i] == m_board[i+3] && m_board[i] == m_board[i+6] && m_board[i] != DEFAULT) {
            return true;
        }
    }
    
    // diagonals
    return (m_board[0] == m_board[4] && m_board[0] == m_board[8] && m_board[0] != DEFAULT) || 
           (m_board[2] == m_board[4] && m_board[2] == m_board[6] && m_board[2] != DEFAULT);
}

bool TicTacToe::didTie(char board[BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (m_board[i] != DEFAULT) {
            return false;
        }
    }
    return true;
}

#ifndef TICTACTOE_H
#define TICTACTOE_H

    #include <iostream>
    #include <string>

    using namespace std;

    void displayBoard(const char board[3][3]);
    bool isValidMove(const char board[3][3], int row, int col);
    bool checkWin(const char board[3][3], char player);
    bool checkDraw(const char board[3][3]);
    void makeMove(char board[3][3], int row, int col, char player);
    bool isValidInteger(const std::string& str, int& number);
    void playGame();

#endif
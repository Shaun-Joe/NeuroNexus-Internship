#include "tictactoe.h"

void displayBoard(const char board[3][3])
{
    cout << "  1 2 3\n";
    for (int row = 0; row < 3; ++row)
    {
        cout << row + 1 << " ";
        for (int col = 0; col < 3; ++col)
        {
            cout << board[row][col] << " ";
        }
        cout << "\n";
    }
}

bool isValidMove(const char board[3][3], int row, int col)
{
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}

bool checkWin(const char board[3][3], char player)
{

    for (int i = 0; i < 3; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

bool checkDraw(const char board[3][3])
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if (board[row][col] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void makeMove(char board[3][3], int row, int col, char player)
{
    board[row][col] = player;
}

bool isValidInteger(const string &str, int &number)
{
    size_t idx;
    try
    {
        number = stoi(str, &idx);

        return idx == str.size() && number >= 1 && number <= 3;
    }
    catch (...)
    {

        return false;
    }
}

void playGame()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    bool gameWon = false;

    while (!gameWon && !checkDraw(board))
    {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", it's your turn.\n";

        int row, col;
        string input;
        bool validInput = false;

        while (!validInput)
        {
            cout << "Enter row (1-3) and column (1-3) separated by space: ";
            getline(cin, input);

            size_t spacePos = input.find(' ');
            if (spacePos != string::npos)
            {
                string rowStr = input.substr(0, spacePos);
                string colStr = input.substr(spacePos + 1);
                int rowNum, colNum;

                if (isValidInteger(rowStr, rowNum) && isValidInteger(colStr, colNum))
                {
                    row = rowNum - 1;
                    col = colNum - 1;

                    if (isValidMove(board, row, col))
                    {
                        makeMove(board, row, col, currentPlayer);
                        validInput = true;
                    }
                    else
                    {
                        cout << "Invalid move. The cell is already occupied or out of bounds." << endl;
                    }
                }
                else
                {
                    cout << "Invalid input. Please enter numbers between 1 and 3." << endl;
                }
            }
            else
            {
                cout << "Invalid input format. Please enter row and column separated by space." << endl;
            }
        }

        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameWon = true;
        }
        else
        {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    if (!gameWon)
    {
        displayBoard(board);
        cout << "It's a draw!" << endl;
    }

    cout << "Do you want to play again? (y/n): ";
    string playAgain;
    getline(cin, playAgain);

    if (playAgain == "y" || playAgain == "Y")
    {
        system("clear");
        playGame();
    }
}

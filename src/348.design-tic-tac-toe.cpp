class TicTacToe {

public:

    TicTacToe(int n) {
        board.resize(n);
        for (auto &v : board) {
            for (int i = 0; i < n; ++i) {
                v.push_back(0);
            }
        }
        this->n = n;
    }

    int move(int row, int col, int player) {
        // execute the move
        board[row][col] = player;

        // check win condition
        bool win = true;

        // check row
        for (int i = 0; i < n; ++i) {
            if (board[i][col] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return player;
        }
        win = true;

        // check column
        for (int i = 0; i < n; ++i) {
            if (board[row][i] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return player;
        }

        // check main diagonol
        win = true;
        for (int i = 0; i < n; ++i) {
            if (board[i][i] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return player;
        }

        // check another diagonol
        win = true;
        for (int i = 0; i < n; ++i) {
            if (board[i][n - 1 - i] != player) {
                win = false;
                break;
            }
        }
        if (win) {
            return player;
        }
        return 0;
    }

private:

    vector<vector<int>> board;
    int n;
};
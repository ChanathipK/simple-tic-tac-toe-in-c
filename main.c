#include <stdio.h>
#include <stdlib.h>

int checkBoardStuck(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return -1;
            }
        }
    }
    return 1;
}

int checkUserWin(char board[3][3])
{
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] == board[i][2]) {
            if (board[i][0] == 'x') {
                return 0;
            } else if (board[i][0] == 'o') {
                return 1;
            }
        }

        if (board[0][i] == board[1][i] == board[2][i]) {
            if (board[0][i] == 'x') {
                return 0;
            } else if (board[0][i] == 'o') {
                return 1;
            }
        }
    }

    if (board[0][0] == board[1][1] == board[2][2]) {
        if (board[0][0] == 'x') {
            return 0;
        } else if (board[1][1] == 'o') {
            return 1;
        }
    }

    if (board[0][2] == board[1][1] == board[2][0]) {
        if (board[0][2] == 'x') {
            return 0;
        } else if (board[1][1] == 'o') {
            return 1;
        }
    }

    return -1;

}

void getUserInput(int *rowInput, int *columnInput)
{
    printf("Row: ");
    scanf("%d", &(*rowInput));
    printf("Column: ");
    scanf("%d", &(*columnInput));
    return;
}

void printBoard(char board[3][3])
{
    printf("  1 2 3\n");
    printf("1 %c %c %c\n", board[0][0], board[0][1], board[0][2]);
    printf("2 %c %c %c\n", board[1][0], board[1][1], board[1][2]);
    printf("3 %c %c %c\n\n", board[2][0], board[2][1], board[2][2]);
    return;
}

int main()
{
    char board[3][3] = {
        "---",
        "---",
        "---"
    };

    int s = 0;

    while (checkUserWin(board) == -1 && checkBoardStuck(board) == -1) {
        printBoard(board);
        int row, col;

        if (s == 0) {
            printf("X's turn\n");
        } else {
            printf("O's turn\n");
        }

        getUserInput(&row, &col);
        row--;
        col--;

        if (s == 0) {
            board[row][col] = 'x';
        } else {
            board[row][col] = 'o';
        }

        s += 1;
        s %= 2;
    }

    if (checkUserWin == 0) {
        printf("X won!\n");
    } else if (checkUserWin == 1) {
        printf("O won!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
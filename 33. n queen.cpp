#include <stdio.h>
#include <stdbool.h>

#define N 4

void print_solution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

bool is_safe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve_n_queens_util(int board[N][N], int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;

            if (solve_n_queens_util(board, col + 1))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

bool solve_n_queens() {
    int board[N][N] = {{0}};

    if (solve_n_queens_util(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }

    printf("Solution exists and is as follows:\n");
    print_solution(board);
    return true;
}

int main() {
    solve_n_queens();
    return 0;
}

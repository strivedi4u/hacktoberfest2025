#include <stdio.h>
#include <string.h>

#define N 4 // Size of the maze

// Function to check if the current cell is safe to visit
int isSafe(int maze[N][N], int x, int y, int visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && visited[x][y] == 0);
}

// Recursive function to find all paths from (0,0) to (N-1,N-1)
void findPaths(int maze[N][N], int x, int y, int visited[N][N], char path[], int pos) {
    // If destination is reached, print the path
    if (x == N - 1 && y == N - 1) {
        path[pos] = '\0';
        printf("%s\n", path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Move Down
    if (isSafe(maze, x + 1, y, visited)) {
        path[pos] = 'D';
        findPaths(maze, x + 1, y, visited, path, pos + 1);
    }

    // Move Right
    if (isSafe(maze, x, y + 1, visited)) {
        path[pos] = 'R';
        findPaths(maze, x, y + 1, visited, path, pos + 1);
    }

    // Move Up
    if (isSafe(maze, x - 1, y, visited)) {
        path[pos] = 'U';
        findPaths(maze, x - 1, y, visited, path, pos + 1);
    }

    // Move Left
    if (isSafe(maze, x, y - 1, visited)) {
        path[pos] = 'L';
        findPaths(maze, x, y - 1, visited, path, pos + 1);
    }

    // Backtrack: unmark the current cell as visited
    visited[x][y] = 0;
}

// Main function to initiate the rat in a maze problem
int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int visited[N][N];
    memset(visited, 0, sizeof(visited));

    char path[N * N]; // String to store the path
    printf("All possible paths are:\n");
    findPaths(maze, 0, 0, visited, path, 0);

    return 0;
}

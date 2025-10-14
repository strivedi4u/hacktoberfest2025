#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *right, *down, *left, *up;
    Node(int value) : data(value), right(nullptr), down(nullptr), left(nullptr), up(nullptr) {}
};
Node* arrayToLinkedMatrix(int matrix[][3], int rows, int cols) {
    // Create a matrix of Node pointers
    Node* head = nullptr; 
    Node* temp[rows][cols]; // To store the node pointers for easy linking
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = new Node(matrix[i][j]);
            if (i == 0 && j == 0) {
                head = temp[i][j]; // Save the head node
            }
            if (j > 0) {
                temp[i][j]->left = temp[i][j - 1];
                temp[i][j - 1]->right = temp[i][j];
            }
            if (i > 0) {
                temp[i][j]->up = temp[i - 1][j];
                temp[i - 1][j]->down = temp[i][j];
            }
        }
    }
    return head;
}
void printLinkedMatrix(Node* head, int rows, int cols) {
    Node* rowPtr = head;
    Node* colPtr = nullptr;
    for (int i = 0; i < rows; i++) {
        colPtr = rowPtr;
        for (int j = 0; j < cols; j++) {
            if (colPtr) {
                cout << colPtr->data << " ";
                colPtr = colPtr->right;
            }
        }
        cout << endl;
        if (rowPtr) {
            rowPtr = rowPtr->down;
        }
    }
}

int main() {
    int matrix[3][3] = { 
        { 1, 2, 3 }, 
        { 4, 5, 6 }, 
        { 7, 8, 9 } 
    };

    Node* linkedMatrix = arrayToLinkedMatrix(matrix, 3, 3);

    cout << "Linked List Matrix:" << endl;
    printLinkedMatrix(linkedMatrix, 3, 3);

    return 0;
}

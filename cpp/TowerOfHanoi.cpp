#include <iostream>

void towerOfHanoi(int n, const char from_rod, const char to_rod, const char aux_rod, int &moveCount) {
    if (n == 1) {
        std::cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << std::endl;
        moveCount++;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, moveCount);
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << std::endl;
    moveCount++;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, moveCount);
}

int main() {
    int n;
    std::cout << "Enter number of disks: ";
    std::cin >> n;

    int moveCount = 0;
    towerOfHanoi(n, 'A', 'C', 'B', moveCount);

    std::cout << "Total moves: " << moveCount << std::endl;
    return 0;
}

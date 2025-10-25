#include <iostream>

void printArrayUsingPointer(int* arr, int size) {
    // Iterate through the array using pointer arithmetic
    for (int i = 0; i < size; ++i) {
        std::cout << *(arr + i) << " "; // Dereference the pointer at (arr + i)
    }
    std::cout << std::endl;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array elements printed using a pointer: ";
    printArrayUsingPointer(numbers, size); // Pass the array (which decays to a pointer)

    // Another example: modifying a value using a pointer
    int value = 100;
    int* ptr = &value; // ptr points to the memory location of 'value'

    std::cout << "Initial value: " << value << std::endl;
    *ptr = 200; // Dereference ptr and assign a new value to the location it points to
    std::cout << "Modified value: " << value << std::endl;

    return 0;
}

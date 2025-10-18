#include <iostream>
// Bubble Sort by Mujeeb Arshad for Hacktoberfest 2025

void Bubble_Sort(int arr[], const int &size)
{
    int flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    int size = 10;
    int arr[size] = {5, 4, 3, 10, 9, 7, 8, 6, 1, 2};
    Bubble_Sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std ::cout << std::endl;
    return 0;
}
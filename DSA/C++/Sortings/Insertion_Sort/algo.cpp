#include <iostream>
// Insertion Sort by Mujeeb Arshad for Hacktoberfest 2025

void I_s(int arr[], const int &n)

{
    for (int i = 1; i < n; i++)
    {
        int x = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

int main()
{
    int arr[7] = {2, 3, 4, 5, 6, 7, 3};
    I_s(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
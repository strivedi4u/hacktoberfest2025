#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; i++) {
            result[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) 
            {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        return result;
    }
};

int main() 
{
    Solution s;
    int numRows;
    cout << "Number of rows: ";
    cin >> numRows;

    vector<vector<int>> triangle = s.generate(numRows);

    cout << "Pascal's Triangle:\n";
    for (const auto& row : triangle) 
    {
        for (int val : row) 
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}

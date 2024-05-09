/*  _____                                                                             _____  */
/* ( ___ )                                                                           ( ___ ) */
/*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |  */
/*  |   |                                                                             |   |  */
/*  |   |                                                                             |   |  */
/*  |   |    _   _                       ____                  ____   ___  _ ____     |   |  */
/*  |   |   | | | | __ _ _ __ _ __ _   _|  _ \  ___  _ __ ___ |___ \ / _ \/ |___ \    |   |  */
/*  |   |   | |_| |/ _` | '__| '__| | | | | | |/ _ \| '_ ` _ \  __) | (_) | | __) |   |   |  */
/*  |   |   |  _  | (_| | |  | |  | |_| | |_| | (_) | | | | | |/ __/ \__, | |/ __/    |   |  */
/*  |   |   |_| |_|\__,_|_|  |_|   \__, |____/ \___/|_| |_| |_|_____|  /_/|_|_____|   |   |  */
/*  |   |                          |___/                                              |   |  */
/*  |   |                                                                             |   |  */
/*  |   |                                                                             |   |  */
/*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|  */
/* (_____)                                                                           (_____) */

#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> heights(m, vector<int>(n, 0));
    int maxArea = 0;

    // Calculate the heights of each column up to the current row
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                heights[i][j] = (i == 0) ? 1 : heights[i - 1][j] + 1;
            }
        }
    }

    // Calculate the largest rectangle area for each row
    for (int i = 0; i < m; i++)
    {
        vector<int> left(n), right(n, n);

        // Calculate left boundary
        for (int j = 0; j < n; j++)
        {
            int k = j;
            while (k >= 0 && heights[i][k] >= heights[i][j])
            {
                k--;
            }
            left[j] = k + 1;
        }

        // Calculate right boundary
        for (int j = n - 1; j >= 0; j--)
        {
            int k = j;
            while (k < n && heights[i][k] >= heights[i][j])
            {
                k++;
            }
            right[j] = k;
        }

        // Calculate the area for each position
        for (int j = 0; j < n; j++)
        {
            maxArea = max(maxArea, heights[i][j] * (right[j] - left[j]));
        }
    }

    return maxArea;
}

int main()
{
    int m, n;
    // cout << "Enter the number of rows and columns of the matrix: ";
    cin >> m >> n;

    vector<vector<int>> matrix(n, vector<int>(m));
    // cout << "Enter the elements of the matrix (0 or 1):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << maximalRectangle(matrix) << endl;

    return 0;
}
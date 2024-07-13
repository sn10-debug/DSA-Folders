#include <iostream>

using namespace std;

int main()
{

    int n, m;

    cout << "Enter the Order of the Matrix : ";

    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {

        cout << "Enter the elements for the row " << i + 1 << " separated with space : ";
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    int bottom = n - 1;
    int top = 0;
    int left = 0;
    int right = m - 1;

    while (bottom > top)
    {

        for (int i = left; i <= right; i++)
        {

            cout << arr[top][i] << " ";
        }

        top++;

        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }

        right--;

        for (int i = right; i >= left; i--)
        {

            cout << arr[bottom][i] << " ";
        }

        bottom--;

        for (int i = bottom; i >= top; i--)
        {
            cout << arr[i][left] << " ";
        }

        left++;
    }

    return 0;
}
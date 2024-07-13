#include <iostream>

using namespace std;

int main()
{

    int n, m;

    cout << "Enter the order of the Matrix : ";
    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {

        cout << "Enter the elements for the row " << i + 1 << " separated with space : ";
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (i == j)
                continue;

            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m / 2; j++)
        {
            int temp = arr[i][j];

            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    cout << "Rotated Matrix : " << endl;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
    return 0;
}
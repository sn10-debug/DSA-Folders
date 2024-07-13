#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    int m;

    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    int t[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {

        for (int j = 0; j < m + 1; j++)
        {

            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {

        for (int j = 1; j < m + 1; j++)
        {

            t[i][j] = arr[i - 1][j - 1] + max(t[i - 1][j], t[i][j - 1]);
        }
    }

    int max_num = arr[n - 1][m - 1];

    int i = n, j = m;

    while (i != 0 && j != 0)
    {

        if (arr[i - 1][j - 1] > max_num)
            max_num = arr[i - 1][j - 1];

        if (t[i - 1][j] > t[i][j - 1])
        {
            i--;
        }
        else
        {

            j--;
        }
    }

    cout << "The Maximum QR Codes will be " << t[n][m] + max_num << endl;

    return 0;
}
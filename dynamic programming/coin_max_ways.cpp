#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cout << "Enter the Number of coins : ";
    cin >> n;

    int arr[n];

    cout << "Enter the value of coins separated with space : ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum_num;

    cout << "Enter the required value of amount : ";

    cin >> sum_num;

    int t[n + 1][sum_num + 1];

    for (int i = 0; i < n + 1; i++)
    {

        for (int j = 0; j < sum_num + 1; j++)
        {

            if (j == 0)
                t[i][j] = 1;
            else if (i == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {

        for (int j = 1; j < sum_num + 1; j++)
        {

            if (j >= arr[i - 1])
            {
                t[i][j] = t[i - 1][j] + t[i][j - arr[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    cout << "Total Number of Ways : " << t[n][sum_num] << endl;

    return 0;
}
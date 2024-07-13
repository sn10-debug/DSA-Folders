#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    int sum_num;

    cout << "Enter the Number of Elements : ";
    cin >> n;

    cout << "Enter the elements separated with space : ";
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the required sum : ";
    cin >> sum_num;

    bool t[n + 1][sum_num + 1];

    for (int i = 0; i < n + 1; i++)
    {

        for (int j = 0; j < sum_num + 1; j++)
        {

            if (j == 0)
                t[i][j] = true;

            else if (i == 0)
                t[i][j] = false;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {

        for (int j = 1; j < sum_num + 1; j++)
        {

            if (j >= arr[i - 1])
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    cout << "Subset Sum Possibility : " << t[n][sum_num];
    return 0;
}
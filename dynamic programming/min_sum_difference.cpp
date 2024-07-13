#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cout << "Enter the Number of Elements : ";
    cin >> n;

    cout << "Enter the elements separated with space : ";
    int arr[n];

    int sum_num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum_num += arr[i];
    }

    int max_num = 0;

    for (int k = 1; k < sum_num / 2 + 1; k++)
    {

        bool t[n + 1][k + 1];

        for (int i = 0; i < n + 1; i++)
        {

            for (int j = 0; j < k + 1; j++)
            {

                if (j == 0)
                    t[i][j] = true;

                else if (i == 0)
                    t[i][j] = false;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {

            for (int j = 1; j < k + 1; j++)
            {

                if (j >= arr[i - 1])
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        if (t[n][k])
        {
            if (k > max_num)
                max_num = k;
        }
    }

    cout << "Minimum Difference : " << sum_num - 2 * max_num << endl;
    return 0;
}
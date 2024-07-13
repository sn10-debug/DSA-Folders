#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cout << "Enter the Number of Elements in the Array : ";

    cin >> n;

    int arr[n];

    int range = 0;

    cout << "Enter the elements separated with space : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        range += arr[i];
    }
    cout << "Enter the Difference for the subset to be found : ";

    int diff;
    cin >> diff;

    int sum_num = (range - diff) / 2;

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

            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    cout << "Count of Possible Subsets : " << t[n][sum_num] << endl;

    return 0;
}
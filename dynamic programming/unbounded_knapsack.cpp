#include <iostream>

using namespace std;

int main()
{

    int n;

    cout << "Enter the number of items : ";
    cin >> n;

    int wt[n];
    int val[n];

    cout << "Enter the weight of items separated with space : ";

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter the profit associated with the items separated with space : ";

    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter the Knapsack weight : ";
    int knap_weight;
    cin >> knap_weight;

    int t[n + 1][knap_weight + 1];

    for (int i = 0; i < n + 1; i++)
    {

        for (int j = 0; j < knap_weight + 1; i++)
        {

            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
                t[i][j] = -1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {

        for (int j = 1; j < knap_weight + 1; j++)
        {

            if (wt[i - 1] <= j)
            {

                t[i][j] = max(t[i - 1][j], max(val[i - 1] + t[i][j - wt[i - 1]], t[i][j]));
            }
            else
            {

                t[i][j] = t[i - 1][j];
            }
        }
    }

    return 0;
}
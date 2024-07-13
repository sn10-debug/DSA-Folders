#include <bits/stdc++.h>

using namespace std;

int main()
{

    string x;
    string y;

    cout << "Enter the String 1 : ";
    cin >> x;

    cout << "Enter the String 2 : ";
    cin >> y;

    int m = x.size();
    int n = y.size();

    int t[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
    {

        for (int j = 0; j < n + 1; j++)
        {

            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {

        for (int j = 1; j < n + 1; j++)
        {

            if (i == j && x.at(i - 1) == y.at(j - 1))
            {

                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {

                t[i][j] = 0;
            }
        }
    }

    int max_length = 0;

    for (int i = 0; i < m + 1; i++)
    {
        if (t[i][i] > max_length)
            max_length = t[i][i];
    }
    cout << "Longest Common SubString Length is " << max_length << endl;

      return 0;
}
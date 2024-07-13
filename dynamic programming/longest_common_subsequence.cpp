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

            if (x.at(i - 1) == y.at(j - 1))
            {

                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {

                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    cout << "Longest Common Subsequence Length is " << t[m][n] << endl;

    int i = m, j = n;
    stack<char> chr;
    while (!(i == 0 || j == 0))
    {

        if (x[i - 1] == y[j - 1])
        {
            chr.push(x[i - 1]);
            i--;
            j--;
        }
        else
        {

            if (t[i - 1][j] > t[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    while (!chr.empty())
    {
        cout << chr.top();
        chr.pop();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int firstOccurence(string a, string b)
{

    int m = a.size();
    int n = b.size();

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

            if (a.at(i - 1) == b.at(j - 1))
            {

                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {

                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    int firstOccurenceIndex = -1;

    for (int i = 1; i <= n; i++)
    {

        if (t[i][1] == 1)
        {

            firstOccurenceIndex = i;
            break;
        }
    }

    if (t[m][n] == b.size())
        return firstOccurenceIndex;
    else if (t[m][n] == b.size() - 1)
    {

        return firstOccurenceIndex;
    }
    else
    {

        return -1;
    }
}

int main()
{

    return 0;
}
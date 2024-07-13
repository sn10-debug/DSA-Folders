#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int numRows;
    cin >> numRows;
    vector<vector<int>> x{};
    for (int i = 0; i < numRows; i++)
    {
        vector<int> y{};
        if (i == 0)
        {
            y.push_back(1);
            x.push_back(y);
            continue;
        }
        else
        {

            for (int j = 0; j < i + 1; j++)
            {
                if ((j - 1) < 0)
                {
                    y.push_back(x.at(i - 1).at(j));

                    continue;
                }
                if (j == i)
                {
                    y.push_back(x.at(i - 1).at(j - 1));
                    continue;
                }

                y.push_back(x.at(i - 1).at(j - 1) + x.at(i - 1).at(j));
            }
            x.push_back(y);
        }
    }

    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < x.at(i).size(); j++)
        {
            cout << x.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n, m;

    cout << "Enter the Order of the Matrix separated with space ";

    cin >> n >> m;

    int arr[n][m];

    for (int i = 0; i < n; i++)
    {

        cout << "Enter the elements separated with space for row " << i + 1 << " : ";
        for (int j = 0; j < m; j++)
        {

            cin >> arr[i][j];
        }
    }

    int col0 = 1;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == 0)
            {

                if (j == 0)
                    col0 = 0;
                else
                    arr[0][j] = 0;
                arr[i][0] = 0;
            }
        }
    }

    // Going columnwise

    for (int i = 1; i < m; i++)
    {

        bool status = false;
        if (i == 0)
        {
            if (col0 == 0)
                status = true;
        }
        else
        {

            if (arr[0][i] == 0)
                status = true;
        }

        if (status)
        {

            for (int j = 0; j < n; j++)
            {

                arr[j][i] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {

        bool status = false;

        if (arr[i][0] == 0)
            status = true;

        if (status)
        {

            for (int j = 1; j < m; j++)
            {

                arr[i][j] = 0;
            }
        }
    }

    // Now update the Data Elements

    if (arr[0][0] == 0)
    {

        for (int i = 1; i < m; i++)
            arr[0][i] = 0;
    }

    if (col0 == 0)
    {

        for (int i = 0; i < n; i++)
        {
            arr[i][0] = 0;
        }
    }

    cout << "Latest Matrix :" << endl;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}
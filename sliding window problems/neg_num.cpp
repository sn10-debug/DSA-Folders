#include <iostream>
#include <queue>

using namespace std;

int main()
{

    int n;

    cout << "Enter the size :";
    cin >> n;
    cout << "Enter the numbers separated with space : ";
    int arr[n];

    int k;

    vector<int> nums;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the window size :";
    cin >> k;

    int i = 0, j = 0;

    queue<int> q;

    while (j < n)
    {

        if (j - i + 1 < k)
        {

            if (arr[j] < 0)
                q.push(arr[j]);
        }
        else if (j - i + 1 == k)
        {
            if (arr[j] < 0)
                q.push(arr[j]);

            if (!q.empty())
            {

                nums.push_back(q.front());
            }
            else
            {

                nums.push_back(0);
            }

            if (arr[i] < 0)
                q.pop();

            i++;
        }

        j++;
    }

    for (int k = 0; k < nums.size(); k++)
    {

        cout << nums.at(k) << " ";
    }

    cout << endl;

    return 0;
}
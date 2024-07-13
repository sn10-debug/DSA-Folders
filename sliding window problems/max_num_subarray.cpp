#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main()
{

    int n;
    cout << "Enter the Size of the Array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements separated with space : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the Window Size : ";
    int k;
    cin >> k;

    // queue<int> max_num;

    list<int> max_num;

    int i = 0, j = 0;

    while (j < n)
    {

        while (!max_num.empty() && arr[j] > max_num.back())
        {
            max_num.pop_back();
        }

        max_num.push_back(arr[j]);

        if (j - i + 1 == k)
        {

            if (!max_num.empty())
                cout << max_num.front() << " ";

            if (arr[i] == max_num.front())
                max_num.pop_front();

            i++;
        }

        j++;
    }

    return 0;
}
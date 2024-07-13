#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cout << "Enter the Number of Elements in the Array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements separated with space : ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<int, vector<int>, greater<int>> minHeap;

    int k;
    cout << "Enter the value of K : ";
    cin >> k;

    int j = 0;
    int heap_size = 0;

    while (j < n)
    {

        if (heap_size < k)
        {
            minHeap.push(arr[j]);
            heap_size++;
        }
        else
        {

            if (arr[j] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(arr[j]);
            }
        }

        j++;
    }

    cout << k << "th Largest Element : " << minHeap.top() << endl;

    return 0;
}
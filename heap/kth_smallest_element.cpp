#include <iostream>
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

    priority_queue<int> maxHeap;

    int k;
    cout << "Enter the value of K : ";
    cin >> k;

    int j = 0;
    int heap_size = 0;

    while (j < n)
    {

        if (heap_size < k)
        {
            maxHeap.push(arr[j]);
            heap_size++;
        }
        else
        {

            if (arr[j] < maxHeap.top())
            {
                maxHeap.pop();
                maxHeap.push(arr[j]);
            }
        }
        j++;
    }

    cout << k << "th Smallest Element : " << maxHeap.top() << endl;

    return 0;
}
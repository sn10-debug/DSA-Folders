#include <iostream>

using namespace std;

int findMin(int arr[], int n)
{

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
            return mid;
        else if (arr[mid] > arr[end])
            start = mid + 1;
        else
            end = mid - 1;
    }
}

int main()
{

    int n;

    cout << "Enter the Size of the Array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the rotated Array separated with space : ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int index = findMin(arr, n);

    cout << "Number of Rotations : " << n - index << endl;

    return 0;
}
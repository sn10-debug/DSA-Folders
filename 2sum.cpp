#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{

    int n;
    cout << "Enter the length of the array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the numbers separated with space : ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter the target : ";
    cin >> target;

    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];

        if (umap.count(complement) > 0)
        {
            cout << "( " << umap[complement] << "," << i << " )" << endl;
            break;
        }
        umap[arr[i]] = i;
    }

    return 0;
}
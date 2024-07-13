#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int find_max(int arr[], int n, bool bought)
{
    if (n == 0)
        return 0;
    if (bought)
        return max(-arr[n] + find_max(arr, n - 1, false), find_max(arr, n - 1, true));
    else
        return max(arr[n] + find_max(arr, n - 1, true), find_max(arr, n - 1, false));
}

int main()
{

    int n;
    class Solution
    {
    public:
        int find_max(vector<int> arr, int index, int n, bool bought)
        {
            if (index >= n)
                return 0;
            if (bought)
                return max(arr.at(index) + find_max(arr, index + 1, n, false), find_max(arr, index + 1, n, true));
            else
                return max(-arr.at(index) + find_max(arr, index + 1, n, true), find_max(arr, index + 1, n, false));
        }
        int maxProfit(vector<int> &prices)
        {

            return find_max(prices, 0, prices.size(), false);
        }
    };
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    return 0;
}
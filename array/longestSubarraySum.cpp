#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{

    int n;
    cout << "Enter the number of elements in the Array : ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements separated with space : ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;

    cout << "Enter the required Sum : ";
    cin >> k;

    // sum,index
    unordered_map<int, int> sum_mappings;

    int j = 0;

    int sum_nums = 0;
    int count = 0;
    while (j < n)
    {

        sum_nums += arr[j];

        if (sum_nums == k)
            count++;
        else
        {
            int rem_value = sum_nums - k;

            if (sum_mappings.find(rem_value) != sum_mappings.end())
                count++;
        }
        sum_mappings[sum_nums] = j;

        j++;
    }

    cout << "Number of Subarrays : " << count << endl;

    return 0;
}
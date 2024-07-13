#include <iostream>

using namespace std;

int main()
{

    int n;

    cout << "Enter the number of elements in the array ";
    cin >> n;
    cout << "Enter the elements separated with space :";

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the sum required : ";
    int sum_required;
    cin >> sum_required;

    int count = 0;

    int i = 0, j = 0;

    int sum_nums = 0;

    int neg_sum = 0;

    for (int k = 0; k < n; k++)
    {
        if (arr[k] < 0)
            neg_sum += arr[k];
    }
    while (j < n)
    {

        sum_nums += arr[j];

        if (sum_nums == sum_required)
        {
            count++;
        }
        else if (sum_nums > sum_required)
        {

            if (sum_nums + neg_sum <= 0)
                continue;
            while (sum_nums > sum_required)
            {
                sum_nums -= arr[i];
                i++;

                if (sum_nums == sum_required)
                    count++;
            }
        }

        j++;
    }

    cout << count << endl;

    return 0;
}
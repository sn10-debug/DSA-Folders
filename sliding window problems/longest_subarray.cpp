#include <iostream>

using namespace std;

int main()
{

    int n;
    cout << "Enter the Size of the Array :";
    cin >> n;

    int arr[n];

    cout << "Enter the " << n << " elements separated with space : ";

    for (int k = 0; k < n; k++)
        cin >> arr[k];

    int sum_required;

    cout << "Enter the Sum of the Subarray : ";
    cin >> sum_required;

    int i = 0, j = 0;

    int sum_nums = 0;
    int max_length = 0;

    while (j < n)
    {

        sum_nums += arr[j];

        if (sum_nums == sum_required)
        {

            if (j - i + 1 > max_length)
                max_length = j - i + 1;
        }
        else if (sum_nums > sum_required)
        {

            while (sum_nums > sum_required)
            {

                sum_nums -= arr[i];
                i++;
                if (sum_nums == sum_required)
                {
                    if (j - i + 1 > max_length)
                        max_length = j - i + 1;
                }
            }
        }

        j++;
    }

    cout << "Max Length : " << max_length << endl;

    return 0;
}
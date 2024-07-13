#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{

    string s1;
    cout << "Enter the String : ";
    cin >> s1;

    int k;

    cout << "Enter the number of unique Characters : ";
    cin >> k;

    unordered_map<char, int> char_map;
    int i = 0, j = 0;
    int max_length = 0;

    while (j < s1.size())
    {

        if (char_map.find(s1.at(j)) == char_map.end())
            char_map[s1.at(j)] = 1;
        else
            char_map[s1.at(j)]++;

        if (char_map.size() == k)
        {

            if (j - i + 1 > max_length)
                max_length = j - i + 1;
        }

        if (char_map.size() > k)
        {

            // Check if any zero

            while (char_map.size() > k)
            {
                char_map[s1.at(i)]--;

                if (char_map[s1.at(i)] == 0)
                    char_map.erase(s1.at(i));

                i++;

                if (char_map.size() == k)
                {

                    if (j - i + 1 > max_length)
                        max_length = j - i + 1;
                }
            }
        }

        j++;
    }
    cout << "Max Length with Unique Character : " << max_length << endl;
    return 0;
}
#include <iostream>
#include <string.h>
#include <unordered_map>

using namespace std;

int main()
{

    cout << "Code to find the Anagrams " << endl;
    string s1;
    cout << "Enter the Main string : ";
    cin >> s1;
    string s2;
    cout << "Enter the Sub-String : ";
    cin >> s2;

    int i = 0, j = 0;

    int string_size = s1.size();

    unordered_map<char, int> subStringMapping;
    int count = 0;

    for (int k = 0; k < s2.size(); k++)
    {
        if (subStringMapping.find(s2.at(k)) == subStringMapping.end())
        {
            count++;

            subStringMapping[s2.at(k)] = 1;
        }
        else
        {
            subStringMapping[s2.at(k)]++;
        }
    }

    int ans = 0;
    while (j < string_size)
    {

        if (subStringMapping.find(s1.at(j)) != subStringMapping.end())
        {
            subStringMapping[s1.at(j)]--;
            if (subStringMapping[s1.at(j)] == 0)
                count--;
        }

        if (j - i + 1 == s2.size())
        {

            if (count == 0)
                ans++;

            if (subStringMapping.find(s1.at(j)) != subStringMapping.end())
            {
                if (subStringMapping[s1.at(j)] == 0)
                    count++;
                subStringMapping[s1.at(j)]++;
            }

            i++;
        }
        j++;
    }

    return 0;
}
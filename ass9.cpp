#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string canTransform(string s1, string s2)
{
    int i = 0, j = 0;

    while (i < s1.length() && j < s2.length())
    {
        char c1 = s1[i];
        char c2 = s2[j];

        // If characters are same
        if (c1 == c2)
        {
            i++;
            j++;
        }

        // If lowercase can be converted to uppercase
        else if (islower(c1) && toupper(c1) == c2)
        {
            i++;
            j++;
        }

        // If lowercase character can be deleted
        else if (islower(c1))
        {
            i++;
        }

        // Uppercase character cannot be deleted
        else
        {
            return "NO";
        }
    }

    // Remaining lowercase characters can be deleted
    while (i < s1.length())
    {
        if (isupper(s1[i]))
        {
            return "NO";
        }

        i++;
    }

    // s2 should be completely matched
    if (j == s2.length())
        return "YES";

    return "NO";
}

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    cout << canTransform(s1, s2);

    return 0;
}
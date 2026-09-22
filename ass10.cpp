#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    set<vector<int>> subsets;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> subset;

        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                subset.push_back(arr[i]);
            }
        }

        // Store distinct subset
        subsets.insert(subset);

        // Print mask and subset
        cout << "Mask " << mask << " : { ";

        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }

        cout << "}" << endl;
    }

    cout << "\nDistinct subsets are:\n";

    for (auto subset : subsets)
    {
        cout << "{ ";

        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }

        cout << "}\n";
    }

    return 0;
}
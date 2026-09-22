#include <iostream>
using namespace std;

bool findSubset(int arr[], int n, int sum, int result[], int &count)
{
    bool dp[100][1001];

    // Sum 0 is always possible
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // No elements cannot form a positive sum
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    // Create DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] ||
                            dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // No subset found
    if (!dp[n][sum])
        return false;

    // Find one subset
    int i = n;
    int j = sum;

    count = 0;

    while (i > 0 && j > 0)
    {
        if (dp[i - 1][j])
        {
            // Element not selected
            i--;
        }
        else
        {
            // Element selected
            result[count++] = arr[i - 1];
            j = j - arr[i - 1];
            i--;
        }
    }

    return true;
}

int main()
{
    int n, sum;
    int arr[100];
    int result[100];
    int count = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter required sum: ";
    cin >> sum;

    bool found = findSubset(arr, n, sum, result, count);

    cout << endl;

    cout << "Numbers: [";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];

        if (i != n - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    cout << "Required Sum: " << sum << endl;

    if (found)
    {
        cout << "Subset: ";

        for (int i = count - 1; i >= 0; i--)
        {
            cout << result[i];

            if (i != 0)
                cout << " + ";
        }

        cout << endl;
        cout << "Answer: YES" << endl;
    }
    else
    {
        cout << "Subset: -" << endl;
        cout << "Answer: NO" << endl;
    }

    return 0;
}
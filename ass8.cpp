//assignment 8:

#include <iostream>
using namespace std;

int main()
{
    int coins[100], n, sum;
    int countWays = 0;

    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter sum: ";
    cin >> sum;

    cout << "\nPossible ways:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (coins[i] + coins[j] == sum)
            {
                cout << coins[i] << "+" << coins[j] << endl;
                countWays++;
            }
        }
    }

    cout << "\nNumber of ways = " << countWays << endl;

    return 0;
}
/* Assignment 5: maximize profit by trading stocks */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int price[n];

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++)
        cin >> price[i];

    int maxPrice = price[n - 1];
    int profit = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (price[i] > maxPrice)
        {
            maxPrice = price[i];
        }
        else
        {
            profit = profit + (maxPrice - price[i]);
        }
    }

    cout << "Maximum Profit = " << profit;

    return 0;
}
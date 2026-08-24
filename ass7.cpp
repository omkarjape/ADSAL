// Assignment 7: Coin change problem
// Statement: Given an integer array of coin denominations and an integer sum, determine the minimum number of ways to make the given sum using different combinations of the coin.
// we can use any number of coins of each denomination.
// we have show all posible combinations of coins that can make the given sum.

#include <iostream>
#include <vector>
using namespace std;

int t = 0;

void findCombinations(vector<int>& coins, int sum, vector<int>& combination, int start) {
    if (sum == 0) {
        t++;
        cout << "Combination " << t << ": ";
        for (int coin : combination) {
            cout << coin << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i < coins.size(); i++) {
        if (coins[i] <= sum) {
            combination.push_back(coins[i]);
            findCombinations(coins, sum - coins[i], combination, i); // Allow unlimited use of the same coin
            combination.pop_back();
        }
    }
}

int main() {

    while(true){
        t = 0; // Reset the combination counter for each new input
        int n, sum;
        cout << "Enter the number of coin denominations: ";
        cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter the target sum: ";
    cin >> sum;

    vector<int> combination;
    cout << "All possible combinations to make the sum " << sum << " are:\n";
    findCombinations(coins, sum, combination, 0);
    cout << "Total combinations found: " << t << endl;
    }

    return 0;
}
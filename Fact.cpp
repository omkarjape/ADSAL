#include <iostream>
using namespace std;


int countTrailingZeroes(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 5;
        count = count + n;
    }
    return count;
}


int findNum(int n)
{
    int low = 0;
    int high = 5 * n;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (countTrailingZeroes(mid) >= n)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int n;

    cout << "Enter required trailing zeroes: ";
    cin >> n;

    cout << "Smallest number is: " << findNum(n);

    return 0;
}
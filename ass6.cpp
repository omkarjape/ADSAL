#include <iostream>
using namespace std;

int main()
{
    int n, days;

    cout << "Enter number of tasks: ";
    cin >> n;

    int arr[n];
    cout << "Enter work: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "No of days: ";
    cin >> days;

    int low = arr[0];
    int high = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > low)
            low = arr[i];

        high = high + arr[i];
    }

    int ans = high;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        int day = 1;
        int work = 0;

        for(int i = 0; i < n; i++)
        {
            if(work + arr[i] <= mid)
            {
                work = work + arr[i];
            }
            else
            {
                day++;
                work = arr[i];
            }
        }

        if(day <= days)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "Minimum work per day = " << ans;

    return 0;
}
// Assignment 6: minimum work per day to finish task in d days

/* This program calculates the minimum amount of work that needs to be done per day in order to complete a set of tasks within 
   a specified number of days. It uses a binary search approach to find the optimal solution.*/

#include<iostream>
using namespace std;

int main()
{
    int n, d;
    cout<<"Enter the number of days: ";
    cin>>d;
    cout<<"Enter the number of tasks: ";
    cin>>n;
    int task[n];
    for(int i=0; i<n; i++){
        cout<<"Task ["<<i<<"] :";
        cin>>task[i];
    }
    
    int low = task[0];
    int high = 0;
    for(int i=0; i<n; i++){
        if(task[i] > low)
            low = task[i];
        high += task[i];
    }

    int ans = high;
    while(low <= high){
        int mid = (low + high) / 2;
        int days = 1;
        int work = 0;

        for(int i=0; i<n; i++){
            if(work + task[i] <= mid){
                work += task[i];
            }
            else{
                days++;
                work = task[i];
            }
        }

        if(days <= d){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout<<"Minimum work per day = "<<ans;

    return 0;
}
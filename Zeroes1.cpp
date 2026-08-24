#include <iostream>
using namespace std;
void countzero(int arr[], int n)
{

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    int low = 0;
    int high = n - 1;
    int firstzero = n;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == 0)
        {
            firstzero = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout<<"Number of Zero's: "<< n - firstzero<<endl;
}
int main()
{
    int size;
    cout << "enter array's size:";
    cin >> size;
    int arr[size];
    cout << "enter array elements:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    countzero(arr, size);
    return 0;
} 
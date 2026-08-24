#include <iostream>
using namespace std;
int temp = -1;

void merge(int arr[], int low, int heigh){
    if(heigh<=low){
        int mid = (low + heigh)/2;
        merge(arr, low, mid);
        merge(arr, mid+1, heigh);
        for(int i=low; i<= mid; i++){
            for(int j=mid+1;j<=heigh;j++){
                if(arr[i]>arr[j]){
                    temp = arr[i];
                    for(int x = i; x<j; x++){
                        arr[x]=arr[x+1];
                    }
                    arr[j]=temp;
                }
            }
        }
    }
    
}


void countzero(int arr[], int n)
{
    
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
    merge(arr, 0, size-1);
    
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
   // countzero(arr, size);
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

struct Visitor
{
    string name;
    int start=0;
    int end=0;
};

struct Shop
{
    string name;
    int start=0;
    int end=0;
    Visitor visitor;
    bool visited = false;
};

void  MaxShops(Shop shops[], Visitor visitors[], int n, int k)
{
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(shops[j].end < shops[i].end)
            {
                Shop temp = shops[j];
                shops[j] = shops[i];
                shops[i] = temp;
            }
        }
    }
    int count = 0, i = 0, j = 0;


    shops[i].visited = true;
    visitors[j].start = shops[i].start;
    visitors[j].end = shops[i].end;
    shops[i].visitor = visitors[j];
    count++, i++;


    while(i<n)
    {
        if(!shops[i].visited){
            j=0;
            while(j<k){
                if(visitors[j].end <= shops[i].start){
                    shops[i].visited = true;
                    visitors[j].start = shops[i].start;
                    visitors[j].end = shops[i].end;
                    shops[i].visitor = visitors[j];
                    count++;
                    break;
                }
                j++;
            }
        }
        i++;
    }

    for(int i =0;i<n;i++){
        if(shops[i].visited){
            cout<<shops[i].name<<"  -  "<<shops[i].visitor.name<<endl;
        }
    }

    cout << "Maximum number of shops that can be visited: "<<count;
}

int main()
{
    int n, k;
    cout << "Enter number of shops: ";
    cin >> n;
    cout << "Enter number of visitors: ";
    cin >> k;

    Shop shops[n];
    Visitor visitors[k];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter name of shop " << i + 1 << ": ";
        cin >> shops[i].name;
        cout << "Enter start time of shop " << i + 1 << ": ";
        cin >> shops[i].start;
        cout << "Enter end time of shop " << i + 1 << ": ";
        cin >> shops[i].end;
    }
    
    for(int i = 0; i < k; i++)
    {
        cout << "Enter name of visitor " << i + 1 << ": ";
        cin >> visitors[i].name;
    }

    MaxShops(shops, visitors, n, k);
    return 0;
}
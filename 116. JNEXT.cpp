#include<bits/stdc++.h>
using namespace std;

//This is a special algorithm specifically made to find the next closest greater element in O(n), can be modified to find the closest next smaller element

//defined my macro functions
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

//defined my macro strings
#define ENDL "\n"
#define SPACE " "

//defined my constants
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 3.14159265358979323846;

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        int pivot;
        for(pivot = n - 1; pivot > 0 && arr[pivot - 1] >= arr[pivot]; pivot--);
        if(pivot == 0)
        {
            cout<<-1<<endl;
            continue;
        }
        pivot--;
        int swapplace;
        for(swapplace = n - 1; swapplace > pivot && arr[pivot] >= arr[swapplace]; swapplace--);
//        cout<<pivot<<" "<<swapplace<<endl;
//        int temp = arr[swapplace];
//        arr[swapplace] = arr[pivot];
//        arr[pivot] = temp;
        swap(arr[pivot], arr[swapplace]);
        for(int i = 0; i <= pivot; i++) cout<<arr[i];
        for(int i = n - 1; i > pivot; i--) cout<< arr[i];
        cout<<endl;
    }

    return 0;
}

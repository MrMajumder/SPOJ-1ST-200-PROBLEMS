#include<bits/stdc++.h>
using namespace std;

//defined my macro functions
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

//defined my macro strings
#define ENDL "\n"
#define SPACE " "

//defined my constants
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007; //9digits
const double EPS = 1e-8;
const long double EULER = 2.71828182845904523536;   //20digits
const long double PI = 3.14159265358979323846;      //20digits
//float = 7digits, double = 15digits, long double = 21 digits precision

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

bool isDone(int arr[], int n)
{
    for(int i = 1; i < n; i++) if(arr[0] != arr[i]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n, extra;
        cin>>n>>extra;
        int arr[n + extra] = {0};
        int start[n + 1] = {0};
        for(int i = 0; i < n; i++) cin>>arr[i];

        int counter = n;
        while(!isDone(arr, counter))
        {
            start[counter--] = arr[0];
            for(int i = 0; i < counter; i++) arr[i] = arr[i + 1] - arr[i];
        }
        for(int i = 0; i < extra; i++) arr[i + counter] = arr[0];
        int hold, temp;
        while(counter < n)
        {
            hold = arr[0];
            arr[0] = start[counter + 1];
            for(int i = 1; i <= counter + extra; i++)
            {
                temp = hold + arr[i - 1];
                hold = arr[i];
                arr[i] = temp;
            }
            counter++;
        }
        for(int i = 0; i < extra; i++) cout<<arr[n + i]<<SPACE;
        cout<<endl;
    }

    return 0;
}


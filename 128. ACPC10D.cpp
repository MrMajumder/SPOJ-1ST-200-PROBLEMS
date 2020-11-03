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

    int n, counter = 1;
    cin>>n;
    while(n != 0)
    {
        int arr[n][3];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 3; j++) cin>>arr[i][j];
        }
        arr[0][2] += arr[0][1];
        arr[0][0] = INF;
        for(int i = 1; i < n; i++)
        {
            arr[i][0] += min(arr[i - 1][0], arr[i - 1][1]);
            arr[i][1] += min(arr[i - 1][0], min(arr[i - 1][1], min(arr[i - 1][2], arr[i][0])));
            arr[i][2] += min(arr[i - 1][1], min(arr[i - 1][2], arr[i][1]));
        }
        cout<<counter++<<". "<<arr[n - 1][1]<<endl;
        cin>>n;
    }

    return 0;
}


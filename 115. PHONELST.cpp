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

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        sort(arr, arr + n);

        bool found = false;
        string temp = arr[0];

        for(int i = 1; i < n; i++)
        {
            int len = temp.length();
            string now = arr[i].substr(0, len);
            if(now == temp)
            {
                found = true;
                cout<<"NO"<<endl;
                break;
            }
            temp = arr[i];
        }
        if(!found) cout<<"YES"<<endl;
    }

    return 0;
}


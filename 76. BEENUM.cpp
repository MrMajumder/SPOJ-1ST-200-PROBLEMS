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

    ll x;
    cin>>x;

    while(x != -1)
    {
        long double res = sqrt((12 * x) - 3);
        //cout<<res<<" "<<floor(res)<<endl;
        if(res == floor(res)) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
        cin>>x;
    }


    return 0;
}


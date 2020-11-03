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

    int half, quarter, quarter3;
    half = quarter = quarter3 = 0;
    while(t--)
    {
        string s;
        cin>>s;
        if(s == "1/4") quarter++;
        if(s == "1/2") half++;
        if(s == "3/4") quarter3++;
    }


    int pizza = 1 + quarter3 + ceil(double(half / 2.0));
    quarter -= quarter3 + ((half % 2) ? 2 : 0);
    if(quarter > 0) pizza += ceil(double(quarter / 4.0));
    cout<<pizza<<endl;

    return 0;
}



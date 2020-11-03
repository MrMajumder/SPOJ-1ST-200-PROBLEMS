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

int primefactor[10000000 + 1] = {0};
ll sequence[10000000 + 1] = {0};

void precalc(int n)
{
    for(int i = 2; i < n; i++)
    {
        if(primefactor[i] == 0)
        {
            for(int j = i; j < n; j += i)
            {
                if(primefactor[j] == 0) primefactor[j] = i;
            }
        }
    }

    sequence[0] = sequence[1] = 0;
    for(int i = 2; i <= n; i++) sequence[i] = sequence[i - 1] + primefactor[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalc(10000000 + 5);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<sequence[n]<<endl;
    }

    return 0;
}


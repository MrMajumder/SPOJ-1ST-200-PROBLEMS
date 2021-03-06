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

    int have[4];
    int need[4];
    for(int i = 0; i < 4; i++) cin>>have[i];
    for(int i = 0; i < 4; i++) cin>>need[i];

    while(have[0] != -1)
    {
        int maxneed = 0;
        for(int i = 0; i < 4; i++)
        {
            maxneed = max(maxneed, (int)ceil(have[i] * 1.0 / need[i]));
        }
        for(int i = 0; i < 4; i++) cout<< (maxneed * need[i]) - have[i]<<SPACE;
        cout<<endl;
        for(int i = 0; i < 4; i++) cin>>have[i];
        for(int i = 0; i < 4; i++) cin>>need[i];
    }

    return 0;
}


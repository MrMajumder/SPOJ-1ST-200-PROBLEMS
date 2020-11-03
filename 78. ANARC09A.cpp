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

    string line;
    cin>>line;

    int l, r, len, tally = 0;

    while(line[0] != '-')
    {
        tally++;
        len = line.length();
        l = r = 0;

        for(int i = 0; i < len; i++)
        {
            if(line[i] == '}')
            {
                if(l) l--;
                else r++;
            }
            else if(line[i] == '{') l++;
        }
        cout<<tally<<". "<<((l>>1) + (r>>1) + (l&1) + (r&1))<<endl;

        cin>>line;
    }

    return 0;
}


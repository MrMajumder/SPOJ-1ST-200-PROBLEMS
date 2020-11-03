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

bool mycomp(pair<int, bool> p1, pair<int, bool> p2)
{
    return p1.first < p2.first;
}

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
        vector<pair<int, bool>> point;
        for(int i = 0; i < n; i++)
        {
            int a, b;
            cin>>a>>b;
            point.push_back(make_pair(a, true));
            point.push_back(make_pair(b, false));
        }
        sort(point.begin(), point.end(), mycomp);
        int maxi = 0, cur = 0;
        for(int i = 0; i < point.size(); i++)
        {
            if(point[i].second)
            {
                cur++;
                if(cur > maxi) maxi = cur;
            }
            else cur--;
        }
        cout<<maxi<<endl;
    }

    return 0;
}


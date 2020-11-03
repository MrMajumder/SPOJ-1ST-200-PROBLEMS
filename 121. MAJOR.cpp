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

bool mycomp(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.second > p2.second);
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
        map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin>>temp;
            if(mp.find(temp) == mp.end()) mp[temp] = 1;
            else mp[temp]++;
        }
        vector<pair<int, int>> vc;
        copy(mp.begin(), mp.end(), back_inserter<vector<pair<int, int>>>(vc));
        sort(vc.begin(), vc.end(), mycomp);
        if(vc[0].second > (n / 2.0)) cout<<"YES"<<SPACE<<vc[0].first<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}


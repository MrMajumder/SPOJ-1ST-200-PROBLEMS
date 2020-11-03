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
        int before, after;
        cin>>before>>after;
        int weight = after - before;

        int n;
        cin>>n;
        vector<pair<int, int>> item;
        for(int i = 0; i < n; i++)
        {
            int p, w;
            cin>>p>>w;
            item.push_back(make_pair(w, p));
        }
        //sort(item.begin(), item.end());

        vector<int> dp(weight + 1, INF);
        dp[0] = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= weight; j++)
            {
                if(j >= item[i].first)
                {
                    if(dp[j - item[i].first] != INF) dp[j] = min(dp[j], dp[j - item[i].first] + item[i].second);
                }
            }
        }

        if(dp[weight] == INF) cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<dp[weight]<<"."<<endl;

    }

    return 0;
}



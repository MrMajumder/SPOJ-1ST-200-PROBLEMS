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
        vector<pair<int, int>> schedule;
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            int s, f;
            cin>>s>>f;
            schedule.push_back(make_pair(f, s));
        }
        sort(schedule.begin(), schedule.end());
        int counter = 1;
        int f;
        f = schedule[0].first;
        for(int i = 1; i < n; i++)
        {
            if(schedule[i].second >= f)
            {
                counter++;
                f = schedule[i].first;
            }
        }
        cout<<counter<<endl;
    }

    return 0;
}



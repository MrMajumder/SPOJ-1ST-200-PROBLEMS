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

string bfs(int n)
{
    queue<pair<string, int>> q;
    vector<bool> visited(n, false);
    q.push(make_pair("1", 1));
    //visited[1] = true;
    while(!q.empty())
    {
        string s = q.front().first;
        int x = q.front().second;
        x %= n;
        if(x == 0)
        {
            return s;
        }
        q.pop();
        if(visited[x]) continue;
        visited[x] = true;
        q.push(make_pair(s + '0', (x * 10)));
        q.push(make_pair(s + '1', (x * 10) + 1));
    }
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
        cout<<bfs(n)<<endl;
    }

    return 0;
}


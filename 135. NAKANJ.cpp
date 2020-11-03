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

int dx[] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[] = {-1, -2, 1, 2, -1, -2, 1, 2};

int bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    vector<vector<int>> dist(8, vector<int>(8, INF));
    dist[si][sj] = 0;
    q.push(make_pair(si, sj));
    while(!q.empty())
    {
        int ai = q.front().first;
        int aj = q.front().second;
        if(ai == di && aj == dj) return dist[di][dj];
        q.pop();
        visited[ai][aj] = true;
        for(int i = 0; i < 8; i++)
        {
            int bi = ai + dx[i];
            int bj = aj + dy[i];
            if(bi < 0 || bi > 7 || bj < 0 || bj > 7 || visited[bi][bj]) continue;
            dist[bi][bj] = dist[ai][aj] + 1;
            q.push(make_pair(bi, bj));
        }
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
        char a, b;
        int aj, bj, ai, bi;
        cin>>a>>aj>>b>>bj;
        ai = a - 'a';
        bi = b - 'a';
        --aj; --bj;
        cout<<bfs(ai, aj, bi, bj)<<endl;
    }

    return 0;
}


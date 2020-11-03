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

int dist[183][183];
short xx[] = {-1, 0, 1};
int r, c;

void bfs(pair<int, int> p)
{
    queue <pair<int, int>> q;
    q.push(p);

    while(!q.empty())
    {
        int a = q.front().first, b = q.front().second;
        q.pop();

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(abs(xx[i]) != abs(xx[j]) && a + xx[i] >= 0 && a + xx[i] <= r && b + xx[j] >= 0 && b + xx[j] <= c && dist[a + xx[i]][b + xx[j]] > 1 + dist[a][b])
                {
                    dist[a + xx[i]][b + xx[j]] = 1 + dist[a][b];
                    q.push(make_pair(a + xx[i], b + xx[j]));
                }
            }
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
        int x;
        cin>>r>>c;
        vector<pair<int, int>> src;
        string s;

        for(int i = 0; i < r; i++)
        {
            cin>>s;
            for(int j = 0; j < c; j++)
            {
                x = s[j] - '0';
                if(x == 1)
                {
                    dist[i][j] = 0;
                    src.push_back(make_pair(i, j));
                }
                else
                {
                    dist[i][j] = INF;
                }
            }
        }

        for(int i = 0; i < src.size(); i++)
        {
            bfs(src[i]);
        }
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++) cout<<dist[i][j]<<SPACE;
            cout<<ENDL;
        }

    }

    return 0;
}


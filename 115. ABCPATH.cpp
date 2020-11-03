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

char arr[51][51];
int traverse[] = {-1, 0, 1};
bool visited[51][51];
int dist[51][51];
int r, c;

struct pos
{
    int i, j;
};

pos createPos(int i, int j)
{
    pos p;
    p.i = i;
    p.j = j;
    return p;
}

int dfsUtil(int x, int y, int level)
{
    int maxi = 1;


    return maxi;
}

int dfs()
{
    int maxi = 0;
    memset(visited, 0, sizeof visited);
    memset(dist, 0, sizeof dist);

    queue<pos> q;
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) if(arr[i][j] == 'A')
    {
        maxi = 1;
        dist[i][j] = 1;
        q.push(createPos(i, j));
    }

    while(!q.empty())
    {
        pos temp = q.front();
        q.pop();
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == 1 && j == 1) continue;
                int ex = temp.i + traverse[i];
                int oai = temp.j + traverse[j];

                if(ex >= 0 && ex < r && oai >= 0 && oai < c && !visited[ex][oai] && (arr[ex][oai] == arr[temp.i][temp.j] + 1))
                {
                    visited[ex][oai] = true;
                    dist[ex][oai] = dist[temp.i][temp.j] + 1;
                    maxi = max(maxi, dist[ex][oai]);
                    q.push(createPos(ex, oai));
                }
            }
        }
    }

    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>r>>c;
    int counter = 1;
    while(r != 0)
    {
        for(int i = 0; i < r; i++) cin>>arr[i];
        cout<<"Case "<<counter++<<": "<<dfs()<<endl;
        cin>>r>>c;
    }

    return 0;
}


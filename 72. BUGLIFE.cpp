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

int mat[2010][2010];

void restart(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }
}

bool isBipartite(int n, int src)
{


    int color[n + 1];
    for(int i = 1; i <= n; i++) color[i] = -1;

    queue<int> q;
    q.push(src);
    color[src] = 1;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(mat[x][x]) return false;

        for(int v = 1; v <= n; v++)
        {
            if(mat[x][v] && color[v] == -1)
            {
                color[v] = !color[x];
                q.push(v);
            }
            else if(mat[x][v] && color[x] == color[v])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int cno = 1;

    while(t--)
    {
        int b, c;
        cin>>b>>c;
        int l, r;

        restart(b + 1);

        while(c--)
        {
            cin>>l>>r;
            mat[l][r] = 1;
            mat[r][l] = 1;
        }

        if(isBipartite(b, l)) cout<<"Scenario #"<<cno++<<":"<<endl<<"No suspicious bugs found!"<<endl;
        else cout<<"Scenario #"<<cno++<<":"<<endl<<"Suspicious bugs found!"<<endl;

    }


    return 0;
}


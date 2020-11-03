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

int maxi = 0, length = 0;
bool visited[1001][1001];
char lab[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int bestx, besty;
int row, col;

void dfsUtil(int r, int c)
{
    visited[r][c] = true;
    length++;
    if(length > maxi)
    {
        maxi = length;
        bestx = r; besty = c;
    }
    for(int i = 0; i < 4; i++)
    {
        int tempx = r + dx[i];
        int tempy = c + dy[i];
        if(tempx < 0 || tempx >= row || tempy < 0 || tempy >= col || visited[tempx][tempy] || lab[tempx][tempy] == '#') continue;
        dfsUtil(tempx, tempy);
    }
    visited[r][c] = false;
    length--;
}

void dfs(int r, int c)
{
    memset(visited, false, sizeof visited);
    length = 0; maxi = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(lab[i][j] == '.')
            {
                dfsUtil(i, j);
                i = r;
                break;
            }
        }
    }
    length = 0; maxi = 0;
    dfsUtil(bestx, besty);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>col>>row;
        for(int i = 0; i < row; i++) cin>>lab[i];
        dfs(row, col);
        cout<<"Maximum rope length is "<<maxi - 1<<"."<<endl;
    }

    return 0;
}


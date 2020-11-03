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
const int MOD = 1000000007; //9digits
const double EPS = 1e-8;
const long double EULER = 2.71828182845904523536;   //20digits
const long double PI = 3.14159265358979323846;      //20digits
//float = 7digits, double = 15digits, long double = 21 digits precision

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

char mat[101][101];
int r, c;
bool found;
string solu = "ALLIZZWELL";

int dxy[] = {-1, 0, 1};

void dfsUtil(int x, int y, vector<vector<bool>> visited, int pos)
{
    if(pos == 10)
    {
        found = true;
        return;
    }
    visited[x][y] = true;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == 1 && j == 1) continue;
            int a = x + dxy[i];
            int b = y + dxy[j];
            if(a < 0 || b < 0 || a >= r || b >= c)
            {
                continue;
            }
            //cout<<a<<SPACE<<b<<endl;
            if(!visited[a][b] && mat[a][b] == solu[pos]) dfsUtil(a, b, visited, pos + 1);
            if(found) return;
        }
    }
}

void dfs()
{
    vector<vector<bool>> visited(r, vector<bool>(c));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(mat[i][j] == 'A')
            {
                for(int m = 0; m < r; m++) visited[m].assign(c, false);
                dfsUtil(i, j, visited, 1);
            }
            if(found)
            {
                i = r;
                break;
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
        cin>>r>>c;
        for(int i = 0; i < r; i++) cin>>mat[i];
        found = false;
//        for(int i = 0; i < r; i++)
//        {
//            for(int j = 0; j < c; j++) cout<<mat[i][j]<<SPACE;
//            cout<<endl;
//        }
        dfs();
        if(found) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}


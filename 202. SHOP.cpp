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

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin>>col>>row;
    while(row || col)
    {
        string s[row];
        for(int i = 0; i < row; i++) cin>>s[i];
        vector<vector<int>> dist(row, vector<int>(col, INF));
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(s[i][j] == 'S')
                {
                    dist[i][j] = 0;
                    pq.push(make_pair(0, make_pair(i, j)));
                }
            }
        }
        int ans = 0;
        while(!pq.empty())
        {
            bool done = false;
            int far = - pq.top().first;
            pair<int, int> pos = pq.top().second;
            pq.pop();
            if(visited[pos.first][pos.second]) continue;
            visited[pos.first][pos.second] = true;
            for(int i = 0; i <= 3; i++)
            {
                int x = pos.first + dx[i];
                int y = pos.second + dy[i];
                if(x < 0 || y < 0 || x >= row || y >= col || visited[x][y] || s[x][y] == 'X') continue;
                if(s[x][y] == 'D')
                {
                    ans = far;
                    done = true;
                    break;
                }
                int val = (int) s[x][y] - '0';
                if(val + far < dist[x][y]) pq.push(make_pair( - (dist[x][y] = val + far), make_pair(x, y)));
            }
            if(done) break;
        }
        cout<<ans<<endl;
        cin>>col>>row;
    }

    return 0;
}


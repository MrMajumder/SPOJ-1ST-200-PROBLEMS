#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

bool dfs(vector<int> graph[], int start, int node)
{
    bool isVisited[node + 1];
    memset(isVisited, 0, sizeof(isVisited));

    queue<int> q;
    q.push(start);
    int counter = 0;

    while(!q.empty())
    {
        int now = q.front();
        isVisited[now] = true;
        q.pop();

        for(int i = 0; i < graph[now].size(); i++)
        {
            if(isVisited[graph[now][i]])
            {
                return false;
            }
            else
            {
                q.push(graph[now][i]);
            }
        }
        counter++;
    }

    if(counter == node) return true;
    else return false;
}

int main()
{
    int node, edge;
    cin>>node>>edge;

    vector<int> graph[node + 1];
    int l, r;

    while(edge--)
    {
        cin>>l>>r;
        if(l > r) swap(l, r);
        graph[l].push_back(r);
    }

    if(dfs(graph, 1, node)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    return 0;
}


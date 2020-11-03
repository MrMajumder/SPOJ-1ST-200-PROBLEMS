#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

int x;

void dfs(int start, vector<int> * tree, int count, int & maxcount, bool * isVisited)
{
    isVisited[start] = true;
    count++;

    for(int i = 0; i < tree[start].size(); i++)
    {
        if(!isVisited[tree[start][i]])
        {
            if(count > maxcount)
            {
                maxcount = count;
                x = tree[start][i];
            }
            dfs(tree[start][i], tree, count, maxcount, isVisited);
        }
    }
}

int diameter(vector<int> * tree, int n)
{
    int maxcount = INT_MIN;
    bool isVisited[n + 1];
    memset(isVisited, 0, sizeof(isVisited));
    int count = 0;

    dfs(1, tree, count, maxcount, isVisited);

    count = 0;
    memset(isVisited, 0, sizeof(isVisited));
    dfs(x, tree, count, maxcount, isVisited);

    return maxcount;
}

int main()
{
    int node;
    cin>>node;
    int edge = node - 1;
    vector<int> tree[node + 1];
    int l, r;
    while(edge--)
    {
        cin>>l>>r;
        tree[l].push_back(r);
        tree[r].push_back(l);
    }

    cout<<diameter(tree, node)<<endl;

    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    long long b;
    cin>>n;
    int sol[10][4] = {0, 0, 0, 0, 1, 1, 1, 1, 6, 2, 4, 8, 1, 3, 9, 7, 6, 4, 6, 4, 5, 5, 5, 5, 6, 6, 6, 6, 1, 7, 9, 3, 6, 8, 4, 2, 1, 9, 1, 9};

    for(; n > 0; n--)
    {
        cin>>a>>b;
        a = a % 10;
        if(b == 0)
        {
            cout<<1<<endl;
            continue;
        }
        int col = b % 4;
        cout<<sol[a][col]<<endl;
    }

    return 0;
}


╔┓┏╦━━╦┓╔┓╔━━╗
║┗┛║┗━╣┃║┃║╯╰║
║┏┓║┏━╣┗╣┗╣╰╯║
╚┛┗╩━━╩━╩━╩━━╝

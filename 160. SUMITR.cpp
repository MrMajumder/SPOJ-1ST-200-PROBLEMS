#include<bits/stdc++.h>
using namespace std;int arr[101][101],t,n,i,j;main(){cin>>t;while(t--){cin>>n;for(i=0;i<n;i++)for(j=0;j<=i;j++)cin>>arr[i][j];for(i=n-2;i>=0;i--)for(j=i;j>=0;j--)arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);cout<<arr[0][0]<<endl;}}

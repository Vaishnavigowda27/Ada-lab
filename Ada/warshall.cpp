#include<bits/stdc++.h>
using namespace std;
int a[10][10], i,j,k,n;
int main()
{
cout<<"Enter no of vertices:\n";
cin>>n;
cout<<"Enter elements\n";
for(int i = 1;i <= n; i++)
for(int j = 1;j <= n; j++)
cin>>a[i][j];
for(int i = 1;i <= n; i++)
for(int j = 1;j <= n; j++)
for(int k = 1;k <= n; k++)
a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
cout<<"The o/p is\n";
for(int i = 1;i <= n; i++){
for(int j = 1;j <= n; j++){
cout << a[i][j]<<"\t";
}
cout<<"\n";
}
return 0;
}






#include<bits/stdc++.h>
using namespace std;
int min_val(int a, int b){
  if(a < b)
    return a;
  else
    return b;
  }
  void floyds(int a[10][10], int p[10][10], int n) {
    int i,j,k;
     for(i =0 ; i < n; i++)
     for(j =0 ; j < n; j++)
     for(k =0 ; k < n; k++)
a[i][j] = min_val(a[i][j], a[i][k] + a[k][j]);
     for(i =0 ; i < n; i++){
     for(j =0 ; j < n; j++){
      cout<<a[i][j]<<"\t";
  }
  cout<<endl;
     }
  }
  int main(){
    int p[10][10], a[10][10], n;
    cout<<"Enter the nodes:";
    cin>>n;
    cout<<"Enter the matrix:\n";
    for(int i =0 ; i < n; i++)
     for(int j =0 ; j < n; j++)
     cin>>p[i][j];
    for(int i =0 ; i < n; i++)
     for(int j =0 ; j < n; j++)
a[i][j] = p[i][j];
cout<<"The given matrix:\n";
     for(int i =0 ; i < n; i++){
     for(int j =0 ; j < n; j++){
     cout<<a[i][j]<<"\t";
  }
  cout<<endl;
     }
cout<<"The sol is:\n";
floyds(p, a, n);
return 0;
  } 








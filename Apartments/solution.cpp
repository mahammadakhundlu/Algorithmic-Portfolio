#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n,m,k;
    cin>>n>>m>>k;
    long a[n];
    for(long i=0;i<n;i++){
    cin>>a[i];}
    long b[m];
    for(long j=0;j<m;j++){
    cin>>b[j];}
    sort(a,a+n);
    sort(b,b+m);
    long i=0,j=0,say=0,x,y;
    while(i<n and j<m){
     x=a[i]-k,y=a[i]+k;
     if(b[j]>=x and b[j]<=y){
        say++;
        i++;
        j++;
     }
     else if(b[j]<x)
     j++;
     else if(b[j]>y)
     i++;
    }
    cout<<say;
    return 0;
}

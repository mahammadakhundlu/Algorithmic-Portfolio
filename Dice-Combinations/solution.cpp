#include <bits/stdc++.h>
using namespace std;
long a[1000001];
int main()
{
   long n;
   cin>>n;
   a[0]=1;
   for(long i=1;i<=n;i++){
    for(long j=1;j<=6;j++){
    if(i-j>-1)
    a[i]=(a[i]+a[i-j])%1000000007;
    }
   }
   cout<<a[n];
    return 0;

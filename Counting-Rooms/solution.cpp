#include <bits/stdc++.h>
using namespace std;
long a[1001][1001];
bool ch[1001][1001];
void yes(long x,long y){
ch[x][y]=true;
if(a[x][y+1]==1 and ch[x][y+1]==0)
yes(x,y+1);
if(a[x][y-1]==1 and ch[x][y-1]==0)
yes(x,y-1);
if(a[x+1][y]==1 and ch[x+1][y]==0)
yes(x+1,y);
if(a[x-1][y]==1 and ch[x-1][y]==0)
yes(x-1,y);
}
int main()
{
    long n,m;
    char s;
    cin>>n>>m;
    for(long i=1;i<=n;i++){
        for(long j=1;j<=m;j++){
        cin>>s;
        if(s=='.'){
        a[i][j]=1;}
        else a[i][j]=0;
        }
    }
    long say=0;
    for(long i=1;i<=n;i++){
    for(long j=1;j<=m;j++){
    if(ch[i][j]==0 and a[i][j]==1){
    yes(i,j);
    say++;}
    }
    }
    cout<<say;
    
    return 0;
}


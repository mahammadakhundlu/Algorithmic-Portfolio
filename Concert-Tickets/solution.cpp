#include <bits/stdc++.h>
using namespace std;
int main()
{
   long n,a,m;
   cin>>n>>m;
   multiset<long>ms;
   for(long i=0;i<n;i++){
   cin>>a;
   ms.insert(a);}
   while(m--){
    cin>>a;
    auto it=ms.upper_bound(a);
    if(it!=ms.begin()){
    it--;}
    if(*it<=a and it!=ms.end()){
    cout<<*it<<endl;
    ms.erase(it);}
    else
    cout<<-1<<endl;
    
   }
   
   
 
    return 0;
}

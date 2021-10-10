#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>x;
const ll M = 1e18;

ll find(ll a,ll b){
  if(a==0){
    return 0;
  }
  ll c = upper_bound(x.begin(),x.end(),a)-x.begin()-1;
  if(c>=b){
    return -1;
  }
  ll k = find(a-x[c],c);
  if(k == -1){
    if((c+1)<b){
      return x[c+1];
    }
    return -1;
  }
  return k+x[c];
}

int main()
{
  //write your code here
  ll p = 1;
  x.push_back(0);
  x.push_back(1);
  while((x.back()<=(M/3))){
    x.push_back(x.back()*3);
  }x.push_back(x.back()*3);
  ll t;
  cin>>t;
  while(t--){
    ll k;
    cin>>k;
    ll r =  upper_bound(x.begin(),x.end(),k)-x.begin();
    ll p = find(k,r);
    if(p==-1){
      cout<<x[r]<<"\n";
    }else{
      cout<<p<<"\n";
    }
  }
  return 0;
}

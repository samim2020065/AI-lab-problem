#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define sz 200005
using namespace std;
// ll par1[sz],par2[sz];
// ll h1[sz],h2[sz];
// vector<ll>v;
// bool cmp(pair<ll,ll>x,pair<ll,ll>y){
//     if(x.first==y.first){
//         return x.second<y.second;
//     }
//     else{
//         return x.first>y.first;
//     }
// }
// void dfs(ll ind,ll c){
//     vis2[ind]=1;
//     mp[ind]=c;
//     for(auto it:adj2[ind]){
//         if(!vis2[it]){
//             dfs(it,c);
//         }
//     }
// }
// void dfs1(ll ind){
//     vis1[ind]=1;
//     for(auto it:adj1[ind]){
//         if(!vis1[it]){
//             dfs1(it);
//         }
//     }
// }
// void init(ll n){
//     for(ll i=1;i<=n;i++){
//         adj1[i].clear();
//         adj2[i].clear();
//         vis1[i]=0;
//         vis2[i]=0;
//     }
//     mp.clear();
//     v.clear();
//     st.clear();
// }

// void make(ll v){
//     par1[v]=v;
//     par2[v]=v;
//     h1[v]=1;
//     h2[v]=1;
// }
// ll findG(ll v){
//     if(v==par2[v]){
//         return v;
//     }
//     return par2[v]=findG(par2[v]);
// }
// ll findF(ll v){
//     if(v==par1[v]){
//         return v;
//     }
//     return par1[v]=findF(par1[v]);
// }
// void UnionG(ll a,ll b){
//     a=findG(a);
//     b=findG(b);
//     //cout<<par2[a]<<" "<<par2[b]<<endl;
//     if(a!=b){
//         if(h2[a]<h2[b]){
//             swap(a,b);
//         }
//         par2[b]=a;
//         h2[a]+=h2[b];
//     }
//     //cout<<par2[a]<<" "<<par2[b]<<endl;
// }
// void UnionF(ll a,ll b){
//     a=findF(a);
//     b=findF(b);
//     if(a!=b){
//         if(h1[a]<h1[b]){
//             swap(a,b);
//         }
//         par1[b]=a;
//         h1[a]+=h1[b];
//     }
// }
// void prime(){
//     for(ll i=2;i<=3000;i++){
//         ll f=0;
//         for(ll j=2;j<=sqrt(i);j++){
//             if(i%j==0){
//                 f=1;
//                 break;
//             }
//         }
//         if(f==0){
//             v.pb(i);
//         }
//     }
// }
ll check(ll m,ll k){
    ll lo=1,hi=m;
    ll ans;
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        ll booked=m/(mid+1)*mid+(m%(mid+1));
        if(booked>=k){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int main(){
    //prime();
    // for(auto it:v){
    //     cout<<it<<" ";
    // }
    // set<ll>st;
    // for(ll i=1;i<=1000000;i++){
    //     st.insert(i*i);
    // }
    // for(ll i=1;i<=500000;i++){
    //         auto it2=find(v.begin(),v.end(),i*(i+1)/2);
    //         auto it3=find(v.begin(),v.end(),(i*(i+1)/2)+1);
    //         if(it2!=v.end()&&it3!=v.end()){
    //             cout<<i<<endl;
    //         }
    // }
    int t;
    cin>>t;
    // for(ll i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    while(t--){
      ll n;
      cin>>n;
      ll a[n];
      ll mn=LLONG_MAX;
      ll x=-1;
      for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<mn){
            mn=a[i];
            x=i;
        }
        
      }
      vector<ll>v;
      for(ll i=0;i<n;i++){
        if(x!=i){
            if(a[i]%mn==0){
                v.pb(a[i]);
            }
        }
      }
      if(v.size()==0){
        no;
      }
      else{

        ll gc=v[0];
      for(ll i=1;i<v.size();i++){
        gc=__gcd(v[i],gc);
      }
      if(gc==mn){
        yes;
      }
      else{
        no;
      }
      }
      
  }
}
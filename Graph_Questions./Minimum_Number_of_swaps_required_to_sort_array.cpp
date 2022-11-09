#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

int main(){

    int n; cin>>n;
    vector<pair<int, int>>v;
    for (int i = 0; i < n; ++i)
    {
        int x; cin>>x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    int moves=0;

    vector<bool>vis(n, false);
    for (int i = 0; i < n; ++i)
    {
        if(vis[i]== true|| v[i].second==i ){
            continue;
        }
        int cy_len=0;
        int j=i;
        while(vis[j]==false){
            vis[j]= true;
            cy_len++;
            j= v[j].second;
        }
        moves+=cy_len-1;
    }
    cout<<moves<<nl;


}

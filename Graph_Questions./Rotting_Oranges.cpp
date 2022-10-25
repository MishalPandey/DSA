#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define fs  first
#define sc  second


int main(){

    int m, n;
      cin>>m>>n;
      vector<vector<int>>grid(m, vector<int>(n, 0));
      queue<pair<int, int>>q;
      int ct_1=0;
       //taking input
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          cin>>grid[i][j];

          if(grid[i][j]==2){
            q.push({i, j});
          }
          if(grid[i][j]==1){
            ct_1++;
          }
          
        }
      }
      if(ct_1==0){
        cout<<"0"<<nl;
        return 0;
      }
      
      //using BFS level wise ---->check it
      int level=-1;

     
     while(q.size()>0){
          int size= q.size();
          level++;
          while(size--){
                pair<int, int>v= q.front();
                q.pop();        
                vector<pair<int, int>>for_nebr={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (int i = 0; i < for_nebr.size(); ++i)
                {
                    int x= for_nebr[i].fs+ v.fs;
                    int y= for_nebr[i].sc+ v.sc;
                    if(x<0|| y<0|| x>=m|| y>=n || grid[x][y]!=1){
                      continue;
                    }
                    else{
                      q.push({x, y});
                      grid[x][y]= 2;
                      ct_1--;
                    }
                }
                
          }
          
    }
    if(ct_1==0){
      cout<<level<<nl;
    }
    else{
      cout<<"-1"<<nl;
    }



}

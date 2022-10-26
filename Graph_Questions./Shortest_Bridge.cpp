#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define fs  first
#define sc  second
vector<pair<int, int>>for_nebr={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int i, int j,vector<vector<int>>grid, queue<pair<int, int>>&q, vector<vector<bool>>&vis ){
  vis[i][j]= true;
  q.push({i, j});
  for (int k = 0; k < for_nebr.size(); ++k)
  {
        int x= for_nebr[k].fs+ i;
        int y= for_nebr[k].sc+ j;
        if(x<0|| y<0|| x>=grid.size()|| y>=grid[0].size() || vis[x][y]==true|| grid[x][y]==0){
          continue;
        }
        dfs(x, y, grid, q, vis);
        

  }
}


int main(){

    int n;
      cin>>n;
      vector<vector<int>>grid(n, vector<int>(n, 0));
      vector<vector<bool>>vis(n, vector<bool>(n, false));
      queue<pair<int, int>>q;
      
       //taking input
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin>>grid[i][j];

      bool flag= false;
      for (int i = 0; i < n && !flag; ++i)
      {
        for (int j = 0; j < n && !flag; ++j)
        {
            if(grid[i][j]==1){
              dfs(i, j, grid, q, vis);
              flag=true;
            }
        }        
      }
      
      
       int level=0;
       //------------------------->>>>using BFS
       while(q.size()>0){
            int size= q.size();
  
            while(size--){
                  pair<int, int>v= q.front();
                  q.pop();        
                
                  for (int i = 0; i < for_nebr.size(); ++i)
                  {
                      int x= for_nebr[i].fs+ v.fs;
                      int y= for_nebr[i].sc+ v.sc;
                      if(x<0|| y<0|| x>=n|| y>=n || vis[x][y]==true){
                        continue;
                      }
                      if(grid[x][y]==1){
                        cout<<level<<nl;
                        return 0;
                      }
                      q.push({x, y});
                  }            
            }
            level++;            
        }
          
        cout<<"-1"<<nl;


}

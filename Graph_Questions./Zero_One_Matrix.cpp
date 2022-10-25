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
  
       //taking input
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          cin>>grid[i][j];
           //adding 0 values's vertex in queue and marking  1 values's vertex unvisited
          if(grid[i][j]==1){
            grid[i][j]=-1;
          }
          else{
            q.push({i, j});
          }
          
        }
      }

      while(q.size()>0){
          pair<int, int>v= q.front();
          q.pop();
          // if(v.sc+1<n && grid[v.fs][v.sc+1]==-1){
          //     q.push({v.fs, v.sc+1});
          //     grid[v.fs][v.sc+1]=grid[v.fs][v.sc]+1;

          // }
          // if(v.sc-1>=0 && grid[v.fs][v.sc-1]==-1){
          //     q.push({v.fs, v.sc-1});
          //     grid[v.fs][v.sc-1]=grid[v.fs][v.sc]+1;
          // }
          // if(v.fs+1<m && grid[v.fs+1][v.sc]==-1){
          //     q.push({v.fs+1, v.sc});
          //     grid[v.fs+1][v.sc]=grid[v.fs][v.sc]+1;
          // }
          // if(v.fs-1>=0 && grid[v.fs-1][v.sc]==-1){
          //     q.push({v.fs-1, v.sc});
          //     grid[v.fs-1][v.sc]=grid[v.fs][v.sc]+1;
          // }
        
        // short-------------------
          vector<pair<int, int>>for_nebr={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
          for (int i = 0; i < for_nebr.size(); ++i)
          {
            int x= for_nebr[i].fs+ v.fs;
            int y= for_nebr[i].sc+ v.sc;
            if(x<0|| y<0|| x>=m|| y>=n || grid[x][y]!=-1){
              continue;
            }
            else{
              q.push({x, y});
              grid[x][y]= grid[v.fs][v.sc]+1;
            }
          }



      }
  
      //output
     for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          cout<<grid[i][j]<<" ";
        }
        cout<<nl;
      }
  


}

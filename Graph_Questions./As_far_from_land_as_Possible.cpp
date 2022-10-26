#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define fs  first
#define sc  second

int main(){

    int n;
      cin>>n;
      vector<vector<int>>grid(n, vector<int>(n, 0));
      queue<pair<int, int>>q;
         //taking input
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          cin>>grid[i][j];
           //adding 1 values's vertex in queue and marking  0 values's vertex unvisited
          if(grid[i][j]==1){
            q.push({i, j});
          }
        }
      }
      if(q.size()==0 || q.size()==n*n){
        cout<<"-1"<<nl;
        return 0;
      }
      
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
                      if(x<0|| y<0|| x>=n|| y>=n || grid[x][y]==1){
                        continue;
                      }
                      else{
                        q.push({x, y});
                        grid[x][y]= 1;
                       
                      }
                  }
                  
            }            
        }
  
        cout<<level<<nl;
}

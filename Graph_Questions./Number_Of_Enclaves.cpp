#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
void no_of_enclaves(vector<vector<int>>&grid,int i, int j){


    if (i < 0  || j < 0 ||i == grid.size()|| j == grid[0].size()|| grid[i][j]!=1)
        return;
    
    grid[i][j]=0;

    no_of_enclaves(grid, i+1, j);
    no_of_enclaves(grid, i-1, j);
    no_of_enclaves(grid, i, j+1);
    no_of_enclaves(grid, i, j-1);
     

}


int main(){

  
      int m, n;
      cin>>m>>n;
      vector<vector<int>>grid(m, vector<int>(n, 0));
  
       //taking input
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          cin>>grid[i][j];
        }
      }
  
      // making zero to every boundary 1's and his connected component
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          if(grid[i][j]==1 && (i == 0 || i == m-1 || j == 0 || j == n-1)){
            no_of_enclaves(grid, i, j);
          }
        }
      }
  
     int ans=0;
     for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          if(grid[i][j]==1){
            ans++;
          }
        }
      }
      cout<<ans<<nl;
  



}

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

string psf="";
//component and structure making
void no_of_dis_island(vector<vector<int>>&grid, int i, int j){

    grid[i][j]=0;

    if ( j+1 < grid[0].size() && grid[i][j+1]==1){
        psf+="r";
        no_of_dis_island(grid, i, j+1);
    }
    if (  i+1 < grid.size() && grid[i+1][j]==1){
        psf+="d";
        no_of_dis_island(grid, i+1, j);
    }
    if (  j-1 >= 0 && grid[i][j-1]==1){
        psf+="l";
        no_of_dis_island(grid, i, j-1);
    }
    if (  i-1 >= 0 && grid[i-1][j]==1){
        psf+="u";
        no_of_dis_island(grid, i-1, j);
    }

    psf+="z";
    
}

  

int main(){

      //taking input
      int m, n;
      cin>>m>>n;
      vector<vector<int>>grid(m, vector<int>(n, 0));
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          cin>>grid[i][j];
        }
      }
      
      //adding structures in a set to find no of distnict islands
      set<string>ans;
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
            if(grid[i][j]==1){
              psf+="x";
              no_of_dis_island(grid, i, j);
              ans.insert(psf);
              psf="";

          }
        }
      }
     
     
      cout<<ans.size() <<nl;
  



}

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};
//------1st
bool hasPath(vector<Edge>graph[], int src, int dest, vector<bool> visited ){
      if(src== dest){
        return true;
      }

      visited[src]= true;
      for(Edge edge : graph[src]){

          if(visited[edge.nbr]== false){

              bool hasNbrPath= hasPath(graph, edge.nbr, dest, visited);
              if(hasNbrPath == true){
                return true;
              }

          }

      }


      return false;
}

//------2nd
void printAllPaths(vector<Edge>graph[], int src, int dest, vector<bool> visited, string psf ){
      if(src== dest){
        cout<<psf<<nl;
        return;

      }

      visited[src]= true;
      for(Edge edge : graph[src]){

          if(visited[edge.nbr]== false){

              printAllPaths(graph, edge.nbr, dest, visited, psf+ to_string(edge.nbr));
              
          }

      }


      visited[src]= false;
}

//------3rd

string smaller_path;
int smaller_path_wt = INT_MAX;
string larger_path;
int larger_path_wt = INT_MIN;
string ceil_path;
int ceil_path_wt = INT_MAX;
string floor_path;
int floor_path_wt = INT_MIN;
string kth_path;

//min heap for priority queue
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

void multisolver(vector<Edge> graph[], int src, int dest, vector<bool> visited, int criteria, int k, string path, int wt) {



      if(src== dest){

            if(smaller_path_wt> wt){
                smaller_path_wt= wt;
                smaller_path= path;

            }
            if(larger_path_wt<wt){
                larger_path_wt= wt;
                larger_path= path;
            }

            if(wt>criteria && ceil_path_wt>wt){
                ceil_path_wt=wt;
                ceil_path=path;

            }
            if(wt<criteria && floor_path_wt<wt){
                floor_path_wt=wt;
                floor_path=path;

            }


            // kth largest path
            if(pq.size() < k)
            {
                    pq.push({wt, path});
            }

            else
            {
                  if(pq.top().first < wt)
                  {
                    pq.pop();
                    pq.push({wt, path});
                  }
                  kth_path = pq.top().second + "@" + to_string(pq.top().first);
            }

        return;

      }


      visited[src]= true;
      for(Edge edge : graph[src]){

          if(visited[edge.nbr]== false){

              multisolver( graph, edge.nbr, dest, visited, criteria, k, path+ to_string(edge.nbr), wt+ edge.wt);
              
          }

      }
      visited[src]= false;


  
}
//------4th
void drawTreeAndGenerateComp(vector<Edge> graph[], int src, vector<int>&comp, vector<bool> &visited){
    visited[src]= true;
    comp.push_back(src);
    for(Edge edge : graph[src]){

          if(visited[edge.nbr]== false){

              drawTreeAndGenerateComp(graph, edge.nbr, comp, visited);
              
          }

      }

}

//------6th
void drawTreeForComponents(vector<vector<int>> arr, int i, int j, vector<vector<bool>> &visited){
    
    if(i<0||j<0|| i>= arr.size() || j>=arr[0].size()|| arr[i][j]==1|| visited[i][j]==true){
      return;
    }


    visited[i][j]= true;
    drawTreeForComponents(arr, i-1, j, visited );
    drawTreeForComponents(arr, i, j+1, visited );
    drawTreeForComponents(arr, i, j-1, visited );
    drawTreeForComponents(arr, i+1, j, visited );
}

//------7th
class  Edgee {
public:
  int src;
  int nbr;

   Edgee(int src, int nbr) {
    this->src = src;
    this->nbr = nbr;
  }
};
void drawTreeAndGenerateComp_Perfect_friend(vector<Edgee> graph[], int src, vector<int>&comp, vector<bool> &visited){
    visited[src]= true;
    comp.push_back(src);
    for(Edgee edge : graph[src]){

          if(visited[edge.nbr]== false){

               drawTreeAndGenerateComp_Perfect_friend(graph, edge.nbr, comp, visited);
              
          }

      }

}
//--------8th
void Hamiltonian_path_cycle(vector<Edge> graph[], int src, set<int>&visited, string psf, int osrc, int vtces){

    if(visited.size()== vtces- 1){ // because psf me phle hi add ho jarhi hai, par visited me function ke andar aane ke baad add ho rahi hai pathpoint

          cout<<psf;
    
          bool closingEdgeFound= false;
          for(Edge edge : graph[src]){

                if(edge.nbr== osrc){

                     closingEdgeFound=true;
                     break;
                }

          }
          if(closingEdgeFound){
            cout<<"*"<<nl;
          }
          else{
            cout<<"."<<nl;
          }
          return;
  }



      visited.insert(src);
      for(Edge edge : graph[src]){

          if(visited.find(edge.nbr)== visited.end()){
              Hamiltonian_path_cycle(graph, edge.nbr, visited, psf+ to_string(edge.nbr), osrc, vtces);
               
          }

      }
      visited.erase(src);

}

//---------9th
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess,  int r, int c, int move) {
  
  if(r<0|| c<0|| r>=chess.size()|| c>=chess.size() || chess[r][c]>0){
      return;
  }
  else if(move== chess.size()*chess.size()){
      chess[r][c]= move;
      display(chess);
      chess[r][c]= 0;
      return;
  }
  chess[r][c]= move;
  printKnightsTour(chess, r-2, c+1,  move+1);
  printKnightsTour(chess, r-1, c+2,  move+1);
  printKnightsTour(chess, r+1, c+2,  move+1);
  printKnightsTour(chess, r+2, c+1,  move+1);
  printKnightsTour(chess, r+2, c-1,  move+1);
  printKnightsTour(chess, r+1, c-2,  move+1);
  printKnightsTour(chess, r-1, c-2,  move+1);
  printKnightsTour(chess, r-2, c-1,  move+1);
  chess[r][c]= 0;
  
  
}
//--------------10th

void Breadth_First_search(vector<Edge> graph[], int src, vector<bool>visited){
  queue<pair<int, string>>que;
  que.push({src, to_string(src)});

  while(que.size()>0){
        // r m* w a* 
        int rem_val= (que.front()).first;
        string rem_path= que.front().second;
        que.pop();
        if(visited[rem_val]== true)
        {
             continue;
        }
        visited[rem_val]=true;
        cout<<rem_val<<"@"<<rem_path<<nl;
        for(Edge edge: graph[rem_val])
        {
              if(visited[edge.nbr]== false)
              {
                    que.push({edge.nbr, rem_path+to_string(edge.nbr)});
              }
        }

  }
}
bool IsCyclic(vector<Edge> graph[], int src, vector<bool>&visited){
  queue<int>que;
  que.push(src);

  while(que.size()>0){
        // r m* w a* 
        int rem_val= que.front();
        que.pop();
        if(visited[rem_val]== true)
        {
             return true;
        }
        visited[rem_val]=true;

        for(Edge edge: graph[rem_val])
        {
              if(visited[edge.nbr]== false)
              {
                    que.push(edge.nbr);
              }
        }

  }
  return false;
}

 //---------12th
class Pair{
 public:
  int val;
  string psf;
  int level;

  Pair(int val, string psf, int level){
    this->val=val;
    this->psf= psf;
    this->level= level;

  }
};
 bool checkComponentBipartite(vector<Edge> graph[], int src, vector<int>&visited){
    queue<Pair>que;
    que.push(Pair(src, to_string(src), 0));

    while(que.size()>0){
          Pair rem= que.front();
          que.pop();
          if(visited[rem.val]!= -1)
          {
              if(rem.level!= visited[rem.val]) {
                  return false;
              }
          }
          else
          {
              visited[rem.val]=rem.level;
          }
          
          for(Edge edge: graph[rem.val])
          {
              if(visited[edge.nbr]== -1)
              {
                    que.push(Pair(edge.nbr, rem.psf+to_string(edge.nbr), rem.level+1));
              }
          }

    }

    return true;

 }
  //---------13th
 void Spread_Infection(vector<Edge> graph[], int src, vector<int>&visited, int time_limit){
    queue<pair<int, int>>q;
    //pair---value and time
    q.push({src, 1});
    int count=0;

         while(q.size()>0){
          // r m* w a* 
            pair<int, int> rem= q.front();
            q.pop();
            if(visited[rem.first]>0){
              continue;
            }
            visited[rem.first]= rem.second;
            if(rem.second>time_limit ){
              break;
            }
            count++;

            for(Edge edge: graph[rem.first])
              {
                  if(visited[edge.nbr]== 0)
                  {
                        q.push({edge.nbr, rem.second+1});
                  }
              }


         }
         cout<<count<<nl;
 }

 //Dijkstra Algorithm
struct Tuple
{
  int wt;
  int v;
  string path;

  Tuple(int wt, int v, string path)
  {
    this->wt = wt;
    this->v = v;
    this->path = path;
  }
};

struct compo
{
  bool operator()(Tuple const &t1, Tuple const t2)
  {
    if(t1.wt == t2.wt)
    {
      if(t1.path.size() == t2.path.size())
        return t1.path > t2.path;

      else
        return t1.path.size() > t2.path.size();
    }

    return t1.wt > t2.wt;
  }
};


void Dijkstra(vector <Edge> graph[], int src, vector<bool> visited)
{
      priority_queue <Tuple, vector <Tuple>, compo> pq;
      pq.push(Tuple(0, src, to_string(src)));

      while(pq.size())
      {
        Tuple top = pq.top();
        pq.pop();

        if(visited[top.v])
          continue;

        visited[top.v] = true;

        cout << top.v << " via " << top.path << " @ " << top.wt << endl;

        for(auto child : graph[top.v])
        {
          if(visited[child.nbr] == false)
            pq.push(Tuple(top.wt + child.wt, child.nbr, top.path + to_string(child.nbr)));
        }
      }  
}


//Prims Algorithm
struct NTuple
{
  int v;
  int aquring_vertex;
  int wt;

  NTuple(int v, int aquring_vertex, int wt)
  {
    this->v = v;
    this->aquring_vertex = aquring_vertex;
    this->wt = wt;
  }
};

struct compoo
{
  bool operator()(NTuple const &t1, NTuple const &t2)
  {

    return t1.wt > t2.wt;
  }
};


void Prims(vector <Edge> graph[] , vector<bool> visited)
{
      priority_queue <NTuple, vector <NTuple>, compoo> pq;
      pq.push(NTuple(0, -1 , 0)); //-1 imaginary vertex

      while(pq.size())
      {
        NTuple top = pq.top();
        pq.pop();

        if(visited[top.v])
          continue;

        visited[top.v] = true;

        if(top.aquring_vertex!=-1)
            cout <<"["<< top.v << "-" << top.aquring_vertex << "@" << top.wt <<"]"<< endl;

        for(auto child : graph[top.v])
        {
          if(visited[child.nbr] == false)
            pq.push(NTuple(child.nbr, top.v, child.wt ));
        }
      }  
}


// topologicalSort order
class Edge_No_wtt {
public:
  int src;
  int nbr;

  Edge_No_wtt(int src, int nbr) {
    this->src = src;
    this->nbr = nbr;
  }
};

 void topologicalSort(vector <Edge_No_wtt> graph[] ,int src, vector<bool> &visited, stack<int>&st){


    visited[src]=true;
    for(Edge_No_wtt edge : graph[src])
    {
        if(visited[edge.nbr] == false){
          topologicalSort(graph, edge.nbr, visited, st);
        }
        
    }
    st.push(src);

 }
// same as BFS but here we are using stack in place of queue
 void Iterative_DFS(vector <Edge_No_wtt> graph[] ,int src, vector<bool> &visited){

    stack<pair<int, string>>st;
    st.push({src, to_string(src)});

    while(st.size()>0){
          // r m* w a* 
          int rem_val= (st.top()).first;
          string rem_path= st.top().second;
          st.pop();
          if(visited[rem_val]== true)
          {
               continue;
          }
          visited[rem_val]=true;
          cout<<rem_val<<"@"<<rem_path<<nl;

          for(Edge edge: graph[rem_val])
          {
                if(visited[edge.nbr]== false)
                {
                      st.push({edge.nbr, rem_path+to_string(edge.nbr)});
                }
          }

    }

 }










int main() {
  // int vtces;
  // cin >> vtces;
  // vector<Edge>graph[vtces];

  // int edges;
  // cin >> edges;
  // for (int i = 0; i < edges; i++) {
  //   int v1 ;
  //   int v2 ;
  //   int wt ;
  //   cin >> v1 >> v2 >> wt;
  //   graph[v1].push_back( Edge(v1, v2, wt));
  //   graph[v2].push_back( Edge(v2, v1, wt));
  // }
  //  vector<bool>visited(vtces, false);

  // int src;
  // cin >> src;
  // int dest;
  // cin >> dest;
  

  // cout<<hasPath(graph, src, dest, visited)<<nl;                                                 //------1st

  // printAllPaths(graph, src, dest, visited, to_string(src));                                    //------2nd


  //int criteria; cin>>criteria; int k; cin>>k;                                                   //------3rd
  // multisolver(graph, src, dest, visited, criteria, k, src + "0", 0);
  //     cout << "Smallest Path = " << smaller_path << "@" << smaller_path_wt << endl;
  //     cout << "Largest Path = " << larger_path << "@" << larger_path_wt << endl;
  //     cout << "Just Larger Path than " << criteria << " = " << ceil_path << "@" << ceil_path_wt << endl;
  //     cout << "Just Smaller Path than " << criteria << " = " << floor_path << "@" << floor_path_wt << endl;
  //     cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;


      // vector<vector<int>> connectedComps;                                                      //------4th
      // for (int i = 0; i < vtces; ++i)
      // {
      //   if(visited[i]==false){
      //       vector<int>comp;
      //       drawTreeAndGenerateComp(graph, i, comp, visited);
      //       connectedComps.push_back(comp);
      //   }
      // }

      // for(auto it: connectedComps){
      //     for(auto it1: it){
      //       cout<<it1<<" ";
      //     }
      //     cout<<nl;
      // }
      // if(connectedComps.size()==1){                                                          //------5th
      //   cout<<"yesGraph Connected";
      // }
      // else{
      //   cout<<"no";
      // }


      // int n, m;                                                                              //--------6th
      // cin >> n;
      // cin >> m;
      // vector<vector<bool>> visited(n, vector<bool>(m, false));

      // vector<vector<int>> arr;
      // for (int i = 0; i < n; i++)
      // {
      //     vector<int> ans;
      //     for (int j = 0; j < m; j++)
      //     {
      //         int res;
      //         cin >> res;
      //         ans.push_back(res);
      //     }
      //     arr.push_back(ans);
      // }
      // int count=0;
      // for (int i = 0; i < n; i++)
      // {
      //     for (int j = 0; j < m; j++)
      //     {
      //         if(arr[i][j]==0 && visited[i][j]==false){
      //           drawTreeForComponents(arr, i, j, visited);
      //           count++;

      //         }
              
      //     }
      // }
      // cout<<count;

      // int vtces;                                                                     //-----------7th
      // cin >> vtces;
      // vector<Edgee>graph[vtces];

      // int edges;
      // cin >> edges;
      // for (int i = 0; i < edges; i++) {
      //   int v1 ;
      //   int v2 ;
      //   cin >> v1 >> v2 ;
      //   graph[v1].push_back( Edgee(v1, v2));
      //   graph[v2].push_back( Edgee(v2, v1));
      // }
      // vector<bool>visited(vtces, false);

      // vector<vector<int>> connectedComps;                                                      
      // for (int i = 0; i < vtces; ++i)
      // {
      //   if(visited[i]==false){
      //       vector<int>comp;
      //       drawTreeAndGenerateComp_Perfect_friend(graph, i, comp, visited);
      //       connectedComps.push_back(comp);
      //   }
      // }

      // int Perfect_friend_pairs=0;
      // for (int i = 0; i < connectedComps.size(); ++i)
      // {
      //   for (int j = i+1; j < connectedComps.size(); ++j)
      //   {
      //      int ans= connectedComps[i].size()* connectedComps[j].size();
      //      Perfect_friend_pairs+=ans;
      //   }
      // }
      // cout<<Perfect_friend_pairs<<nl;

        // set<int>visited;                                                                                       //-----------8th
        // Hamiltonian_path_cycle(graph, src, visited, to_string(src), src, vtces);

        //     int n, r, c; cin>>n>>r>>c;                                                                       //---------9th
        // vector<vector<int>>a(n , vector<int> (n , 0));                                           
        // printKnightsTour(a,  r, c, 1) ;
        
       // Breadth_First_search(graph, src, visited);                                                                  //---------10th

      //  for (int i = 0; i < vtces; ++i)                                                                             //---------11th
      // {
      //   if(visited[i]==false){
      //       bool cycle = IsCyclic(graph, i, visited);
      //       if(cycle){
      //         cout<<"true"<<nl;
      //         return 0;
      //       }
      //   }
      // }
      // cout<<"false"<<nl;

       //  vector<int>visited(vtces, -1);
       // for (int i = 0; i < vtces; ++i)                                                                             //---------12th
       //  {
       //      if(visited[i]==-1){
       //          bool isCompBipartite = checkComponentBipartite(graph, i, visited);
       //          if(isCompBipartite== false){
       //            cout<<"false"<<nl;
       //            return 0;
       //          }
       //      }
       //  }

       //  cout<<"true"<<nl;

        // vector<int>visited(vtces, 0);
        // int time; cin>>time;
        // Spread_Infection(graph, src, visited, time);                           //---------13th


        //Dijkstra(graph, src, visited);                                            //---------14th
       // Prims(graph, visited);                                                 //---------15th




        //  int vtces;
        //   cin >> vtces;
        //   vector<Edge_No_wtt>graph[vtces];                                      //---------16th

        //   int edges;
        //   cin >> edges;
        //   for(int i = 0; i < edges; i++) {
        //       int v1 ;
        //       int v2 ;
        //       cin >> v1 >> v2;
        //       graph[v1].push_back( Edge_No_wtt(v1, v2));
        //   }
        //    vector<bool>visited(vtces, false);

        // stack<int> st;
        // for (int v = 0; v < vtces; ++v)
        // {
        //     if(visited[v]== false){
        //       topologicalSort(graph, v, visited, st);
        //     }
        // }
        // while(st.size()>0){
        //   cout<<st.top()<<endl;
        //   st.pop();
        // }





}

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

string swapp(string s, int i, int j){
    char s1= s[i];
    s[i]= s[j];
    s[j]= s1;
    return s;
}

int main(){

    string M_s="";
    for(int i = 0; i < 6; ++i)
    {
        
           char c;
           cin>>c;
           M_s.push_back(c);

    }
    
    // for 0 value, swap positions
    vector<vector<int>>SW={{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};


    //we want state {{1, 2, 3}, 4, 5, 0}} means string "123450"
    string ans="123450";
    set <string> vis;
    vis.insert(M_s);

    queue <string> q;
    q.push(M_s);
    int level=0;

    int flag=1;
    function <void()> bfs;  
    bfs = [&]()
    {
        while(q.size())
        {
            int size = q.size();

            while(size--)
            {
                string front = q.front();
                q.pop();

                if(front == ans)
                {
                    return ;
                }

                int pos_of_0=0;
                for (int i = 0; i < 6; ++i)
                {
                    if(front[i]=='0'){
                        pos_of_0=i;
                        break;
                    }
                }
                vector<int>swapidxs= SW[pos_of_0];
                for(int i=0; i<swapidxs.size(); i++){
                    string new_add_str= swapp(front, pos_of_0, swapidxs[i]);
                    if(vis.find(new_add_str)==vis.end()){
                        q.push(new_add_str);
                        vis.insert(new_add_str);
                    }

                }


            }
                
            level++;
        }
        flag=0;
    };

     bfs();
     if(flag) cout<<level<<nl;
     else cout<<"-1"<<nl;
}

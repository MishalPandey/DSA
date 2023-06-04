//By Topology Sort(Kahns algorithm)- GFG question
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int>graph[K];
        
        for(int i=0; i<N-1; i++)
        {
            string fs = dict[i];
            string sc = dict[i+1];
            
            for(int j=0; j< min(fs.size(), sc.size()); j++)
            {
                if(fs[j]==sc[j])
                {
                    continue;
                }
                else{
                    graph[fs[j]-'a'].push_back(sc[j]-'a');
                    
                    break;
                }
            }
            
        }
        
        vector<int>ordering;
        
        vector<int>indegree(K, 0);
        for(int i=0; i<K; i++)
        {
            for(auto child: graph[i])
            {
                indegree[child]++;
            }
        }
        
        queue<int>q;
        for(int i=0; i<K; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
            
        }
        
        
        while(q.size())
        {
            int ver = q.front();
            q.pop();
            
            ordering.push_back(ver);
            
            for(auto child: graph[ver])
            {
                indegree[child]--;
                
                if(indegree[child]==0)
                {
                    q.push(child);
                }
            }
            
            
        }
        set<int> for_remain_ch;
        for(int i=0; i<K; i++)
        {
            for_remain_ch.insert(i);
        }
        
        string ans="";
        for(auto it: ordering)
        {
            ans+= char('a' + it);
            for_remain_ch.erase(it);
        }
        for(auto it: for_remain_ch)
        {
            ans+= char('a' + it);
        }
        
        
        return ans;
        
        
        
    }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        graph = vector<vector<int>>(numCourses,vector<int>());
        in_degree = vector<int>(numCourses);
        
        //build a graph
        for(auto prerequisite : prerequisites){
            Add_Edge(prerequisite[1],prerequisite[0]);
        }
        top_sort(result);
        
        if(result.size() < numCourses) return { };
        
        return result;
        
    }
    
private:
    vector<vector<int>> graph;
    vector<int> in_degree;
    //x -> y
    void Add_Edge(int x, int y){
        graph[x].push_back(y);
        in_degree[y]++;
    }
    
    void top_sort(vector<int>& result){
        
        queue<int> No_need_pre;
        for(int i =0; i < in_degree.size(); i++){
            
            if(in_degree[i] == 0){
                No_need_pre.push(i);
            }
        }
        
        while(!No_need_pre.empty()){
            //取出对头
            int node = No_need_pre.front();
            result.push_back(node);
            No_need_pre.pop();
            //加入新的可修
            for(int a : graph[node]){
                in_degree[a]--;
                if(in_degree[a] == 0){
                    No_need_pre.push(a);
                }
                
            }
            
            
            
        }
        
    }
    
    
    
};
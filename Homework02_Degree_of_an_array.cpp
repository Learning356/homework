class Solution {
public:
    unordered_map<int,int> val_to_degree_map;
    unordered_map<int,vector<int>> val_to_indexes_map;
    int findShortestSubArray(vector<int>& nums) {
        int max_degree = 0;
        int min_len = nums.size();
        for(int i: nums){
            val_to_degree_map[i]++;
            max_degree = max(max_degree,val_to_degree_map[i]);
            
        }
        if(max_degree == 1) return 1;
        
        for (int i=0; i < nums.size(); i++){
            
            if(val_to_degree_map[nums[i]] == max_degree ){
                if(val_to_indexes_map.find(nums[i]) == val_to_indexes_map.end()) {
                    
                    val_to_indexes_map[nums[i]].push_back(max_degree);
                    val_to_indexes_map[nums[i]].push_back(i);
                    val_to_indexes_map[nums[i]].push_back(i);
                }
                else{
                    val_to_indexes_map[nums[i]].front()--;
                    val_to_indexes_map[nums[i]].back() = i;
                    if(val_to_indexes_map[nums[i]].front() == 1) 
                    {
                       min_len = min(min_len,val_to_indexes_map[nums[i]].at(2) - val_to_indexes_map[nums[i]].at(1) +1);   
                    }
                }
                                                                                                 
                                                                                                 
                                                                                                 }}
                         
                                                     
                                                                           
            
    
        return min_len;
        
    }
};
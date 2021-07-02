class Solution {
public:
    vector<bool> num_to_used;
    vector<int> sets;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        num_to_used.resize(nums.size());
        FindSubsets(nums,0);
        
        return ans;
    }
    
    void FindSubsets(vector<int>& nums, int index){
        if(index == nums.size()){
            ans.push_back(sets);
            return;
            
        }
        
        for(int i = 0; i < nums.size(); i++){
            
            if(i > 0 && nums[i] == nums[i-1] && !num_to_used[i-1] ) continue;
            if(!num_to_used[i]){
                sets.push_back(nums[i]);
                num_to_used[i] = true;
                FindSubsets(nums,index+1);
                sets.pop_back();
                num_to_used[i] = false;
            }
            
            
            
        }
        
    }
};
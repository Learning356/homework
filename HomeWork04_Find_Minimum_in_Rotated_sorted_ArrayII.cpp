class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //[1,2,2,2,3,6,7]
        //[2,2,3,6,7,1,2]
        //[1,1,2,4,5,0,0]
        int left = 0;
        int right = nums.size() - 1 ;
        
        while(left < right){
            int mid = (right + left  )/2;
            //cout << nums[mid] << " ";
            if(nums[mid] < nums[right]){
                right = mid;
            }
            //左右相等则右边左移，所以 最小数不会丢失
            else if(nums[mid] == nums[right]){
                right = right - 1;
            }
            else{
                left = mid +1;
            }
        }
        
        return nums[right];
        
    }
};
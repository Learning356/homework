class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ans_row = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m - 1;
        while(left < right){
            int mid = (left + right + 1)/2;
            
            if(matrix[mid][0] <= target){
                left = mid;
            }
            else{
                right = mid - 1;
            }
            
        }
        if(target < matrix[right][0] || target > matrix[right][n-1]) return false;
        ans_row = right;
        left = 0;
        right = n;
        while(left < right){
            int mid = (left + right)/2;
            if(matrix[ans_row][mid] >= target){
                right = mid;
            }
            else{
                left = mid + 1;
            }   
            
        }
        if(matrix[ans_row][right] == target) return true;
        //cout << right;
        return false;
    }
};
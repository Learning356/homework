class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int result = 0;
        if(m*k > bloomDay.size()) return -1;
        //假设 第n天恰好能制作m朵花
        // n --> 增大  则 m 增大
        //|    ___/
        //| __/
        //|/___
        // n 最大值为 max(bloomDay)
        // n 最小值为 min(bloomDay)
        // m 的目标值为 M
        // 限定条件：相邻的 k朵
        int min_Day = 1000000000;
        int max_Day = 0;
        for(int i : bloomDay){
            min_Day = min(min_Day,i);
            max_Day = max(max_Day,i);


        }
        if(m*k == bloomDay.size()) return max_Day;
        int left = min_Day;
        int right = max_Day;
        int target = m;
        while(left < right){
            int mid = (left + right)>>1;
            if(can_finsh_flowers(bloomDay,mid,k) >= target){
                right = mid;
            }
            else{
                left = mid + 1 ;
            }
        }
        return right;

        //can_finsh_flowers(bloomDay,3,2,1);


        
        //return result;


    }

    int can_finsh_flowers(vector<int>& bloomDay, int day_passed,int need_flowers){
        int flowers_we_have = 0;
        int bunch_we_have = 0;
        for(int i: bloomDay){
            if(i <= day_passed){
                ++flowers_we_have;
                if(flowers_we_have >= need_flowers){
                    ++bunch_we_have;
                    flowers_we_have = 0;

                }
            }
            else{
                flowers_we_have = 0;
            }
        }
        
        return bunch_we_have;


    }
};
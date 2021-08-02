class Solution {
public:
    int MAX = 1000000000;
    int minEatingSpeed(vector<int>& piles, int h) {

        //Speed : s
        //max(s) = max(piles # number of banana) when h = length of piles
        //min(s) = 0 / min(piles # number of banana)   when h = 10^9
        int left = 0;
        int right =0;
        for(int i : piles){
            right = max(right,i);

        }
        while(left < right){
            int mid = (left + right)>>1;
            if(time_need_in_a_speed(piles,mid) <= h){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
         

             return right;

    }

    int time_need_in_a_speed(vector<int>& piles,int speed){
        if(speed == 0) return MAX;
        int time = 0;
        for(int i : piles){
            if(i < speed){
                ++time;

            }
            else{
                time += i/speed;
                if( i%speed != 0) ++time;


            }
        }

        return time;



    }
};
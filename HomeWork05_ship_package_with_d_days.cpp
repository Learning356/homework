class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        //D 增大  最低运载能力在 减小
        //D 的最大值 为  weights.size() 最低运载能力即为 max(weights)
        //D 最小为  1  最低运载能力为 weights[i] 累加
        //target 值为五
        int left = 0;
        int right = 0;
        for(int i: weights){
            left = max(left,i);
            right += i;

        }
        while(left < right){
            int mid = (left + right)>>1;
            
            int need_day = days_with_load(weights,mid);
            //cout << "left: "<< left << " right: "<< right << " mid: "<<mid << " needday:  " << need_day << endl;
            if(need_day <= days ){
                right = mid;
            }
            else{
                left = mid + 1;
            }


        }
        //if(left == right) cout << "hello";
        
        return right;




    }

    int days_with_load(vector<int>& weights, int load){
        int weight = 0;
        int days = 0;
        for(int i = 0; i < weights.size(); i ++){
          //cout << weights[i];
          if(weight + weights[i] >= load){
              //cout << weight << " ";
              days++;
              if(weight + weights[i] == load) weight = 0;
              else{ weight = weights[i];  }
              //cout << endl;
              
          }
          else{

              weight+=weights[i];
          } 
            

        }
        if(weight != 0) ++days; 

        return days;
    }
};
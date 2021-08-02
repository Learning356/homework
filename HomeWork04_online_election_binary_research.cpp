class TopVotedCandidate {
public:
    unordered_map<int,int> time_index_to_best_candidate;
    vector<int> p;
    int N = 0;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        N = times.size();
        vector<int> candidate_to_tickets = vector<int>(5000,0);
        time_index_to_best_candidate[0] = persons[0];
        candidate_to_tickets[persons[0]]++;
        p = times;

        for(int i =1; i < times.size(); i++){
           candidate_to_tickets[persons[i]]++;
           if(time_index_to_best_candidate[i-1] != persons[i] && candidate_to_tickets[persons[i]] >= candidate_to_tickets[time_index_to_best_candidate[i-1]]){
               
               time_index_to_best_candidate[i] = persons[i];
           }
           else{
               time_index_to_best_candidate[i] = time_index_to_best_candidate[i-1];
           }
          //cout <<" candi: " <<persons[i] << " tick: "<<candidate_to_tickets[persons[i]] << endl;
          //cout << time_index_to_best_candidate[i] << " " << endl;

        }


    }
    
    int q(int t) {
        //int i = 0;
        if(t >= p.back()) return time_index_to_best_candidate[N-1];
        int left = 0;
        int right = N-1;
        while(left < right){
            int mid = (left + right)>>1;
            if(p[mid] >= t){
                right = mid;
            }
            else{
                left = mid+1;
            }
            
            
        }
        if(t != p[right]) right--;
        //cout << right << " ";
     
        
        //if(i != N - 1 && t == p[i+1] ) i = i + 1;
        //cout << i << " ";
        

        return time_index_to_best_candidate[right];

    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
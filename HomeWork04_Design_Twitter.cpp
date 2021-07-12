struct Node{
    int tweetId;
    int time;
    Node * next;
    Node(int tweetId, int time):tweetId(tweetId),time(time),next(nullptr){
        
    }
    
};

bool operator<(const Node& a, const Node& b){
    
    return a.time < b.time;
}
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
        userId_Node = vector<Node *>(501, nullptr);
        followers = vector<set<int>>(501,set<int>());
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ++time;
        Node* newnode = new Node(tweetId,time);
        if(userId_Node[userId] == nullptr){
           userId_Node[userId] = newnode; 
            //cout << tweetId << " " ;
        }
        else{
            Node* ptr = userId_Node[userId];
            Node* prev = nullptr;
            while(ptr != nullptr){
                prev = ptr;
                ptr = ptr->next; 
            }
            prev->next = newnode;
            
        }
        
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<Node *> top10;
        Node* node = userId_Node[userId];
        while(node != nullptr ){
            top10.push(node);
            node = node->next;
        }
        for(int follow : followers[userId]){
            //cout << follow << " ";
             node = userId_Node[follow];
             while(node != nullptr ){
                top10.push(node);
                 //cout << node->tweetId << " ";
                node = node->next;
            }
            
        }
        for(int i=0; i < 10; i++){
            if(top10.empty()) break;
            ans.push_back(top10.top()->tweetId);
            top10.pop();
        }
        
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        //follower and followeeid not existed
        //if(userId_Node[followerId] == nullptr ) return;
        
            //cout << "heelo";
            followers[followerId].insert(followeeId);
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
    if( followers[followerId].find(followeeId) == followers[followerId].end()) return;
        else{
           followers[followerId].erase(followeeId);
        }
        
    }
private:
    vector<Node*> userId_Node;
    vector<set<int>> followers;
    int time;
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
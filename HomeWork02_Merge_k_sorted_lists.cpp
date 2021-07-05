/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
       ListNode* tmp = nullptr;
       if(lists.size() == 0) return tmp;  
       return DivideAndConquer(lists,0,lists.size()-1);
       // return MergeTwo(lists[0],lists[1]);
        
    }
    
    ListNode* DivideAndConquer(vector<ListNode*>& lists, int begin, int end){
        if(begin == end) return lists[begin];
        if(end - begin == 1) return MergeTwo(lists[begin],lists[end]);
        int mid = (begin + end)/2;
        //cout << mid << " ";
        ListNode* begining = DivideAndConquer(lists,begin,mid);
        ListNode* ending = DivideAndConquer(lists,mid+1,end);
        
        
        
        return MergeTwo(begining,ending);
        
    }
    
    ListNode* MergeTwo(ListNode* list1, ListNode* list2){
        ListNode* head = nullptr;
        ListNode* tmp = nullptr;
        ListNode* SmallerNode = nullptr;
        ListNode* LargerNode = nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        if(list1->val <= list2->val){
            head = list1;
            //list1 = list1->next;
            SmallerNode = list1;
            LargerNode = list2;
            //cout << "list 1 is smaller" << endl;
        }
        else{
            head = list2;
            //cout << "list 2 is smaller" << endl;
            //list2 = list2->next;
            SmallerNode = list2;
            LargerNode = list1;
        }
        tmp = SmallerNode;
        while(SmallerNode != nullptr && LargerNode != nullptr){
           
           //在更小的那组找到一个更大的node
            while(SmallerNode->val <= LargerNode->val){
                tmp = SmallerNode;
                SmallerNode = SmallerNode->next;
                if(SmallerNode == nullptr){
                    tmp->next = LargerNode;
                    return head;
                    
                } 
            }
            
            ListNode * next = LargerNode->next;
            tmp->next = LargerNode;
            tmp = LargerNode;
            LargerNode->next = SmallerNode;
            LargerNode = next;
             
          
            
           
            
        }
        
        return head;
            
        
        //if(list1 == nullptr && list2 != nullptr)  
        
        
        
    }
};
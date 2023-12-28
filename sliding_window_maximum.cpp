class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans ;
        //create dequeue
        deque<int>dq;
        
        //first k element ka maximumum find krenge
        for(int index=0;index<k;index++){
            int element=nums[index];
           
            while((!dq.empty())&&nums[dq.back()]<=element){
                dq.pop_back();
            }
            dq.push_back(index);
            
        }
        //remaining window ko process krenge
        //removal && addition
        for(int index=k; index<n;index++){
           //ans store krenge
            ans.push_back(nums[dq.front()]);
            
        
            //remove out of range index
            if((!dq.empty())&&(index-dq.front()>=k)){
                  dq.pop_front();
             }
             //chhote element pop kardo
            int element=nums[index];
            while((!dq.empty())&&(element >nums[dq.back()])){
               dq.pop_back();
           
              }
              //addition
              dq.push_back(index);
        }
      if(!dq.empty()){
          ans.push_back (nums[dq.front()]);
       }
        return ans;
    }
};
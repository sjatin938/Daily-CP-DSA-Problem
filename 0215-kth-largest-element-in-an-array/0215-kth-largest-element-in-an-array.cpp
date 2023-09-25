class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       if(nums.size()<k)
        return 0;

        priority_queue<int>pq;
        for(int i =0 ; i < nums.size() ; i++){
            pq.push(-nums[i]);
          if(pq.size()>k)
            pq.pop();  
        } 
        return -pq.top();
    }
};
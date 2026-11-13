class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start  = 0;
        int last  = n-1;
        while(start <= last){
            int mid = start + (last-start)/2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]){
                start = mid+1;
            }else if(target < nums[mid]) {
                last = mid-1;
            }
        }
        return -1;
    }
};

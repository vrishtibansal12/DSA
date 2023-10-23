class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return nums[0];

        stack<int> st; 
        vector<int> left(n), right(n);

        #pragma unroll
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) 
                st.pop();
            left[i]=st.empty()? -1:st.top();
            st.push(i);
        }

        st={};  
        #pragma unroll
        for (int i = n-1; i>= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()])
                st.pop();
            right[i] = st.empty()?n:st.top();
            st.push(i);
        }

        int ans= 0;
        #pragma unroll
        for (int i = 0; i < n; i++) {
            if (left[i] < k && right[i] > k) {
                ans=max(ans, nums[i]*(right[i]-left[i]-1));
            }
        }

        return ans;
    }
};

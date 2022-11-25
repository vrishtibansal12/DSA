class Solution {
public:
    const int MOD = 1e9 + 7; 
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(); 
        int dp[n]; 
        dp[0] = arr[0]; 
    
        stack<int> stk; 
        int smaller[n]; 
        for(int i = 0; i<n; ++i){
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop(); 
    
            if(stk.empty())
                smaller[i] = -1; 
    
            else
                smaller[i] = stk.top();
            stk.push(i); 
        }
	
        for(int i = 1; i<n; ++i){
            if(smaller[i] == -1)
                dp[i] = ((i+1)*arr[i])%MOD; 
            else
                dp[i] = (((i - smaller[i])*arr[i])%MOD + dp[smaller[i]])%MOD; 
        }
    
        int ans = 0; 
        for(int i = 0; i<n; ++i)
            ans = (ans + dp[i])%MOD;    
        
        return ans; 
    }
};
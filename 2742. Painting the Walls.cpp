class Solution {
private:
    vector<int> prev,curr;
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        prev.resize(n+1,1e9);
        prev[0]=0;
        curr.resize(n+1,0);
        for(int idx=1;idx<=n;++idx) {
            for(int rem=1;rem<=n;++rem) {
                int take=cost[idx-1]+prev[max(0,rem-1-time[idx-1])];
                int notTake=prev[rem];
                curr[rem]=min(take,notTake);
            }
            prev=curr;
        }
        return prev[n];
    }
};
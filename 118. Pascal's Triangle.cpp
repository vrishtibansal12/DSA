class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=1;i<=numRows;i++){
            vector<int> ds;
            for(int j=1;j<=i;j++){
                if(j==1 || i-j==0)
                    ds.push_back(1);
                else
                    ds.push_back(ans[i-2][j-1]+ans[i-2][j-2]);
            }
            // for(int k=0;k<ds.size();k++)
            //     cout<<ds[k]<<",";
            // cout<<endl;
            ans.push_back(ds);
        }
        return ans;
    }
};
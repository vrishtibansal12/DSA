class Solution {
public:
    int findKthPositive(vector<int>& arr, int n) {
        int k=1,x=0,i;
        for (i=0;i<arr.size();){
            if(arr[i]==k){
                i++;
                k++;
            }
            else{
                cout<<k<<" ";
                x++;
                if(x==n)
                    return k;
                k++;
            }
        }
        return arr[i-1]+(n-x);
    }
};
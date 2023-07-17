class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        
        // [0,i] => non-zeros, [i+1,j-1] => zeros, [j,n-1] => undefined region
        int i=-1, j=0;
        while(j<n){
            if(a[j] != 0){
                i++; // expanding range for non-zeros
                swap(a[i],a[j]);
            }
            j++;
        }
    }
};
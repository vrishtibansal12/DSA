class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=INT_MIN,count1=0,num2=INT_MIN,count2=0;
        
        for(int i=0;i<nums.size();i++){
            if(num1==nums[i])
                count1++;
            else if(num2==nums[i])
                count2++;
            else if(count1==0){
                num1=nums[i];
                count1++;
            }
            else if(count2==0){
                num2=nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int c=nums.size()/3, m=0,n=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1)
                m++;
            if(nums[i]==num2)
                n++;
        }
        if(m>c)
            ans.push_back(num1);
        if(n>c)
            ans.push_back(num2);
        return ans;
    }
};
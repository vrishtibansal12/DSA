class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        char c;
        for (auto i : mp) {
            if (i.second > maxi) {
                maxi = i.second;  
                c = i.first;  
            }
        }
        
        if (maxi > (s.size() + 1) / 2) {
            return ""; 
        }
        string ans(s.size(), ' '); 
        int idx = 0;
        
        while (mp[c] > 0) {
            ans[idx] = c;  
            idx += 2;
            mp[c]--;
        }
        
        for (auto i : mp) {
            while (i.second > 0) {
                if (idx >= s.size()) {
                    idx = 1; 
                }
                ans[idx] = i.first;  
                idx += 2;
                i.second--; 
            }
        }
        
        return ans;
    }
};
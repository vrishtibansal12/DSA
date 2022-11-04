class Solution {
public:
    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ) 
            if ((i=s.find_first_of("aeiouAEIOU", i)) < (j=s.find_last_of("aeiouAEIOU", j)))
              swap(s[i++], s[j--]);
        
        return s;
    }
};
class Solution {
public:
    int calculate(string s) {
        long res = 0;
        long num = 0;
        stack<bool> st;
        bool sub = false, cumsub = false;
        for (int i = 0; i < s.size(); ++i){
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (s[i] == '+' || s[i] == '-') {
                res += (cumsub ^ sub)? -num : num;
                num = 0;
                sub = (s[i] == '-')? true : false;
            } else if (s[i] == '(') {
                cumsub ^= sub;
                st.push(sub);
                sub = false;
            } else if (s[i] == ')') {
                res += (cumsub ^ sub)? -num : num;
                num = 0;                
                cumsub ^= st.top(); st.pop();
                sub = false;
            }
        }
        
        res += (cumsub ^ sub)? -num : num;
        
        return res;
    }
};
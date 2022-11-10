class Solution {
public:
    string removeDuplicates(string s) {
        int f=0;
        for(int i=0;i<s.length();){
               // cout<<(s[i]==s[i+1]);
                if(s[i]==s[i+1]){
                    f=1;
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + i);
                    //cout<<s<<endl;
                    if(i>0)
                        i--;
                }

                else
                    i++;
                if(i==s.length()-1 && f==1){
                    i=0;
                    f=0;
                }
            }
        return s;
    }
};

class Solution {
public:
    int maxDepth(string s) {

        stack <char> ss;

        int c=0;

        for(int i=0;i<s.size();i++){

            if(s[i]=='('){
                ss.push(s[i]);
                int a=ss.size();
                c=max(c,a);
            }

            else if(s[i]==')'){
                ss.pop();
            }


        }

        return c;
        
    }
};
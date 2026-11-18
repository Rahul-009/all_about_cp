// backspace string compare (leetcode 844)
    bool backspaceCompare(string s, string t) {
        stack<char> stk_s;
        stack<char> stk_t;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '#'){
                if(stk_s.empty()) continue;
                stk_s.pop();
                continue;
            }
            stk_s.push(s[i]);
        }

        for(int i=0; i<t.size(); i++){
            if(t[i] == '#'){
                if(stk_t.empty()) continue;
                stk_t.pop();
                continue;
            }
            stk_t.push(t[i]);
        }

        if(stk_s.size() != stk_t.size()) return 0;

        while(!stk_s.empty() ){
            if(stk_s.top() != stk_t.top()){
                return 0;
            }
            stk_s.pop(); stk_t.pop();
        }
        return 1;
    }
// 
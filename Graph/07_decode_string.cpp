#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/decode-string/description/

class Solution {
public:
    string decodeString(string s) {
        stack<char>word;

        for(int i=0; i<s.size(); i++){
            if(s[i] != ']'){
                word.push(s[i]);
            }
            else{
                string curr_str = "";
                while(!word.empty() and word.top() != '['){
                    curr_str += word.top();
                    word.pop();
                }

                if(!word.empty() and word.top() == '['){
                    word.pop();
                }
                reverse(curr_str.begin(), curr_str.end());
                
                int num = 0, val = 1;
                while(!word.empty() and word.top()>='0' and word.top()<='9'){
                    num = num + val*(word.top()-'0');
                    word.pop();
                    val *= 10;
                }

                while(num>0){
                    for(int j=0; j<curr_str.size(); j++){
                        word.push(curr_str[j]);
                    }
                    num--;
                }
            }
        }

        string ans = "";
        while(!word.empty()){
            ans += word.top(); word.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    

    return 0;
}
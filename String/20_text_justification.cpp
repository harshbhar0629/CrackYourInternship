#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n = words.size();
        int i=0;
        
        while(i<n){
            int j = i+1;
            int len = words[i].size();
            int spaces = 0;
            while(j<n and len + spaces + words[j].length()+1 <= maxWidth){
                spaces++;
                len += words[j].size();
                j++;
            }

            int remainingSpaces = maxWidth - len;
            int evenlySpaces = (spaces==0)? 0: remainingSpaces / spaces;
            int extraSpaces = (spaces==0)? 0: remainingSpaces % spaces;

            if(j==n){
                extraSpaces = 0;
                evenlySpaces = 1;
            }

            string lines = "";
            for(int k=i; k<j; k++){
                lines += words[k];
                if(k==j-1){
                    break;
                }

                for(int l=0; l<evenlySpaces; l++){
                    lines += ' ';
                }

                if(extraSpaces>0){
                    lines += ' ';
                    extraSpaces--;
                }
            }

            while(lines.length() < maxWidth){
                lines += ' ';
            }
            ans.push_back(lines);

            i=j;
        }

        return ans;
    }
};

int main(){
    

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        int n = secret.length();
        vector<int> sec(10,0),gs(10,0);
        
        for(int i=0;i<n;i++){
            char ch1 = secret[i], ch2 = guess[i];
            if(ch1==ch2) bulls++;
            else{
                sec[ch1-'0']++, gs[ch2-'0']++;
            }
        } 
        for(int i=0;i<10;i++){
            cows += min(sec[i],gs[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
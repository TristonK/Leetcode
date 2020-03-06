//滑动窗口

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.length()){
            return 0;
        }
        int chara[128];
        memset(chara,-1,sizeof(chara));
        int index = 0, end_index=0;
        int longestLength = 0;
        for(int i=0;i<s.length();i++){
            int charToNum = (int)s[i];
            if(chara[charToNum]==-1 || chara[charToNum]<index){
                chara[charToNum]=i;
                end_index=i;
            }else{
                if(end_index-index+1>longestLength){
                    longestLength = end_index - index + 1;
                }
                index = chara[charToNum]+1;
                chara[charToNum] = i;
                end_index = i;
            }
        }
        if(end_index-index+1>longestLength){
            longestLength = end_index - index + 1;
        }
        return longestLength;
    } 
};
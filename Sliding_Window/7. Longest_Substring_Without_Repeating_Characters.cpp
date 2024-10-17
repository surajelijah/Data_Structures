// URL - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/



/*

Idea here is to 

    - Window size - Count
    - Window size > count - Means we have duplicates
    - Window size < count - Add more elements



    The following template works in most of the Varibale sized window cases, when asekd for long but try for min also


*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        

        int ans=0,count;

        int i=0,j=0,n=s.length();

        map<char,int> mp;

        if(n==0)
            return 0;
        
        ans=1; // Adding the first element and considering the answer to be 1 as first element is addded
        mp[s[0]]=1;
        count=1;


        while(j<n){

            while(i<=j && (j-i+1)>count){
                
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                        count--;
                    }
                }
                i++;
            }

            if((j-i+1)==count) // We are matching if the window size is equal to map size, if it is we are sure that we have all unique characters in the substring
                ans=max(ans, (j-i+1)); 

            j++; // Adding the next element
            if(j<n){
                if(mp.find(s[j])==mp.end()){
                    mp[s[j]]=1;
                    count++;
                }
                else
                    mp[s[j]]++;
            }
        }
        return ans;
    }
};




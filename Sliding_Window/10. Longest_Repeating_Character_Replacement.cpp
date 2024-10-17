// URL - https://leetcode.com/problems/longest-repeating-character-replacement/description/


/*

Here we have an idea where we have a dominant count and non dominant count, where if the non dominant count
is within our k then we can change them into the dominant characters, that is the idea.

*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        

        int n=s.length();

        int i=0,j=0;

        int ans=0;
        int dominant_char_count=0, non_dominant_char_count=0;

        map<char,int> mp;

        mp[s[0]]=1;
        dominant_char_count=1;

        while(j<n){

            while(i<=j && non_dominant_char_count > k){
                
                mp[s[i]]--;

                dominant_char_count=0;
                
                i++;

                // Calculate the max in the now current elements in the map
                for(auto item: mp){
                    dominant_char_count = max(dominant_char_count,item.second);
                }
                non_dominant_char_count= (j-i+1) - dominant_char_count;
            }

            if(non_dominant_char_count<=k){
                ans=max(ans,(j-i+1));
            }

            j++;
            if(j<n){
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]++;
                }
                else{
                    mp[s[j]]=1;
                }
                dominant_char_count=max(dominant_char_count,mp[s[j]]);
                non_dominant_char_count= (j-i+1) - dominant_char_count; // Window size  - dominant_char_count
            }

        }
        return ans;
    }
};

/* Optimal Solution - Here we try to optimize the scenario where we are checking the map everytime we shrink
the elements, like how we do this. We do this using the if condition rather than while.


class Solution {
public:
    int characterReplacement(string s, int k) {
        

        int n=s.length();

        int i=0,j=0;

        int ans=0;
        int dominant_char_count=0, non_dominant_char_count=0;

        map<char,int> mp;

        mp[s[0]]=1;
        dominant_char_count=1;

        while(j<n){

            if(i<=j && non_dominant_char_count > k){
                
                mp[s[i]]--;

                dominant_char_count=mp[s[i]];
                
                i++;

                // Calculate the max in the now current elements in the map
                /*for(auto item: mp){
                    dominant_char_count = max(dominant_char_count,item.second);
                }
                non_dominant_char_count= (j-i+1) - dominant_char_count;
            }

            if(non_dominant_char_count<=k){
                ans=max(ans,(j-i+1));
            }

            j++;
            if(j<n){
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]++;
                }
                else{
                    mp[s[j]]=1;
                }
                dominant_char_count=max(dominant_char_count,mp[s[j]]);
                non_dominant_char_count= (j-i+1) - dominant_char_count; // Window size  - dominant_char_count
            }

        }
        return ans;
    }
};

*/







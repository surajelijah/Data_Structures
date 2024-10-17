// URL - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

// https://www.youtube.com/watch?v=xtqN4qlgr8s&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=7

/*

    Here we are asked to count the number of substrings rather than the longest or smallest, so the concept
    of shrinking and expanding won't work, we need to go for some other strategy but similar.


    Here the idea is to find the valid substring that ends at the current index. Watch the video


*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n=s.length();

        int mp[3]={-1,-1,-1}; // In this we store the last scene index of that character

        // Once we have indexes for all of them it means we have encountered a valid substring at that index

        // So now we go to the start of the valid string which is minimal, that is the index of the character whose index is minimal.

        // Then from there whatever elements are behind it can be added to form a substring

        int i=0,j=0;

        int ans=0,minimal_index;

        while(i<n){

            mp[s[i]-'a']=i;

            if(mp[0]!=-1 && mp[1]!=-1 && mp[2]!=-1){
                
                minimal_index=mp[0];
                for(int z=0;z<3;z++)
                    minimal_index=min(minimal_index,mp[z]); 
                //This means the start of the minimal valid window

                ans+= (minimal_index +1);
            }

            i++;
        }
        
        return ans;
    }
};



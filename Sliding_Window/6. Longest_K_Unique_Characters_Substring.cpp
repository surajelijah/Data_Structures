// URL - https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1



class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
    // In this question the substring should have K unique characters thats all, not characters with each count =1
    
    int n=s.length();
    int i=0,j=0,ans=0;
    
    map<char,int> mp;
    
    mp[s[0]]=1; //Added the first element in the map
    
    while(j<n){
        
        while(i<=j && mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0)
                mp.erase(s[i]);
            i++;
        }
        
        if(mp.size()==k)
            ans=max(ans, (j-i+1));
            
        j++;
        if(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]++;
            }
            else{
                mp[s[j]]=1;
            }
        }
    }
    if(ans==0)
        return -1;
    return ans;
    }
};


//Similar Problem - Pick Toys - https://www.youtube.com/watch?v=seOKHXB_w74&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj&index=12
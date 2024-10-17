//URL - https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1



/*

Now in this questiion it was not that obvious but we can easily figure it out


- The pat string's size is the size of the window, why because we need anagrams and anagrams must be of same size and we need to keep track of the characters encountered
  in a map and ask if those characters mathc the pat string

- For that we use the Map

*/


class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    int i=0,j=0;
	    
	    int n=txt.length();
	    int k=pat.length();
	    
	    int ans_count=0;
	    
	    
	    int count =0;
	    
	    int mp[26]={0};
	    
	    for(auto i: pat)
	        mp[i-'a']+=1; // This basically counts the occurences of letters in pat
	    
	    for(int i=0;i<26;i++)
	        if(mp[i]!=0)
	            count++;    // This is the number of distinct elements in pat
	    
	    
	    while(j<n){
	        
	       mp[txt[j]-'a']--;
	            
	       if(mp[txt[j]-'a']==0)
	            count--; // Meaning we have used all the occurences of this single element
	            
	       if( (j-i+1) < k)
	            j++;
	            
	       else if( (j-i+1) == k){
	           
	           if(count==0)
	                ans_count++; // Update answer, here it means in this window we have all the characeters as the count is 0
	           
	           mp[txt[i]-'a']++; //Increase the frequency of the characcter in the map
	           
	           if(mp[txt[i]-'a']==1) //If it is changing from 0 increse the count of elements
	                count++;
	             
	           i++;
	           j++;
	       }
	        
	    }
	    
	    return ans_count;
	}

};
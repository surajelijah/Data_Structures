//URL - https://leetcode.com/problems/remove-k-digits/


/*

Use the stack and try to maintain small elements on the stack

*/


class Solution {
public:
    string removeKdigits(string nums, int k) {
        
        // Idea is to remove the greater elements and use the lower digits to form the number
        int n=nums.length();

        stack<char> s;

        if(k>=n)
            return "0";

        string ans("");
        int i=0;
        while(i<n && k>0){
            if(s.empty())
                s.push(nums[i]);
            else{
                if(s.top()>nums[i]){ // Pop all the elements until top is <= current, why because we want the elemets to be small, when top > current
                    while(!s.empty() && s.top()>nums[i] && k){
                        s.pop();
                        k--;
                        }
                    s.push(nums[i]);
                }
                else{ // Push if the top is < current
                    s.push(nums[i]);
                }
            }
            i++;
        }
        vector<char> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }

        reverse(v.begin(),v.end());

        for(auto i : v)
            ans+=i;
        
        for(int j=i;j<n;j++) // Adding all the elemetns in nums if there are any 
            ans+=nums[j];
        
        string t_ans="";
        if(k!=0){ // remove the last digits if k!=0
            for(int a=0;a<ans.length()-k;a++)
                t_ans+=ans[a];
        }
        else
            t_ans=ans;

        //Removing the leading zeroes

        i=0;
        int m=t_ans.length();

        while(i<m){
            if(t_ans[i]!='0')
                break;
            i++;
        }

        string ans_="";

        for(int a=i;a<m;a++)
            ans_+=t_ans[a];

        if(ans_=="")
            return "0";

        return ans_;
    }
};
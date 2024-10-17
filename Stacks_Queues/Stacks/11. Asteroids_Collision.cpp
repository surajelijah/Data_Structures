// URL - https://leetcode.com/problems/asteroid-collision/submissions/1418530198/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n=asteroids.size();

        vector<int> v;
        stack<int> st;
        int k=0;
        
        while(k<n){

            if(st.empty()){
                st.push(asteroids[k]);
                k++;
            }
            else{
                if(asteroids[k]<0 && st.top()>0){
                    if(abs(asteroids[k]) == st.top()){
                        st.pop();
                        k++;
                    }
                    else if(abs(asteroids[k])< st.top()){
                        k++;
                        continue;
                    }
                    else{
                        if(!st.empty() && st.top()< abs(asteroids[k]))
                            st.pop();
                    }
                }
                else{
                    st.push(asteroids[k]);
                    k++;
                }
            } 
        }
        while(!st.empty()){
                v.push_back(st.top());
                st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
//URL - https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

// Floor - largest number in array such that <= target

class Solution {
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {

        // Your code here
        long long target=x;
        
        long long low=0;
        long long high=n-1;
        
        if(target<v[0]){
            return -1;
        }
        
        if(target>v[n-1])
            return n-1;
            
        long long mid;
        
        while(low<=high){
            
            mid= low+ (high - low)/2;
            if(v[mid]>=target)
                high=mid-1;
            else
                low=mid+1;
        }
        if(v[low]==target)
            return low;
        
        return low-1;
    }
    
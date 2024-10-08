//URL - https://www.naukri.com/code360/problems/lower-bound_8165382

// Lower bound is the smallest index, which satisfies the arr[i]>=target.
// Meaning the first index where we find the target's closer lower bound

int lowerBound(vector<int> arr, int n, int target) {
	// Write your code here
	
	int low=0;
    int high=n-1; // n is the size of the array
    
    int ans= n; // Hypothetical answer
    int mid;
    
    
    while(low<=high){
        mid = low + (high - low)/2;
        
        if(arr[mid]>=target){
            high = mid -1;
            ans=mid;
        }
        else
            low=mid+1;
            
    }
    
    return ans;

    // int arr = lower_bound(arr.begin(),arr.end(),target);
}







    /*
    
    // Lower Bound - Find the smallest index such that arr[index]>=target
    
    int low=0
    int high=n; // n is the size of the array
    
    int ans= n; // Hypothetical answer
    int mid;
    
    
    while(low<=high){
        mid = low + (high - low)/2;
        
        if(arr[mid]>=target){
            high = mid -1;
            ans=mid;
        }
        else
            low=mid+1;
            
    }
    
    return ans;
    
    // or use the function 
    
        int arr = lower_bound(arr.begin(),arr.end(),target);
        


};
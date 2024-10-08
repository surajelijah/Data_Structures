

// Upper Bound - Find the largest index such that arr[index]>target

int upperBound(vector<int> arr, int n, int target) {
	// Write your code here
	
	int low=0
    int high=n; // n is the size of the array
    
    int ans= n; // Hypothetical answer if there is no answer
    int mid;
    
    
    while(low<=high){
        mid = low + (high - low)/2;
        
        if(arr[mid]>target){
            high = mid -1;
            ans=mid;
        }
        else
            low=mid+1;
            
    }
    
    return ans;

    // int arr = upper_bound(arr.begin(),arr.end(),target);
}
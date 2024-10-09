//URL - https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m=matrix.size();
        int n=matrix[0].size();

        vector<int> v;

        for(int i=0;i<m;i++)
            v.push_back(matrix[i][0]);

        int low_index= lower_bound(v.begin(),v.end(),target) - v.begin();

        
        // The below checks are because we used the above function 

        if(low_index<m && matrix[low_index][0]==target) 
            return true;

        if(low_index==m || (low_index>0 && low_index<m))
            low_index--;

        return binary_search(matrix[low_index].begin(),matrix[low_index].end(),target);
    }
};




class Solution { // Solution where we treat the 2D as a iD array and search, this is Nice
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int r = arr.size();
        int c = arr[0].size();
        int s = 0, e = r*c-1;
        while(s<=e) {
            int mid = (s+e)/2;
            int midEle = arr[mid/c][mid%c]; // Very Nice, intuitive but better to remember
            if(target == midEle) return true;
            else if(target < midEle) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return false;
    }
};
// URL - https://leetcode.com/problems/find-a-peak-element-ii/

class Solution {

private:

int find_max(vector<vector<int>>& mat,int col,int rows){

    int max_value=-1;
    int index=-1;

    for(int i=0;i<rows;i++){
        if(mat[i][col]>max_value){
            max_value=mat[i][col];
            index=i;
        }
    }
    return index;
}

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m=mat.size();
        int n=mat[0].size();

        int low=0;
        int high=n-1;
        int mid;
        while(low<=high){

            mid= low + (high -low)/2;

            int index =find_max(mat,mid,m);

            //You need not check for up and down as we are getting the max in the column
            int left= (mid-1 >=0)? mat[index][mid-1]:-1;
            int right= (mid+1 <n)? mat[index][mid+1]:-1;

            if(mat[index][mid] > left && mat[index][mid] > right){
                return {index,mid};
            }
            else if(mat[index][mid]< left)
                high=mid-1;
            else
                low=mid+1;
        }
    return {-1,-1};
    }
};
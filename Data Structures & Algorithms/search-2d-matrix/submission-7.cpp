class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;
        int low = 0;
        int high = matrix.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(matrix[mid][0] == target || matrix[mid][matrix[mid].size()-1] == target){
                return true;
            }
            if(matrix[mid][0] < target && matrix[mid][matrix[mid].size()-1] > target){
                row = mid;
                break;
            }
            if(matrix[mid][0] > target){
                high = mid-1;
            }else if(matrix[mid][matrix[mid].size()-1] < target){
                low = mid+1;
            }
        }
        if(row == -1) return false;
        low = 0;
        high = matrix.size()-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(matrix[row][mid] == target) return true;
            if(matrix[row][mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};

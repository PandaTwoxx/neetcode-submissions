class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        right[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            left[i] = left[i-1];
            if(height[i] > left[i]) {
                left[i] = height[i];
            }
        }

        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1];
            if(height[i] > right[i]) {
                right[i] = height[i];
            }
        }

        int res = 0;

        for(int i = 0; i < n; i++){
            res += min(left[i], right[i]) - height[i];
        }

        return res;
    }
};

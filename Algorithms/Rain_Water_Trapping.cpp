class Solution {
public:
    int trap(vector<int>& a) {
        int ans = 0;
        int leftmax = INT_MIN;        
        int rightmax = INT_MIN;
        int i = 0;
        int j = a.size()-1;
        while(i<=j)
        {
            if(leftmax<=rightmax)
            {
                if(a[i]>leftmax)
                    leftmax = a[i];
                ans += (leftmax-a[i]);
                i++;
            }
            else
            {
                if(a[j]>rightmax)
                    rightmax = a[j];
                ans += (rightmax-a[j]);
                j--;
            }
        }
        return ans;
    }
};

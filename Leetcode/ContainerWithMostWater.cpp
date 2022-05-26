class Solution {
public:
    int maxArea(vector<int>& a) {
        // https://leetcode.com/problems/container-with-most-water/
int i=0,j=a.size()-1;
        int maxi=INT_MIN;
        // int mini=INT_MAXI;
        while(i<=j)
        {

            if(a[i]>=a[j])
            {
               maxi=max(maxi,a[j]*(j-i));
                j--;
            }
            else{
                maxi=max(maxi,a[i]*(j-i));
                i++;
            }
        }
        return maxi;
    }
};
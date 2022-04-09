// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
vector<int> getSumAbsoluteDifferences(vector<int> &nums)
{
    int n = nums.size();
    vector<int> arr(n);
    int sum = 0;
    vector<int> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    arr[0] = prefix[n - 1] - n * nums[0];
    for (int i = 1; i < n; i++)
    {
        int nextSum = (prefix[n - 1] - prefix[i]) - (n - 1 - i) * nums[i];
        int prevSum = nums[i] * i - prefix[i - 1];
        arr[i] = prevSum + nextSum;
    }
    return arr;
}
class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int ans = INT_MAX;
        unordered_map<int,int> ump;

        int sum = 0;
        ump[0]=sum;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            ump[sum]=i+1;
        }
        sum = 0;
        if(ump.find(x)!=ump.end())
        {
            ans = min(ans,ump[x]);
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            sum+=nums[i];
            if(sum>x)
                break;
            
            int t = x - sum;
            if(ump.find(t)!=ump.end())
            {
                int index = ump[t];
                if(index-1 < i)
                {
                    int op = (nums.size()-i)+index;
                    ans= min(ans,op);
                }
            }
        }

        if(ans==INT_MAX)
            return -1;
        return ans;
            
    }
};
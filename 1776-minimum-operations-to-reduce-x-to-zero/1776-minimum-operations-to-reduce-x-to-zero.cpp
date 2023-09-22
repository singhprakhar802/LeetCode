class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int ans = INT_MAX;
        unordered_map<int,int> ump;
        unordered_map<int,int> ump2;

        int sum = 0;
        ump[sum]=0;
        ump2[sum]=0;
        for(int i =0;i<nums.size();i++)
        {
            sum+=nums[i];
            ump[sum]=i+1;
        }
        sum = 0;
        for(int i = nums.size()-1;i>=0;i--)
        {
            sum+=nums[i];
            ump2[sum]=(nums.size()-i);
            // cout<<sum<<endl;
            if(sum>x)
            {
                break;
            }

            int t = x - sum ;

            if(ump.find(t)!=ump.end())
            {
                cout<<"reached "<<sum<<endl;
                int index = ump[t];
                if(index-1 < i)
                {
                    int op = (nums.size()-i+index);
                    cout<<op<<endl;
                    ans = min(ans,op);
                }
            }
        }
        sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>x)
            {
                break;
            }
            int t = x - sum ;
            if(ump2.find(t)!=ump2.end())
            {
                // cout<<"reached "<<sum<<endl;
                int index = ump2[t];
                if(i < (nums.size()-index))
                {
                    int op = (i+1 +index);
                    cout<<op<<endl;
                    ans = min(ans,op);
                }
            }
        }
        if(ans==INT_MAX)
        return -1;
        else
        return ans;
            
    }
};
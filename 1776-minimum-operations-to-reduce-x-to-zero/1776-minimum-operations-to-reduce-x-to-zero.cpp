class Solution {
public:


    int find(vector<int>& psum ,int t)
    {
        int s = 0;
        int e = psum.size()-1;
        while(s <= e)
        {
            int mid = (s+e)/2;

            if(psum[mid]==t)
                return mid;
            else if(psum[mid] > t)
            {
                e = mid -1;
            }
            else
            {
                s = mid+1;
            }
        }
        return -1;
    }
    int minOperations(vector<int>& nums, int x) 
    {
        int ans = INT_MAX;

        vector<int> psum ;
        int sum = 0;
        psum.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            psum.push_back(sum);
        }
        int op1 = find(psum,x);
       cout<<op1<<endl;
        if(op1!=-1)
            ans = min(ans,(op1));

        sum = 0;
        for(int i = nums.size()-1;i>=0;i--)
        {
            sum+=nums[i];
            if(sum>x)
                break;

            int t = x - sum;

            int index = find(psum,t);
            // cout<<index<<" "<<sum<<endl;
            if(index!=-1 && index-1 < i)
            {
                int op = (nums.size()-i)+index;
                ans=min(ans,op);
            }
        }

        // cout<<psum[2]<<endl;
        if(ans==INT_MAX)
            return -1;
        return ans;
            
    }
};
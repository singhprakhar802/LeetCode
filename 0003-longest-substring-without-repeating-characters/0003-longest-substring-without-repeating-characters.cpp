class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char,int> ump;
        int j=0;
        int i;
        int ans = INT_MIN;
        for( i =0;i<s.size();i++)
        {
            if(ump.find(s[i])!=ump.end())
            {
                break;
            }
            else
            {
                ump[s[i]]=i;
            }
        }
        ans = max(ans, (i-j));
        while(i<s.size())
        {
            if(ump.find(s[i])!=ump.end())
            {
                while(j<=ump[s[i]])
                {
                    ump.erase(s[j]);
                    j++;
                }
                ump[s[i]]=i;
                i++;
            }
            else
            {
                ump[s[i]]=i;
                ans=max(ans,(i-j+1));
                i++;
            }
        }
        return ans;
    }
};
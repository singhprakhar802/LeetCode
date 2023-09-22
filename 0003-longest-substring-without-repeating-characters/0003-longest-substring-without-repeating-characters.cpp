class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int ans = 0;
        int j = 0;
        int i;
        for(i = 0;i<s.size();i++)
        {
            if(st.find(s[i])!=st.end())
            {
                while(st.find(s[i])!=st.end())
                {
                    auto it = st.find(s[j]);
                    st.erase(it);
                    j++;
                }
                st.insert(s[i]);
            }
            else
            {
                st.insert(s[i]);
                int t = st.size();
                ans = max(ans , t);
            }
        }
        return ans;
    }
};
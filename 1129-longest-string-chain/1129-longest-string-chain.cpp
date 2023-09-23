class Solution {
public:

    unordered_map<string,int> dp;
    bool ispre(string a,string b)
    {
        if(b.size()-a.size()==1)
        {
            int i = 0;
            int j = 0;
            while(i<a.size() && j<b.size())
            {
                if(a[i]==b[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }
            }
            if(i==a.size())
                return true;
            else
                return false;
        }
        else
            return false;
    }
    int sol(string s,unordered_map<int,vector<string>>& ump)
    {
        
        int l = s.size();
        if(ump.find(l+1)==ump.end())
            return 1;
        
        // cout<<s<<"\n";
        if(dp.find(s)!=dp.end())
        {
            return dp[s];
        }
        else
        {
            int ans = 1;
            int ss = ump[l+1].size();
            // cout<<ss<<" "<<endl;
            for(int i=0;i<ss;i++)
            {
                string temp = ump[l+1].at(i);
                if(ispre(s,temp))
                {
                    cout<<"reached"<<endl;
                    cout<<temp<<endl;
                    int t = 1+sol(temp,ump);
                    ans = max(t,ans);
                }
            }
            // cout<<s<<"\t"<<ans<<endl;
            dp[s]=ans;
            return ans;
        }
    }
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<int,vector<string>> ump;

        for(int i=0;i<words.size();i++)
        {
            ump[words[i].size()].push_back(words[i]);
        }
        int fans = 0;
        for(int i=0;i<words.size();i++)
        {
            int ans = sol(words[i],ump);
            fans=max(ans,fans);
        }
        return fans;
    }
};
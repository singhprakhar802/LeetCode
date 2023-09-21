class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>> ump;
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++)
        {
            vector<int> arr(26,0);
            for(int j=0;j<strs[i].size();j++)
            {
                arr[strs[i][j]-'a']++;
            }
            string temp = "";
            for(int j=0;j<26;j++)
            {
                if(arr[j]>0)
                {
                    temp+= (char)(j+'a');
                    temp+=to_string(arr[j]);
                }
            }
            // cout<<temp<<endl;
            if(ump.find(temp)==ump.end())
                ump[temp] = {strs[i]};
            else
                ump[temp].push_back(strs[i]);
        }

        for(auto it = ump.begin();it!=ump.end();it++)
        {
            ans.push_back((*it).second);
        }

        return ans;
        
    }
};
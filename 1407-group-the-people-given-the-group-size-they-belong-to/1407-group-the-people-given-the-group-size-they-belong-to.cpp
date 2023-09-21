class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) 
    {

        vector<vector<int>> ans;
        unordered_map<int,vector<int>> ump;

        for(int i=0;i<arr.size();i++)
        {
            if(ump.find(arr[i])==ump.end())
            {
                ump[arr[i]].push_back(i);
            }
            else
            {
                if(ump[arr[i]].size()<arr[i])
                {
                    ump[arr[i]].push_back(i);
                }
                else
                {
                    ans.push_back(ump[arr[i]]);
                    ump.erase(arr[i]);
                    ump[arr[i]].push_back(i);
                }
            }
        }     

        for(auto it = ump.begin();it!=ump.end();it++)
        {
            ans.push_back((*it).second);
        }
        return ans;
    }
};
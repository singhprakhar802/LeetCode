class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& arr) 
    {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> ump;

        for(int i=0;i<arr.size();i++)
        {
            if(ump[arr[i]].size()==arr[i]-1)
            {
                ump[arr[i]].push_back(i);
                ans.push_back(ump[arr[i]]);
                ump.erase(arr[i]);
            }
            else
            {
                ump[arr[i]].push_back(i);
            }
        }
        
        return ans;
    }
};
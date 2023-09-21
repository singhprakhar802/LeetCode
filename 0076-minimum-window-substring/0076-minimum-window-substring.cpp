class Solution {
public:
    string minWindow(string s, string t)
    {
        if(s.size() < t.size())
        {
            return "";
        }
        unordered_map<char,int> ump;
        for(int i=0;i<t.size();i++)
        {
            if(ump.find(t[i])==ump.end())
            {
                ump[t[i]]=1;
            }
            else
            {
                ump[t[i]]++;
            }
        }

        int count = t.size();

        unordered_map<char,int> ump2;
        int i;
        int j=0;
        int index1 = 0;
        int index2 = INT_MAX;
        string ans="";
        string temp;
        for(i=0;i<s.size()&&count!=0;i++)
        {
            if(ump.find(s[i])!=ump.end())
            {
                int x = ump[s[i]];
                if( ump2[s[i]] < x)
                    count--;
            }
            ump2[s[i]]++;
        }
        cout<<count<<endl;
        if(count == 0)
            {
                index1 = j;
                index2 = i;
            }
        else
            return "";
        while(j<i && i<s.size())
        {
            if(count == 0)
            {
                if((i-j)<(index2-index1))
                {
                    index1 = j;
                    index2 = i;
                }
                // temp = s.substr(j,(i-j));
                // ans = (ans.size()>temp.size())?temp:ans;
                ump2[s[j]]--;
                if(ump.find(s[j])!=ump.end())
                {
                    if(ump[s[j]] > ump2[s[j]])
                        count++;
                }
                j++;
            }
            else
            {
                ump2[s[i]]++;
                if(ump.find(s[i])!=ump.end())
                {
                    if(ump[s[i]] >= ump2[s[i]])
                        count--;
                }
                i++;
            }
        }
        while( count==0 && j<s.size())
        {
                if((i-j)<(index2-index1))
                {
                    index1 = j;
                    index2 = i;
                }
                // temp = s.substr(j,(i-j));
                //  ans = (ans.size()>temp.size())?temp:ans;
                ump2[s[j]]--;
                if(ump.find(s[j])!=ump.end())
                {
                    if(ump[s[j]] > ump2[s[j]])
                        count++;
                }
                j++;
        }
        temp=s.substr(index1,(index2-index1));
        return temp;
    }
};
class Solution {
public:

    map<pair<int,int>,double> dp;
    double sol(int poured, int query_row, int query_glass)
    {
        if(query_row <0 || query_glass<0)
            return 0.0;
        if(query_row==0 && query_glass==0)
        {
           return poured;
        }
        // cout<<query_row<<"\t"<<query_glass<<endl;
        if(dp.find({query_row,query_glass})!=dp.end())
        {
            return dp[{query_row,query_glass}];
        }
        else{
            double sub = sol(poured,query_row-1,query_glass-1);
            double sub2 = sol(poured,query_row-1,query_glass);
            if(sub>=1.0)
                sub = (sub-1)/2;
            else
                sub=0;
            if(sub2>=1.0)
                sub2= (sub2-1)/2;
            else
                sub2=0;

            // cout<< sub<<"\t"<<sub2<<endl;
            //cout<<dp[{query_row,query_glass}]<<endl;
            return dp[{query_row,query_glass}]=(sub+sub2);
        }
    }
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double ans = sol(poured,query_row,query_glass);
        // cout<<ans<<endl;
        if(ans >=1)
            return 1.0;
        else if(ans>0 && ans<1)
            return ans;
        else
            return (0.0);
    }
};
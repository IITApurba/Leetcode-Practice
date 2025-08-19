class Solution {
public:
     vector<vector<int>>ans;
     vector<int>subset;

    void rec(int start,int level,int k,int left){
        if(level==k){
            if(left==0)
              ans.push_back(subset);
            return;
        }

        for(int ch=start;ch<10;ch++){
            if(ch<=left){
                subset.push_back(ch);
                rec(ch+1,level+1,k,left-ch);
                subset.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear(); subset.clear();
        rec(1,0,k,n);
        return ans;
    }
};
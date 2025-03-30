class Solution {
public:
    vector<string>b;
    vector<vector<string>> ans;
    int n;
    void printB(){
        for(auto&i:b){
            for(auto&j:i)cout<<j<<" ";
            cout<<"\n";
        }

    }
    
  bool isSafe(int r,int c){
    for(int i=0;i<c;++i)
        if(b[r][i]=='Q') return false;
    for(int i=r,j=c;i>=0 && j>=0;--i,--j)
        if(b[i][j]=='Q') return false;
    for(int i=r,j=c;i<n && j>=0;++i,--j)
        if(b[i][j]=='Q') return false;
    return true;
}
    

    void placeQ(int c){
        if(c==n) {
            ans.push_back(b);
            return;
        }
        for(int r=0;r<n;++r){
            if(isSafe(r,c)){
                b[r][c]='Q';
                placeQ(c+1);
                b[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int sz) {
        n=sz;
        b=vector<string>(n);
        string s(n,'.');
        for(int i=0;i<n;++i)b[i]=s;
        placeQ(0);
        return ans;
    }
};
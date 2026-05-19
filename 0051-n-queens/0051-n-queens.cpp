class Solution {
public:
    vector<string>b;
    vector<vector<string>> ans;
    int n;
    // Use hash sets for O(1) isSafe check instead of O(n) iteration
    unordered_set<int> cols;           // columns with queens
    unordered_set<int> diag1;          // main diagonals (r - c)
    unordered_set<int> diag2;          // anti-diagonals (r + c)
    
    void printB(){
        for(auto&i:b){
            for(auto&j:i)cout<<j<<" ";
            cout<<"\n";
        }

    }
    
  // O(1) safety check using hash sets instead of O(n) iteration
  bool isSafe(int r,int c){
    return cols.find(c) == cols.end() &&
           diag1.find(r - c) == diag1.end() &&
           diag2.find(r + c) == diag2.end();
}
    

    void placeQ(int c){
        if(c==n) {
            ans.push_back(b);
            return;
        }
        for(int r=0;r<n;++r){
            if(isSafe(r,c)){
                b[r][c]='Q';
                cols.insert(c);
                diag1.insert(r - c);
                diag2.insert(r + c);
                placeQ(c+1);
                b[r][c]='.';
                cols.erase(c);
                diag1.erase(r - c);
                diag2.erase(r + c);
            }
        }
    }
    vector<vector<string>> solveNQueens(int sz) {
        n=sz;
        b=vector<string>(n);
        cols.clear();
        diag1.clear();
        diag2.clear();
        ans.clear();
        string s(n,'.');
        for(int i=0;i<n;++i)b[i]=s;
        placeQ(0);
        return ans;
    }
};
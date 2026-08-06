class Solution {
public:
    int m,n;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> result(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    result[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if(i-1>=0 && result[i-1][j]==-1){
                q.push({i-1,j});
                result[i-1][j]=result[i][j]+1;
            }
            if(i+1<m && result[i+1][j]==-1){
                q.push({i+1,j});
                result[i+1][j]=result[i][j]+1;
            }
            if(j-1>=0 && result[i][j-1]==-1){
                q.push({i,j-1});
                result[i][j-1]=result[i][j]+1;
            }
            if(j+1<n && result[i][j+1]==-1){
                q.push({i,j+1});
                result[i][j+1]=result[i][j]+1;
            }
        }
        return result;
    }
};
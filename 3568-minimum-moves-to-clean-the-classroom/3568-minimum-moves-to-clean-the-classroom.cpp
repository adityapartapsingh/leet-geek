class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int startX, startY;
        vector<pair<int,int>> litters;
        
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (classroom[i][j]=='S'){ startX=i; startY=j; }
                if (classroom[i][j]=='L'){ litters.push_back({i,j}); }
            }
        }
        int totalL = litters.size();
        int targetMask = (1<<totalL)-1;
        
        int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        
        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1<<totalL, -1)));
        
        queue<tuple<int,int,int,int,int>> q;
        q.push({startX,startY,energy,0,0});
        best[startX][startY][0]=energy;
        
        while(!q.empty()){
            auto [x,y,e,mask,moves]=q.front(); q.pop();
            if(mask==targetMask) return moves;
            
            for(auto& d:dirs){
                int nx=x+d[0], ny=y+d[1];
                if(nx<0||ny<0||nx>=m||ny>=n) continue;
                if(classroom[nx][ny]=='X') continue;
                
                int ne=e-1;
                if(ne<0) continue;
                int nmask=mask;
                if(classroom[nx][ny]=='L'){
                    for(int k=0;k<totalL;k++){
                        if(litters[k].first==nx && litters[k].second==ny){
                            nmask|=(1<<k);
                        }
                    }
                }
                if(classroom[nx][ny]=='R') ne=energy;
                
                if(ne>best[nx][ny][nmask]){
                    best[nx][ny][nmask]=ne;
                    q.push({nx,ny,ne,nmask,moves+1});
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size()*grid.size();
        int k=0;
       vector <int> new_array(n);
        for ( int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                new_array[k]=grid[i][j];
                k++;
            }
        }
        sort(new_array.begin(),new_array.end());
        vector <int> result(2);
      result[1] = (new_array[0] != 1) ? 1 : n;
        for(int l=1;l<n;l++){
            if(new_array[l]==new_array[l-1]){
                result[0]=new_array[l];
            }
           else if(new_array[l] - 1 != new_array[l-1]){
                result[1] = new_array[l] - 1;
            }
        }
        return result;
    }
};
class Solution {
  private: 
    bool isPossible(const vector < int> &arr, int k, int maxPages){
        int studentsRequired =1;
        int currentPagesSum =0;
        
        for (int pages : arr){
            if(pages> maxPages){
                return false;
            }
            if(currentPagesSum + pages>maxPages){
                studentsRequired++;
                currentPagesSum=pages;
                
                if(studentsRequired >k){
                    return false;
                }
            }
            else{
                currentPagesSum +=pages;
            }
        }
        return true;
    };
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n= arr.size();
        if(n<k){return -1;}
            
        int low=*max_element(arr.begin(),arr.end());
        int high= accumulate(arr.begin(),arr.end() ,0);
        int result=-1;
        
        while(low<=high){
            int mid =low +(high -low) /2 ;
            
            if(isPossible(arr , k , mid)){
                result =mid ;
                high =mid-1;
                
            }
            else{low = mid+1;}
        }
        return result;
    }
};
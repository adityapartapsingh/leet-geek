class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long x=0;
        int i=0;
        int d;
        while(n>0){
            d=n%10;
            if(d!=0){
                x=x+(round(pow(10,i))*d);
                i++;
            }
            sum+=d;
            n=n/10;
        }
        return  long (x*sum);
    }
};
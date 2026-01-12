class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long a = n;
        if(a<0) {
        x = 1/x;
        a = -a;
        }
        while(a > 0){
            if(a%2 == 0){
                x = x * x;
                a = a/2;
            }
            else{
                ans = ans * x;
                a = a -1;
            }
        }

     return ans;
        }
};
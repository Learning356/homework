class Solution {
public:
    double myPow(double x, int n) {
        
        //x odd: x^(n/2) * x^(n/2) * x
        //x even: x ^(n/2) * x^(n/2)
        //ending:  n = 1;  x
        //n < 0;
        return n>=0 ? Pow(x,(long)n): 1/(Pow(x,-(long)n));
        
        //double ans;
    }
    
    double Pow(double x,long int n){
        if(n == 0)  return 1;
        double a = Pow(x, n/2);
        
        if(n%2 == 0){
            
            
             return a * a;
        }
        else{
            return a * a * x;
        }
            
        
        
    }
};
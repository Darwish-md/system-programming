#include <stdio.h>
#include <math.h>

int solution(int n){
    
    if(n < 10) return 0;
    
    else{
        int digitsNum = (int) log10(n);
        return pow(10, digitsNum);
    }
    
}

int main()
{
    int x = solution(445214);
    printf("%d", x);
    return 0;
}

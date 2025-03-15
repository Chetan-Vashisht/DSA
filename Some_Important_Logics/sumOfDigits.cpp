#include <iostream>
using namespace std;
void digitSum(int num){
    int digit_sum=0;
    while (num >0)
    {
        int digit = num % 10 ;
        num/=10;
        digit_sum+=digit;
    }
    cout<< digit_sum;
    
}
int main() {
    digitSum(2356);
    return 0;
}
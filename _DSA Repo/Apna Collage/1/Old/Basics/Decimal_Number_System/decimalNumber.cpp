#include <iostream>
using namespace std;
int decimalToBinary(int decimalNumber)
{
    int ans = 0, power = 1;
    while (decimalNumber > 0)
    {
        // deviding go get reminder
        int reminder = decimalNumber % 2;
        // deviding number to reduce number
        decimalNumber /= 2;
        // as we need answer in backword way so using this
        ans += (reminder * power);
        power *= 10;
    }
    return ans;
}
int binaryToDecimal(int binaryNumber)
{
    int ans = 0, power = 1;
    while (binaryNumber > 0)
    {

        int reminder = binaryNumber % 10;
        ans += reminder * power;

        binaryNumber /= 10;
        power *= 2;
    }
    return ans;
}
int main()
{
    int binaryNumber = 110000;
    cout<<binaryToDecimal(binaryNumber);

    // cout << decimalToBinary(decimalNUmber);

    return 0;
}
#include <stdio.h>
int reverse(int x){
    long reversed = 0; // Use long to handle overflow
    
    while(x != 0){
        int digit = x % 10;         // Get the last digit
        reversed = reversed * 10 + digit; // Append it to reversed number
        x /= 10;                     // Remove last digit
    }
    
    // Check for 32-bit integer overflow
    if(reversed > 2147483647 || reversed < -2147483648)
        return 0;
    
    return (int)reversed;
}

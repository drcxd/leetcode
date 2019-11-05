#include <stdlib.h>

bool isPalindrome(int x){
    char buffer[1024];
    
    if (x < 0) {
        return false;
    }
    
    int i = 0;
    while (x > 0) {
        buffer[i] = x % 10 + '0';
        ++i;
        x /= 10;
    }
    buffer[i] = 0;
    
    int j = strlen(buffer) - 1;
    i = 0;
    
    while (i < j) {
        if (buffer[i] != buffer[j]) {
            return false;
        }
        ++i;
        --j;
    }
    
    return true;
}



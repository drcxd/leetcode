#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1)
    {
        return s;
    }
    int len = strlen(s);
    char *res = malloc(len + 1);
    int i = 0;
    for (int r = 0; r < numRows; ++r)
    {
        int k = 0;
        int index = r + k * (2 * numRows - 2);
        int after_index = r + (k + 1) * (2 * numRows - 2) - 2 * r;
        while (index < len || after_index < len)
        {
            res[i++] = s[index];
            if (after_index - index != 2 * numRows - 2 &&
                after_index != index &&
                after_index < len)
            {
                res[i++] = s[after_index];
            }            
            ++k;
            index = r + k * (2 * numRows - 2);
            after_index = r + (k + 1) * (2 * numRows - 2) - 2 * r;
        }
    }
    res[len] = '\0';
    return res;
}

/* int main(void) */
/* { */
/*     char *str = "PAYPALISHIRING"; */
/*     printf("%s\n", convert(str, 4)); */
/*     return 0; */
/* } */


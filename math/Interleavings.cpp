// Given two strings str1 and str2, 
// write a function that prints all interleavings of the given two strings. 
// You may assume that all characters in both strings are different
//
// An interleaved string of given two strings preserves the order 
// of characters in individual strings.
//

#include <stdio.h>
#include <string.h>
int total = 0;
void PrintInterlevaing(const char* str1, const char* str2, 
        char* result, int res_len, int pos) {
    if (pos == res_len) {
        total++;
        printf("%s\n", result);
        return;
    }

    if (*str1 != '\0') {
        result[pos] = *str1;
        PrintInterlevaing(str1+1, str2, result, res_len, pos+1);
    }

    if (*str2 != '\0') {
        result[pos] = *str2;
        PrintInterlevaing(str1, str2+1, result, res_len, pos+1);
    }

}

int main() {
    const char* s1 = "abcd";
    const char* s2 = "fgh";
    char result[8];
    memset(result, 0, 8);
    PrintInterlevaing(s1, s2, result, 7, 0);
    printf("total = %d\n", total);
    return 0;
}


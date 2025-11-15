/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *mapping[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char **result, int *returnSize, char *current, const char *digits, int index) {
    if (digits[index] == '\0') {
        result[*returnSize] = strdup(current);  // store a copy
        (*returnSize)++;
        return;
    }

    const char *letters = mapping[digits[index] - '0'];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(result, returnSize, current, digits, index + 1);
    }
}

char **letterCombinations(char *digits, int *returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) return NULL;

    int maxCombinations = 256;  // safe for digits.length <= 4
    char **result = malloc(sizeof(char*) * maxCombinations);
    char current[5];  // max length = 4 + 1
    current[len] = '\0';

    backtrack(result, returnSize, current, digits, 0);
    return result;
}

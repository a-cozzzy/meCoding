#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */

char* isValid(char* s) {
    // Calculate the occurrence of each character
    int chars_occurs[26] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        chars_occurs[s[i] - 'a']++;
    }

    // Count the number of different characters
    int distinct_chars = 0;
    for (int i = 0; i < 26; i++) {
        if (chars_occurs[i] != 0) {
            distinct_chars++;
        }
    }

    // Calculate the minimum and maximum frequencies
    int min_freq = n;
    int max_freq = 0;
    for (int i = 0; i < 26; i++) {
        if (chars_occurs[i] != 0) {
            min_freq = (chars_occurs[i] < min_freq) ? chars_occurs[i] : min_freq;
            max_freq = (chars_occurs[i] > max_freq) ? chars_occurs[i] : max_freq;
        }
    }

    // Check conditions for validity
    if (n - min_freq * distinct_chars <= 1 || max_freq * distinct_chars - n == max_freq - 1) {
        return "YES";
    }
    
    return "NO";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** possibleChanges(int usernames_count, char** usernames, int* result_count) {
    char** results = malloc(usernames_count * sizeof(char*));
    
    for (int i = 0; i < usernames_count; i++) {
        char* username = usernames[i];
        int length = strlen(username);
        int alphabetical = 1; // Assume alphabetical order initially
        
        for (int j = 0; j < length - 1; j++) {
            if (username[j] > username[j + 1]) {
                alphabetical = 0; // Found a character out of order
                break;
            }
        }
        
        if (alphabetical) {
            results[i] = "NO";
        } else {
            results[i] = "YES";
        }
    }
    
    *result_count = usernames_count;
    return results;
}

int main() {
    char* usernames[] = {"abc", "cba", "abcd", "bcda"};
    int usernames_count = sizeof(usernames) / sizeof(usernames[0]);
    int result_count;
    char** results = possibleChanges(usernames_count, usernames, &result_count);
    
    for (int i = 0; i < result_count; i++) {
        printf("%s\n", results[i]);
    }
    
    free(results); // Free allocated memory
    return 0;
}

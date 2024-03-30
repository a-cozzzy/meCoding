#include <stdio.h>
#include <stdlib.h>

int last_of_us(int n) {
    int *people = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        people[i] = i + 1;
    }
    int day = 1;
    while (n > 1) {
        if (day % 2 != 0) {  
            for (int i = 0; i < n; i += 2) {
                people[i] = 0;
            }
        } else {  
            for (int i = n - 1; i >= 0; i -= 2) {
                people[i] = 0;
            }
        }
        int *new_people = malloc(n/2 * sizeof(int));
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (people[i] != 0) {
                new_people[j++] = people[i];
            }
        }
        free(people);
        people = new_people;
        n /= 2;
        day++;
    }
    int survivor = people[0];
    free(people);
    return survivor;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", last_of_us(n));
    return 0;
}


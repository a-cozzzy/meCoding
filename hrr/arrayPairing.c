#include <stdio.h>
void array_pair(int n, int arr[], int matrix_arr[][2]) {
    int pair_count = 0;

    // Generate adjacent pairs
    for (int i = 0; i < n - 1; i++) {
        matrix_arr[pair_count][0] = arr[i];
        matrix_arr[pair_count][1] = arr[i + 1];
        pair_count++;
    }

    // Generate all possible pairs
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 2; j < n; j++) {
            matrix_arr[pair_count][0] = arr[i];
            matrix_arr[pair_count][1] = arr[j];
            pair_count++;
        }
    }
}

void print_2d_array(int rows, int cols, int arr[][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("%d %d", arr[i][0], arr[i][1]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    int matrix_arr[n*(n-1)/2][2];
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    array_pair(n, arr, matrix_arr);
    print_2d_array(n*(n-1)/2, 2, matrix_arr);

    return 0;
}

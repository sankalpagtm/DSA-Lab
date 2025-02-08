#include <stdio.h>

int BinarySearch(int A[], int l, int r, int key) {
    int m;
    
    do {
        m = (l + r) / 2;
        
        if (key == A[m]) {
            printf("Search successful\n");
            return m;
        }
        else if (key < A[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    } while (l <= r);

    return -1;
}

int main() {
    int A[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(A) / sizeof(A[0]);
    int key = 30;

    int result = BinarySearch(A, 0, n - 1, key);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

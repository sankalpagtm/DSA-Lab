#include <stdio.h>
void LinearSearch(int A[], int n, int key) {
    int Flag = 0;  
    
    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            printf("Search successful\n");
            Flag = 1;  
            break;    
        }
    }
    
    if (Flag == 0) {
        printf("Search unsuccessful\n");
    }
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(A[0]);
    int key = 30;

    LinearSearch(A, n, key);

    return 0;
}

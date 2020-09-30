#include <stdlib.h>
#include <stdio.h>

int main() {

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;

    // Get the number of elements for the array
    printf( "Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));

    // Check if the memory has been successfully allocated by calloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");

        // Get the elements of the array
        for (i = 0; i < n+1; ++i) {
            ptr[i] = i;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n-1; ++i) {
            printf("%d, ", ptr[i]);
        }
        printf("%d\n", ptr[n-1]);

        // Free the memory
        free(ptr);
        printf("Malloc Memory successfully freed.\n");
    }

    return 0;
}


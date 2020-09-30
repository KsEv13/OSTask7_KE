#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

void *my_realloc(void *ptr, size_t oldsize, size_t newsize) {
   if (newsize == 0) {
      free(ptr);
      return NULL;
   }
   else if (ptr==NULL) {
      return malloc(newsize);
   }
   else if (newsize <= oldsize) {
      return ptr;
   }
   else {
      assert((ptr!=NULL)&&(newsize > oldsize));
      void *newptr = malloc(newsize);
      if (newptr) {
          memcpy(newptr, ptr, oldsize);
          free(ptr);
      }
      return newptr;
    }
}

int main() {
    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n1, n2, i;

    // Get the number of elements for the array
    printf( "Enter number of elements: ");
    scanf("%d", &n1);

    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n1, sizeof(int));

    // Print the elements of the array
    printf("The elements of the array are: ");
    for (i = 0; i < n1-1; ++i) {
        printf("%d, ", ptr[i]);
    }
    printf("%d\n", ptr[n1-1]);

    // Get the number of elements for the reallocated array
    printf( "Enter new number of elements: ");
    scanf("%d", &n2);

    my_realloc(ptr, n1, n2);
    // Print the elements of the reallocated array
    printf("The elements of the reallocated array are: ");
    for (i = 0; i < n2-1; ++i) {
        printf("%d, ", ptr[i]);
    }
    printf("%d\n", ptr[n2-1]);
    
    return 0;
}


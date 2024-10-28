#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t total_allocated = 0;
    size_t allocation_size = 1024 * 1024; /* 1 MB */
    char **ptrs = NULL;
    size_t count = 0;
    size_t i;

    while (1) {
        char *ptr = (char *)malloc(allocation_size);
        if (ptr == NULL) {
            printf("メモリ確保に失敗しました。総確保メモリ量: %zu MB\n", total_allocated / (1024 * 1024));
            break;
        }
        printf("%zu MB\n", total_allocated / (1024*1024));

        ptrs = realloc(ptrs, (count + 1) * sizeof(char *));
        ptrs[count] = ptr;
        count++;
        total_allocated += allocation_size;

        for (i = 0; i < allocation_size; i++) {
            ptr[i] = 0;
        }
    }

    for (i = 0; i < count; i++) {
        free(ptrs[i]);
    }
    free(ptrs);

    return 0;
}

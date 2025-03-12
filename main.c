#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

#define TYPE long long int

int comparison_counter = 0;
int swap_counter = 0;

void swap(TYPE *a, TYPE *b) {
    swap_counter++;
    TYPE tmp = *a;
    *a = *b;
    *b = tmp;
}

void choice_sort(int n, TYPE *array) {
    for (int place = 0; place < n - 1; place++) {
        TYPE *next_min = &array[place];
        for (int i = place + 1; i < n; i++) {
            comparison_counter++;
            if (*next_min > array[i]) {
                next_min = &array[i];
            }
        }
        swap(&array[place], next_min);
    }
}

void quick_sort(int n, TYPE *array) {
    if(n <= 1) {
        return;
    }
    // partition on middle element
    int i = 0, j = n - 1;
    TYPE x = array[(n -1)/ 2];
    while(1) {
        comparison_counter++;
        for(; i < n && array[i] < x; i++) comparison_counter++;
        comparison_counter++;
        for(; j >= 0 && x < array[j]; j--) comparison_counter++;
        if(j < i) {
            break;
        }
        swap(&array[i], &array[j]);
        i++;
        j--;
    }
    // sort halves recursively
    if(0 < j) {
        quick_sort(j + 1, array);
    }
    if(i < n - 1) {
        quick_sort(n - i, array + i);
    }
}

TYPE *generate_array(int type, int n) {
    TYPE *array = malloc(sizeof(TYPE) * n);
    // sorted
    if(type == 1) {
        for(int i = 0; i < n; i++) {
            array[i] = i;
        }
        return array;
    }
    // reverse sorted
    if(type == 2) {
        for(int i = 0; i < n; i++) {
            array[i] = n - i;
        }
        return array;
    }
    //random
    for(int i = 0; i < n; i++) {
        array[i] = rand();
    }
    return array;
}

void assert_sorted(int n, TYPE *array) {
    for(int i = 1; i < n; i++) {
        assert(array[i - 1] <= array[i]);
    }
}

int SIZES[4] = {10, 100, 1000, 10000};

int main(void) {
    srand(time(0));
    for(size_t s = 0; s < sizeof(SIZES) / sizeof(SIZES[0]); s++) {
        int n = SIZES[s];
        printf("Amount of elements: %d\n", n);
        for(int type = 1; type <= 4; type++) {
            printf(" Type: %d\n", type);

            comparison_counter = 0;
            swap_counter = 0;
            TYPE *array = generate_array(type, n);
            choice_sort(n, array);
            assert_sorted(n, array);
            free(array);
            printf("  Choice sort:\n   Comparisons: %d\n   Swaps: %d\n", comparison_counter, swap_counter);

            comparison_counter = 0;
            swap_counter = 0;
            array = generate_array(type, n);
            quick_sort(n, array);
            assert_sorted(n, array);
            free(array);
            printf("  Quick sort:\n   Comparisons: %d\n   Swaps: %d\n", comparison_counter, swap_counter);
        }
    }
    return 0;
}

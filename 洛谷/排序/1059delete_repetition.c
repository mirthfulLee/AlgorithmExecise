
//
// Created by 木子又欠 on 2020/7/9.
//

#include <stdio.h>
#include <stdlib.h>


/*Swap function to swap two values*/
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}


int main()
{
    int n, min, repetition_time=0;
    scanf("%d", &n);
    int a[n];
    int t[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        min=i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min] ) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
        if (i > 0 && a[i] == a[i - 1]) {
            repetition_time++;
        }
    }

    printf("%d\n", n - repetition_time);
    for (int i = 0; i < n; i++) {
        if (!(i > 0 && a[i] == a[i - 1])) {
            printf("%d ", a[i]);
        }
    }

}

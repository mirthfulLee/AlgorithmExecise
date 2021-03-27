//
// Created by 木子又欠 on 2020/7/10.
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
    int n, min, waiting_time=0;
    scanf("%d", &n);
    int a[n];
    int t[n];
    double sum=0;
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        min=i;
        for (int j = i; j < n; j++) {
            if (t[j] < t[min] || (t[j] == t[min] && a[j] < a[min])) {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
        swap(&t[i], &t[min]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
        sum+=waiting_time;
        waiting_time += t[i];
    }
    printf("\n%0.2f", sum / n);
}
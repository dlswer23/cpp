#include <string.h>

//기수정렬이란 작은 자리수부터 비교하여 정렬해 간다는 것이 기본 개념으로 하는 정렬 !

void radix_sort(int a[], int size, int base) {
    int ex, i, j, max = a[0];
    for (i = 1; i < size; i++) if (a[i] > max) max = a[i];
    for (ex = 1; ex <= max; ex *= base) {
        int output[size], count[base];
        memset(count, 0, sizeof(count));
        for (i = 0; i < size; i++) count[(a[i] / ex) % base]++;
        for (i = 1; i < base; i++) count[i] += count[i - 1];
        for (i = size - 1; i > -1; i--) {
            j = (a[i] / ex) % base;
            output[count[j] - 1] = a[i];
            count[j]--;
        }
        for (i = 0; i < size; i++) a[i] = output[i];
    }
}
int main() {
    int arr[] = { 9,1,22,4,0,1,22,100,10 };
    int size = sizeof(arr) / sizeof(int);
    radix_sort(arr, size, 10);
    for (int i = 0; i < size; i++) printf("%d ", arr[i]); 
}
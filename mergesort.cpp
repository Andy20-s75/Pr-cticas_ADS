//mergesort intento
#include <stdio.h>
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            array[k++] = L[i++];
        else
            array[k++] = R[j++];
    }

    while (i < n1)
        array[k++] = L[i++];
    while (j < n2)
        array[k++] = R[j++];
}

void MergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main() {
    int n;
    printf("Cuantos numeros pondras? ");
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nTus valores originales son:");
    for (int i = 0; i < n; i++) {
        printf(" %d", array[i]);
    }

    MergeSort(array, 0, n - 1);

    printf("\nTus valores ordenados son:");
    for (int i = 0; i < n; i++) {
        printf(" %d", array[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubble_sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        float temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Fungsi untuk mencetak isi array
void print_array(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Penggunaan: %s <ukuran_n>\n", argv[0]);
        printf("Contoh: %s 10\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    float *original = (float *)malloc(n * sizeof(float));
    float *temp = (float *)malloc(n * sizeof(float));
    clock_t start, end;
    
    // Variabel untuk menyimpan waktu eksekusi
    double time_bubble, time_selection, time_insertion;

    // Menghasilkan angka acak
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        original[i] = ((float)rand() / (float)(RAND_MAX)) * 100.0;
    }

    printf("=== ARRAY ORIGINAL (%d elemen) ===\n", n);
    print_array(original, n);
    printf("\n");

    // 1. Eksekusi Bubble Sort
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    bubble_sort(temp, n);
    end = clock();
    time_bubble = ((double)(end - start)) / CLOCKS_PER_SEC; // Simpan waktu
    printf("--- HASIL BUBBLE SORT ---\n");
    print_array(temp, n);
    printf("\n");

    // 2. Eksekusi Selection Sort
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    selection_sort(temp, n);
    end = clock();
    time_selection = ((double)(end - start)) / CLOCKS_PER_SEC; // Simpan waktu
    printf("--- HASIL SELECTION SORT ---\n");
    print_array(temp, n);
    printf("\n");

    // 3. Eksekusi Insertion Sort
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    insertion_sort(temp, n);
    end = clock();
    time_insertion = ((double)(end - start)) / CLOCKS_PER_SEC; // Simpan waktu
    printf("--- HASIL INSERTION SORT ---\n");
    print_array(temp, n);
    printf("\n");

    // --- CETAK RINGKASAN WAKTU DI AKHIR ---
    printf("=== RINGKASAN WAKTU EKSEKUSI ===\n");
    printf("Ukuran Array (n) : %d\n", n);
    printf("Bubble Sort      : %f detik\n", time_bubble);
    printf("Selection Sort   : %f detik\n", time_selection);
    printf("Insertion Sort   : %f detik\n", time_insertion);
    printf("================================\n");

    // Membersihkan memori
    free(original);
    free(temp);
    return 0;
}
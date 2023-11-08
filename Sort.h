#pragma once
#include <stdio.h>
#include <stdlib.h>

namespace Sort {
    // 排序算法
    // 直接插入排序
    void insertionSort(int arr[], int n) {
        int i, key, j;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            // 将 arr[0..i-1] 中大于 key 的元素都向后移动
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            // 将 key 插入到正确的位置
            arr[j + 1] = key;
        }
    }

    int test05() {
        int arr[] = { 12, 11, 13, 5, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("原始数组：\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        insertionSort(arr, n);

        printf("\n排序后的数组：\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        return 0;
    }

    // 希尔排序
    void shellSort(int arr[], int n) {
        int gap, i, j, temp;

        // 选择间隔序列，通常使用希尔增量
        for (gap = n / 2; gap > 0; gap /= 2) {
            for (i = gap; i < n; i++) {
                temp = arr[i];

                // 对间隔为 gap 的子数组进行插入排序
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }

                arr[j] = temp;
            }
        }
    }

    int test06() {
        int arr[] = { 12, 11, 13, 5, 6, 7 };
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("原始数组：\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        shellSort(arr, n);

        printf("\n排序后的数组：\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        return 0;
    }
} //namespace end

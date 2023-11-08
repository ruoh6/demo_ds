#pragma once
#include <stdio.h>
#include <stdlib.h>
namespace Array {
    void moveNegativeToFront01(int arr[], int n) {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            // 移动left指针直到找到正数元素或者与right指针相遇
            while (arr[left] < 0 && left < right) {
                left++;
            }

            // 移动right指针直到找到负数元素或者与left指针相遇
            while (arr[right] >= 0 && left < right) {
                right--;
            }

            // 交换left和right指针指向的元素
            if (left < right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }
    }

    void test01() {
        int arr[] = { 3, -2, 5, -2, -3, 7, -4, 9, -6, 10, 20 };
        int n = sizeof(arr) / sizeof(arr[0]);

        moveNegativeToFront01(arr, n);

        printf("Resulting array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    }

    /// <summary>
    /// Counting Sort
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="n"></param>
    void moveNegativeToFront02(int arr[], int n) {
        // 找到数组中的最大值和最小值
        int max = arr[0];
        int min = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        // 计算计数数组的大小
        int range = max - min + 1;
        int* count = (int*)malloc(range * sizeof(int));

        // 创建计数数组，并初始化为0
        for (int i = 0; i < range; i++) {
            count[i] = 0;
        }

        // 统计每个元素的出现次数
        for (int i = 0; i < n; i++) {
            count[arr[i] - min]++;
        }

        // 将负数元素移动到数组前部分
        int j = 0;
        for (int i = 0; i < range; i++) {
            while (count[i] > 0) {
                arr[j] = i + min;
                j++;
                count[i]--;
            }
        }
        free(count);
    }

    int test02() {
        int arr[] = { 3, -2, 5, -1, 7, -4, 9, -6 };
        int n = sizeof(arr) / sizeof(arr[0]);

        moveNegativeToFront02(arr, n);

        printf("Resulting array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        return 0;
    }
} // namespace end

#pragma once
#include <stdio.h>
#include <stdlib.h>
namespace Array {
    void moveNegativeToFront01(int arr[], int n) {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            // �ƶ�leftָ��ֱ���ҵ�����Ԫ�ػ�����rightָ������
            while (arr[left] < 0 && left < right) {
                left++;
            }

            // �ƶ�rightָ��ֱ���ҵ�����Ԫ�ػ�����leftָ������
            while (arr[right] >= 0 && left < right) {
                right--;
            }

            // ����left��rightָ��ָ���Ԫ��
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
        // �ҵ������е����ֵ����Сֵ
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

        // �����������Ĵ�С
        int range = max - min + 1;
        int* count = (int*)malloc(range * sizeof(int));

        // �����������飬����ʼ��Ϊ0
        for (int i = 0; i < range; i++) {
            count[i] = 0;
        }

        // ͳ��ÿ��Ԫ�صĳ��ִ���
        for (int i = 0; i < n; i++) {
            count[arr[i] - min]++;
        }

        // ������Ԫ���ƶ�������ǰ����
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

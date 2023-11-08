#pragma once
#include <stdio.h>
#include <stdlib.h>

namespace Sort {
    // �����㷨
    // ֱ�Ӳ�������
    void insertionSort(int arr[], int n) {
        int i, key, j;
        for (i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;

            // �� arr[0..i-1] �д��� key ��Ԫ�ض�����ƶ�
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            // �� key ���뵽��ȷ��λ��
            arr[j + 1] = key;
        }
    }

    int test05() {
        int arr[] = { 12, 11, 13, 5, 6 };
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("ԭʼ���飺\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        insertionSort(arr, n);

        printf("\n���������飺\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        return 0;
    }

    // ϣ������
    void shellSort(int arr[], int n) {
        int gap, i, j, temp;

        // ѡ�������У�ͨ��ʹ��ϣ������
        for (gap = n / 2; gap > 0; gap /= 2) {
            for (i = gap; i < n; i++) {
                temp = arr[i];

                // �Լ��Ϊ gap ����������в�������
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

        printf("ԭʼ���飺\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        shellSort(arr, n);

        printf("\n���������飺\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }

        return 0;
    }
} //namespace end

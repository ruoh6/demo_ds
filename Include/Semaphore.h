#pragma once
#include <windows.h>
#include <stdio.h>

namespace PV {
    // ȫ���ź���
    HANDLE semaphore;

    DWORD WINAPI ProducerThread(LPVOID param) {
        // ģ����������
        Sleep(1000);

        // ִ�� V �����������ź����ļ���ֵ
        ReleaseSemaphore(semaphore, 1, NULL);

        printf("Produced an item.\n");
        return 0;
    }

    DWORD WINAPI ConsumerThread(LPVOID param) {
        // ִ�� P �������ȴ��ź����ļ���ֵ������
        WaitForSingleObject(semaphore, INFINITE);

        // ģ�����Ѳ���
        Sleep(1000);

        printf("Consumed an item.\n");
        return 0;
    }

    int test() {
        // �����ź�������ʼ����ֵΪ 0
        semaphore = CreateSemaphore(NULL, 0, 1, NULL);

        // �����������̺߳��������߳�
        HANDLE producerThread = CreateThread(NULL, 0, ProducerThread, NULL, 0, NULL);
        HANDLE consumerThread = CreateThread(NULL, 0, ConsumerThread, NULL, 0, NULL);

        // �ȴ��߳����
        WaitForSingleObject(producerThread, INFINITE);
        WaitForSingleObject(consumerThread, INFINITE);

        // �ر��ź������
        CloseHandle(semaphore);

        return 0;
    }

}
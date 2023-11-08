#pragma once
#include <windows.h>
#include <stdio.h>

namespace PV {
    // 全局信号量
    HANDLE semaphore;

    DWORD WINAPI ProducerThread(LPVOID param) {
        // 模拟生产操作
        Sleep(1000);

        // 执行 V 操作，增加信号量的计数值
        ReleaseSemaphore(semaphore, 1, NULL);

        printf("Produced an item.\n");
        return 0;
    }

    DWORD WINAPI ConsumerThread(LPVOID param) {
        // 执行 P 操作，等待信号量的计数值大于零
        WaitForSingleObject(semaphore, INFINITE);

        // 模拟消费操作
        Sleep(1000);

        printf("Consumed an item.\n");
        return 0;
    }

    int test() {
        // 创建信号量，初始计数值为 0
        semaphore = CreateSemaphore(NULL, 0, 1, NULL);

        // 创建生产者线程和消费者线程
        HANDLE producerThread = CreateThread(NULL, 0, ProducerThread, NULL, 0, NULL);
        HANDLE consumerThread = CreateThread(NULL, 0, ConsumerThread, NULL, 0, NULL);

        // 等待线程完成
        WaitForSingleObject(producerThread, INFINITE);
        WaitForSingleObject(consumerThread, INFINITE);

        // 关闭信号量句柄
        CloseHandle(semaphore);

        return 0;
    }

}
#pragma once
#include <stdio.h>
#include <stdlib.h>
namespace Tree {
    namespace BiTree {

        // �������ڵ�ṹ
        struct TreeNode {
            int data;
            struct TreeNode* left;
            struct TreeNode* right;
        };

        // ��α�����������ܶ�
        // ��α����㷨��
        // ���ö��У������ڵ���������
        // �Ӷ�ͷȡһ����㣬�Ըýڵ����²�����
        // 1���������ݡ�
        // 2�����ý�������Ԫ�ز�Ϊ�գ������Һ�����ӡ�ѭ��������Ϊ��
        // 
        int maxDensity(struct TreeNode* root) {
            if (root == NULL) {
                return 0;
            }

            int max_density = 0;
            struct TreeNode* queue[100]; // ���ڲ�α����Ķ���
            int front = 0, rear = 0;     // ���е�ǰ��ָ��

            queue[rear++] = root; // ���ڵ����
            while (front < rear) {
                int level_size = rear - front; // ��ǰ��Ľ������
                int current_max = 0; // ��ǰ������ֵ

                // ������ǰ��Ľ�㣬�ҵ����ֵ
                for (int i = 0; i < level_size; i++) {
                    struct TreeNode* node = queue[front++];
                    // һ������ֵ
                    if (node->data > current_max) {
                        current_max = node->data;
                    }

                    // ����ǰ��Ľ����ӽڵ����
                    if (node->left) {
                        queue[rear++] = node->left;
                    }
                    if (node->right) {
                        queue[rear++] = node->right;
                    }
                }

                if (current_max > max_density) {
                    max_density = current_max;
                }
            }

            return max_density;
        }

        int test04() {
            // ����һ��ʾ��������
            // 1.
            struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->data = 1;

            // 2.
            root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->left->data = 4;
            //root->left->left = root->left->right = NULL;

            root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->right->data = 11;
            root->right->right = NULL;

            // 3.
            root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->left->left->data = 4;
            root->left->left->left = root->left->left->right = NULL;

            root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->left->right->data = 5;
            root->left->right->left = root->left->right->right = NULL;

            root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            root->right->left->data = 6;
            root->right->left->left = root->right->left->right = NULL;

            int density = maxDensity(root);
            printf("����ܶ�: %d\n", density);

            return 0;
        }

    } // namespace end

    namespace CSTree {

        // ���庢���ֵ�����Ľ��ṹ
        typedef struct TreeNode {
            int data;
            struct TreeNode* first_child;  // ����
            struct TreeNode* next_sibling; // �ֵܽڵ�
        } TreeNode;

        // �����½��ĺ���
        TreeNode* createNode(int data) {
            TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
            newNode->data = data;
            newNode->first_child = NULL;
            newNode->next_sibling = NULL;
            return newNode;
        }

        // �������Ķȵĺ���
        int calculateDegree(TreeNode* root) {
            if (root == NULL) {
                return 0;
            }

            int degree = 0;

            // �������ӽڵ��������㺢�ӵ�����
            TreeNode* child = root->first_child;
            while (child != NULL) {
                degree++;
                child = child->next_sibling;
            }

            // �ݹ���㺢�ӽڵ�Ķȣ���������ۼӵ���ǰ�ڵ�Ķ�
            TreeNode* sibling = root->first_child;
            while (sibling != NULL) {
                int childDegree = calculateDegree(sibling);
                if (childDegree > degree) {
                    degree = childDegree;
                }
                sibling = sibling->next_sibling;
            }

            return degree;
        }

        int test() {
            // ����һ������ʹ�ú����ֵ�����洢�ṹ
            TreeNode* root = createNode(1);
            root->first_child = createNode(2);
            root->first_child->next_sibling = createNode(3);
            root->first_child->first_child = createNode(4);
            root->first_child->first_child->next_sibling = createNode(5);
            root->first_child->first_child->first_child = createNode(6);

            // ���ú����������Ķ�
            int treeDegree = calculateDegree(root);

            printf("���Ķ�: %d\n", treeDegree);

            // �ͷ��ڴ�
            // ��ʵ��Ӧ���У���Ҫ�����ͷŷ�����ڴ棬�Ա����ڴ�й©
            return 0;
        }

    } // namespace end
}

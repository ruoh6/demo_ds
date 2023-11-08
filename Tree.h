#pragma once
#include <stdio.h>
#include <stdlib.h>
namespace Tree {
    namespace BiTree {

        // 二叉树节点结构
        struct TreeNode {
            int data;
            struct TreeNode* left;
            struct TreeNode* right;
        };

        // 层次遍历计算最大密度
        // 层次遍历算法：
        // 设置队列，将根节点放入队列中
        // 从队头取一个结点，对该节点以下操作：
        // 1、访问数据。
        // 2、若该结点的左右元素不为空，则将左右孩子入队。循环至队列为空
        // 
        int maxDensity(struct TreeNode* root) {
            if (root == NULL) {
                return 0;
            }

            int max_density = 0;
            struct TreeNode* queue[100]; // 用于层次遍历的队列
            int front = 0, rear = 0;     // 队列的前后指针

            queue[rear++] = root; // 根节点入队
            while (front < rear) {
                int level_size = rear - front; // 当前层的结点数量
                int current_max = 0; // 当前层的最大值

                // 遍历当前层的结点，找到最大值
                for (int i = 0; i < level_size; i++) {
                    struct TreeNode* node = queue[front++];
                    // 一层的最大值
                    if (node->data > current_max) {
                        current_max = node->data;
                    }

                    // 将当前层的结点的子节点入队
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
            // 创建一个示例二叉树
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
            printf("最大密度: %d\n", density);

            return 0;
        }

    } // namespace end

    namespace CSTree {

        // 定义孩子兄弟链表的结点结构
        typedef struct TreeNode {
            int data;
            struct TreeNode* first_child;  // 左孩子
            struct TreeNode* next_sibling; // 兄弟节点
        } TreeNode;

        // 创建新结点的函数
        TreeNode* createNode(int data) {
            TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
            newNode->data = data;
            newNode->first_child = NULL;
            newNode->next_sibling = NULL;
            return newNode;
        }

        // 计算树的度的函数
        int calculateDegree(TreeNode* root) {
            if (root == NULL) {
                return 0;
            }

            int degree = 0;

            // 遍历孩子节点链表，计算孩子的数量
            TreeNode* child = root->first_child;
            while (child != NULL) {
                degree++;
                child = child->next_sibling;
            }

            // 递归计算孩子节点的度，并将结果累加到当前节点的度
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
            // 创建一棵树，使用孩子兄弟链表存储结构
            TreeNode* root = createNode(1);
            root->first_child = createNode(2);
            root->first_child->next_sibling = createNode(3);
            root->first_child->first_child = createNode(4);
            root->first_child->first_child->next_sibling = createNode(5);
            root->first_child->first_child->first_child = createNode(6);

            // 调用函数计算树的度
            int treeDegree = calculateDegree(root);

            printf("树的度: %d\n", treeDegree);

            // 释放内存
            // 在实际应用中，不要忘记释放分配的内存，以避免内存泄漏
            return 0;
        }

    } // namespace end
}

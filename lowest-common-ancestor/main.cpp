/*
* Copyright (c) 2022 - @hallo_w3lt
* IDE Qt Creator
* Challenge code taken on https://bit.ly/3C9XP6H
*/

#include <QCoreApplication>
#include <iostream>

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

/**
*       3
*     /   \
*    5     1
*   / \    | \
*  6   2   0  8
*     / \
*    7   4
**/

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5

struct TreeNode
{
    int payload;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n) : payload{n}, left{nullptr}, right{nullptr} {}
};

TreeNode const* make()
{
    // [3,5,1,6,2,0,8,null,null,7,4]
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->left->left = new TreeNode('\0');
    root->right->right->left = new TreeNode('\0');
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    return root;
}

TreeNode const* solution(TreeNode const* root, int const p, int const q)
{
    auto lca
    {
        [&]()->TreeNode const*
        {
            if (nullptr == root) { return nullptr; }
            if (p == root->payload || q == root->payload) { return root; }

            auto const* left {solution(root->left, p, q)};
            auto const* right {solution(root->right, p, q)};

            if (nullptr == left) { return right; }
            if (nullptr == right) { return left; }

            return root;
        }
    };

    return p != q ? lca() : nullptr;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto const* tree {make()};
    auto const* result {solution(tree, 5, 8)};

    if (result != nullptr) {
        std::cout << "solution: " << result->payload << std::endl;
    } else {
        std::cout << "tree node is empty or node not found" << std::endl;
    }

    delete tree;
    return a.exec();
}

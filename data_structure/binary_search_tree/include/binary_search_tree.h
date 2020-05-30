/**
 * Copyright 2020 @author Anmol322
 */

#ifndef DATA_STRUCTURE_BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_
#define DATA_STRUCTURE_BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_

/**
 * @todo add function for height.
 * @todo comments.
 */

#include <memory>
#include <utility>
#include <vector>

template <typename Type>
class BST {
 private:
    struct TreeNode {
        Type data;
        std::shared_ptr<TreeNode> left{nullptr};
        std::shared_ptr<TreeNode> right{nullptr};

        TreeNode() = default;
        ~TreeNode() = default;
        TreeNode(TreeNode&&) = default;
        TreeNode& operator=(TreeNode&&) = default;
        TreeNode(const TreeNode&) = default;
        TreeNode& operator=(const TreeNode&) = default;

        template <typename T>
        explicit TreeNode(T&& t_data) : data(std::forward<T>(t_data)) {}
    };

    enum traversal : uint8_t { preorder = 0, inorder, postorder };

 private:
    Type findMin(std::shared_ptr<TreeNode> node) {
        if (!node->left) {
            return node->data;
        }
        return findMin(node->left);
    }

    std::shared_ptr<TreeNode> remove(std::shared_ptr<TreeNode> node,
                                     const Type& t_data) {
        if (!node) {
            return node;
        } else if (t_data > node->data) {
            node->right = remove(node->right, t_data);
        } else if (t_data < node->data) {
            node->left = remove(node->left, t_data);
        } else {
            if (!node->left && !node->right) {
                node = nullptr;
            } else if (!node->left) {
                node = node->right;
            } else if (!node->right) {
                node = node->left;
            } else {
                node->data = findMin(node->right);
                node->right = remove(node->right, node->data);
            }
        }
        return node;
    }

    void traverse(const std::shared_ptr<TreeNode>& root, std::vector<Type>* vec,
                  const traversal& algo) {
        if (!root) {
            return;
        }

        if (algo == preorder) {
            vec->emplace_back(root->data);
            traverse(root->left, vec, algo);
            traverse(root->right, vec, algo);
        } else if (algo == inorder) {
            traverse(root->left, vec, algo);
            vec->emplace_back(root->data);
            traverse(root->right, vec, algo);
        } else {
            traverse(root->left, vec, algo);
            traverse(root->right, vec, algo);
            vec->emplace_back(root->data);
        }
    }

 public:
    BST() = default;
    ~BST() = default;
    BST(BST&&) = default;
    BST& operator=(BST&&) = default;
    BST(const BST&) = default;
    BST& operator=(const BST&) = default;

    void insert(const Type& t_data);
    void insert(Type&& t_data) noexcept;

    std::shared_ptr<TreeNode> find(const Type& t_data);

    void remove(const Type& t_data);

    std::vector<Type> preOrder();
    std::vector<Type> inOrder();
    std::vector<Type> postOrder();

    const std::shared_ptr<TreeNode>& getRoot() const { return this->m_Root; }

 private:
    std::shared_ptr<TreeNode> m_Root;
};

#endif  // DATA_STRUCTURE_BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H_

/**
 * Copyright 2020 @author Anmol322
 */
#include "./include/binary_search_tree.h"

template <typename Type>
void BST<Type>::insert(const Type& t_data) {
    std::shared_ptr<TreeNode> parent = nullptr;
    auto tmp = m_Root;
    while (tmp) {
        parent = tmp;
        if (t_data > tmp->data) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
    }

    if (!parent) {
        m_Root = std::make_shared<TreeNode>(t_data);
    } else if (t_data < parent->data) {
        parent->left = std::make_shared<TreeNode>(t_data);
    } else {
        parent->right = std::make_shared<TreeNode>(t_data);
    }
}

template <typename Type>
void BST<Type>::insert(Type&& t_data) noexcept {
    std::shared_ptr<TreeNode> parent = nullptr;
    std::shared_ptr<TreeNode> tmp = m_Root;
    while (tmp) {
        parent = tmp;
        if (t_data > tmp->data) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
    }

    if (!parent) {
        m_Root = std::make_shared<TreeNode>(std::move(t_data));
    } else if (t_data < parent->data) {
        parent->left = std::make_shared<TreeNode>(std::move(t_data));
    } else {
        parent->right = std::make_shared<TreeNode>(std::move(t_data));
    }
}

template <typename Type>
std::shared_ptr<typename BST<Type>::TreeNode> BST<Type>::find(
    const Type& t_data) {
    auto tmp = m_Root;
    while (tmp) {
        if (t_data == tmp->data) {
            return tmp;
        } else if (t_data > tmp->data) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
    }

    return nullptr;
}

template <typename Type>
void BST<Type>::remove(const Type& t_data) {
    m_Root = remove(m_Root, t_data);
}

template <typename Type>
std::vector<Type> BST<Type>::preOrder() {
    std::vector<Type> ret;
    traverse(m_Root, &ret, preorder);
    return ret;
}

template <typename Type>
std::vector<Type> BST<Type>::inOrder() {
    std::vector<Type> ret;
    traverse(m_Root, &ret, inorder);
    return ret;
}

template <typename Type>
std::vector<Type> BST<Type>::postOrder() {
    std::vector<Type> ret;
    traverse(m_Root, &ret, postorder);
    return ret;
}

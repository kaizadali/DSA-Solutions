/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Iterative Preorder Traversal using stack (Root -> Left -> Right)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;

        if (root == nullptr) return result;

        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);

            // Push right first so that left is processed first
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
        }
        return result;
    }

    /*
    // Recursive Preorder Traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

    void preorderHelper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->val);
        preorderHelper(root->left, result);
        preorderHelper(root->right, result);
    }
    */
};

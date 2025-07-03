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
    // Iterative Inorder Traversal: Left -> Root -> Right
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // Reach the leftmost node of the current node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Current must be nullptr at this point
            curr = st.top();
            st.pop();

            result.push_back(curr->val); // Visit the node

            // Visit the right subtree
            curr = curr->right;
        }

        return result;
    }
};

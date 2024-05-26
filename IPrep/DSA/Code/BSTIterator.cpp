#include <stack>
#include <iostream>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Inorder traversal
// isReverse == false, gives next in ascending order
// isReverse == true, gives next in descending order
// max space -> O(H), where H -> height of BST
class BSTIterator
{
public:
    bool isReverse;
    stack<TreeNode *> st;
    BSTIterator(TreeNode *root, bool isReverse)
    {
        this->isReverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *currNode = st.top();
        st.pop();
        if (isReverse)
        {
            pushAll(currNode->left);
        }
        else
        {
            pushAll(currNode->right);
        }

        return currNode->val;
    }

private:
    void pushAll(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        st.push(root);
        if (isReverse)
        {
            pushAll(root->right);
        }
        else
        {

            pushAll(root->left);
        }
    }
};

int main()
{
    return 0;
}
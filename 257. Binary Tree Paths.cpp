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
class Solution {
    private:
    vector<string>ans;
    void fun(TreeNode *root,string str)
    {
        if(root == NULL)
            return;
        str += to_string(root->val)+"->";
        if(root->left == NULL && root->right == NULL)
        {
            str.pop_back();
            str.pop_back();
            ans.push_back(str);
        }
        fun(root->left,str);
        fun(root->right,str);
        str.pop_back();
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string str =  "";
        fun(root,str);
        
        return ans;
        
    }
};
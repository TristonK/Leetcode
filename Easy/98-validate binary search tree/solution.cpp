#include<bits/stdc++.h>
using namespace std;

/*Definition for a binary tree node.*/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> pretravel;
    void pre_travel(TreeNode* root){
        if(root!=NULL){
            pre_travel(root->left);
            pretravel.push_back(root->val);
            pre_travel(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        while(pretravel.size()){
            pretravel.pop_back();
        }
        //注意对空值判断。
        if(root==NULL)
            return true;
        pre_travel(root);
        for(int i=0;i<pretravel.size()-1;i++){
            if(pretravel[i]>=pretravel[i+1])
                return false;
        }
        return true;
    }
};

//一种更高效的做法
class Solution2 {
    
    bool isValidBSTLeft(TreeNode* root, long minimum, long maximum) {
         
        if (root == NULL)
            return true;
        
        if (root->val > minimum && root->val < maximum) 
            return isValidBSTLeft(root->left, minimum, root->val) && isValidBSTRight(root->right, root->val, maximum);
        
        return false;
    }
    
    bool isValidBSTRight(TreeNode* root, long minimum, long maximum) {
         
        if (root == NULL)
            return true;

        if (root->val > minimum && root->val < maximum) 
            return isValidBSTLeft(root->left, minimum, root->val) && isValidBSTRight(root->right, root->val, maximum);
        
        return false;
    }
    
    
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
                
        return (isValidBSTLeft(root->left, LONG_MIN, root->val) && isValidBSTRight(root->right, root->val, LONG_MAX));
    }
};
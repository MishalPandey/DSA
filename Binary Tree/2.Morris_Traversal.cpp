// IN ORDER 

//Solution 1 --> Concept of travesal with S.C{O(1)}, T.C{O(3*n)}

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
public:

    TreeNode* get_rightmost_node(TreeNode* node, TreeNode* curr)
    {
            while(node->right != nullptr && node->right != curr)
            {
                node= node->right;
            }

            return node;

    }
    
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>ans;
        TreeNode *curr = root;

        while(curr != nullptr)
        {
                TreeNode *ln = curr->left; 

                if(ln != nullptr)
                {
                        ln = get_rightmost_node(ln, curr); //righmost node of left child
                        if(ln->right == nullptr)
                        {
                            //create thread
                            ln->right = curr;
                            curr = curr->left;

                        }
                        else // means ln== curr
                        {
                            //cut thread
                            ans.push_back(curr->val);
                            curr= curr->right;
                            ln->right = nullptr;

                        }

                }
                else
                {
                    ans.push_back(curr->val);
                    curr = curr->right;

                }
        }

        return ans;
    }
};


//PRE ORDER

class Solution {
public:

        TreeNode* get_rightmost_node(TreeNode* node, TreeNode* curr)
        {
                while(node->right != nullptr && node->right != curr)
                {
                    node= node->right;
                }

                return node;

        }

    
        vector<int> preorderTraversal(TreeNode* root) {

                vector<int>ans;
                TreeNode *curr = root;

                while(curr != nullptr)
                {
                        TreeNode *ln = curr->left; 

                        if(ln != nullptr)
                        {
                                ln = get_rightmost_node(ln, curr); //righmost node of left child
                                if(ln->right == nullptr)
                                {
                                    //create thread
                                    ans.push_back(curr->val);
                                    ln->right = curr;
                                    curr = curr->left;

                                }
                                else // means ln== curr
                                {
                                    //cut thread
                                    curr= curr->right;
                                    ln->right = nullptr;

                                }

                        }
                        else
                        {
                            ans.push_back(curr->val);
                            curr = curr->right;

                        }
                }

                
                return ans;
                
        }
};


   //POST ORDER

class Solution {
public:

    TreeNode* get_rightmost_node(TreeNode* node, TreeNode* curr)
    {
            while(node->left != nullptr && node->left != curr)
            {
                node= node->left;
            }

            return node;

    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;
        TreeNode *curr = root;

        while(curr != nullptr)
        {
                TreeNode *ln = curr->right; 

                if(ln != nullptr)
                {
                        ln = get_rightmost_node(ln, curr); //righmost node of right child
                        if(ln->left == nullptr)
                        {
                            //create thread
                            ans.push_back(curr->val);
                            ln->left = curr;
                            curr = curr->right;

                        }
                        else // means ln== curr
                        {
                            //cut thread
                            curr= curr->left;
                            ln->left = nullptr;

                        }

                }
                else
                {
                    ans.push_back(curr->val);
                    curr = curr->left;

                }
                
        }
        reverse(ans.begin(), ans.end());

                
        return ans;
        
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if (n < 1)
            return result;
        result.push_back(new TreeNode(1));
        for (int i = 2; i <= n; i++)
        {
            MakeBST(result, i);
        }
        return result;
        
    }

private:

void MakeBST(vector<TreeNode *> & result, int n)
{
    int temptotal = result.size();
    for(int i = 0; i < temptotal; i++)
    {
        for(int depth = 0; ; depth ++)
        {
            //拷贝result[i]对应的树
            TreeNode * tempnode = new TreeNode(0);
            CopyTree(result[i], tempnode);          
            
            //向右下降depth的高度
            int tempdepth = depth;
            TreeNode * p = tempnode;
            while (tempdepth != 0)
            {
                p = p -> right;
                tempdepth --;   
            }                               
            
            //判断该节点无右节点
            if (p -> right == NULL)
            {
                p -> right = new TreeNode(n);
                result.push_back(tempnode);
                break;
            }
            
            //该节点有右节点
            else
            {
                TreeNode * tree_n = new TreeNode(n);
                tree_n -> left = p -> right;
                p -> right = tree_n;
                result.push_back(tempnode);
            }
        }
    }
    for(int i = 0; i < temptotal; i++)
    {
        TreeNode * temp = new TreeNode(n);
        temp -> left = result[i];
        result[i] = temp;
    }
    
}

void CopyTree(TreeNode * target, TreeNode * result)
{
    if (target == NULL)
        return;
    result -> val = target -> val;
    if (target -> left != NULL)
    {
        result -> left = new TreeNode(0);
        CopyTree(target -> left, result -> left);
    }
    
    if (target -> right != NULL)
    {
        result -> right = new TreeNode(0);
        CopyTree(target -> right, result -> right);
    }
    return;
}
};

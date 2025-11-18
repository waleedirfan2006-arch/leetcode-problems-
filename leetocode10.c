/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode* root, int targetSum, int* path, int pathLen,
         int** result, int* returnSize, int* returnColumnSizes) {
    if (!root) return;
    
    path[pathLen] = root->val;
    pathLen++;
    
    // If leaf node
    if (!root->left && !root->right) {
        if (targetSum == root->val) {
            // Add a copy of path to result
            int* tmp = (int*)malloc(pathLen * sizeof(int));
            for (int i = 0; i < pathLen; i++) tmp[i] = path[i];
            result[*returnSize] = tmp;
            returnColumnSizes[*returnSize] = pathLen;
            (*returnSize)++;
        }
    } else {
        // Recurse into children
        dfs(root->left, targetSum - root->val, path, pathLen, result, returnSize, returnColumnSizes);
        dfs(root->right, targetSum - root->val, path, pathLen, result, returnSize, returnColumnSizes);
    }
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(1000 * sizeof(int*)); // maximum paths
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    
    int path[1000]; // maximum depth of tree
    dfs(root, targetSum, path, 0, result, returnSize, *returnColumnSizes);
    
    return result;
}

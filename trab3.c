/*
struct TreeNode{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};
*/
void getDepthAndParent(struct TreeNode* root, int x, int depth, int* nodeDepth, struct TreeNode** parent, struct TreeNode* parentNode) {
  if (root == NULL) {
    return;
  }

  if (root->val == x) {
    *nodeDepth = depth;
    *parent = parentNode;
    return;
  }

  getDepthAndParent(root->left, x, depth + 1, nodeDepth, parent, root);
  getDepthAndParent(root->right, x, depth + 1, nodeDepth, parent, root);
}

bool isCousins(struct TreeNode* root, int x, int y){
  int depthX = -1, depthY = -1;
  struct TreeNode* parentX = NULL, *parentY = NULL;

  getDepthAndParent(root, x, 0, &depthX, &parentX, NULL);
  getDepthAndParent(root, y, 0, &depthY, &parentY, NULL);

  return (depthX == depthY) && (parentX != parentY);
}

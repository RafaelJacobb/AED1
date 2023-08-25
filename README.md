<h1>Trabalho prático 1 AED M2 Rafael Jacob de Melo</h1>


<body>
<h2>Estes são os códigos do exercicio do Leetcode.</h2>
  <p>Os arquivos "trab1" e "trabFinal" são referentes ao primeiro trabalho pedido e o arquivo "trab2" é referente ao segundo!</p>
</body>

/*
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

int getSibling(struct Node* prev, struct Node* root) {
    if (prev->left == root)
        return prev->right->val;
    return prev->left->val;
}

void traverse(struct Node* prev, struct Node* root, int x, int y, int* xDepth, int* yDepth, int* xSibling, int level) {
    if (root == NULL)
        return;
    if (root->val == x) {
        *xDepth = level;
        *xSibling = getSibling(prev, root);
    } 
    if (root->val == y)
        *yDepth = level;
    traverse(root, root->left, x, y, xDepth, yDepth, xSibling, level+1);
    traverse(root, root->right, x, y, xDepth, yDepth, xSibling, level+1);
}

int isCousins(struct Node* root, int x, int y) {
    int xDepth = -1, yDepth = -1, xSibling = -1;
    traverse(root, root, x, y, &xDepth, &yDepth, &xSibling, 0);
    //printf("xDepth = %d\nyDepth = %d\nxSibling = %d\n", xDepth, yDepth, xSibling);
    return (xDepth == yDepth) && (xSibling != y);
}
*/

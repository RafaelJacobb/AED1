// Definição da estrutura de um nó de árvore binária
struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// Função auxiliar que retorna a profundidade e o pai de um nó dado um valor
void getDepthAndParent(struct TreeNode* root, int x, int* depth, struct TreeNode** parent) {
  // Caso base: a raiz é nula ou tem o valor procurado
  if (root == NULL || root->val == x) {
    return;
  }
  
  // Se o filho esquerdo ou direito da raiz tem o valor procurado, atualiza a profundidade e o pai
  if ((root->left != NULL && root->left->val == x) || (root->right != NULL && root->right->val == x)) {
    *depth += 1;
    *parent = root;
    return;
  }
  
  // Recursivamente procura o valor nos subárvores esquerda e direita, incrementando a profundidade
  *depth += 1;
  getDepthAndParent(root->left, x, depth, parent);
  getDepthAndParent(root->right, x, depth, parent);
}

// Função principal que verifica se dois nós são primos
bool isCousins(struct TreeNode* root, int x, int y) {
  // Declara variáveis para armazenar a profundidade e o pai de cada nó
  int depthX = 0, depthY = 0;
  struct TreeNode* parentX = NULL, *parentY = NULL;
  
  // Obtém a profundidade e o pai de cada nó usando a função auxiliar
  getDepthAndParent(root, x, &depthX, &parentX);
  getDepthAndParent(root, y, &depthY, &parentY);
  
  // Retorna verdadeiro se as profundidades são iguais e os pais são diferentes, ou falso caso contrário
  return (depthX == depthY) && (parentX != parentY);
}

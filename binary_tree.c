#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int data;
	struct treeNode *right;
	struct treeNode *left;
} treeNode;

treeNode* getNode(int item) {
	treeNode *p = (treeNode*)malloc(sizeof(treeNode));
	p->data = item;
	p->right = p->left = NULL;

	return p;
}
// Inserting into the tree
treeNode* insert(treeNode *root, int item) {
	if(root==NULL) {
		root = getNode(item);
		return root;
	}
	if(root->data < item) {
		root->right = insert(root->right, item);
	} else {
		root->left = insert(root->left, item);
	}
	return root;
}

treeNode* minValNode(treeNode* node) {
	treeNode* cur = node;
	while(cur->left!=NULL)cur=cur->left; // Basically moving towards the least value element

	return cur;
}

// Deleting node from the tree we use minValNode function in this
treeNode* delete(treeNode *root, int key) {

	if(root==NULL)
		return NULL; // alternatively use return root;

	if(key < root->data)
		root->left = delete(root->left, key);
	else if(key > root->data)
		root->right = delete(root->right, key);
	else {
		if(root->left==NULL) {
			treeNode* tmp = root->right;
			free(root);
			return tmp;
		} else if(root->right==NULL) {
			treeNode* tmp = root->left;
			free(root);
			return tmp;
		}

		treeNode* tmp = minValNode(root->right);
		root->data = tmp->data;
		root->right = delete(root->right, tmp->data);

	}
	return root;
}

// BST Traversals
void inorder(treeNode* root) {
	if(root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode* root) {
	if(root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

void preorder(treeNode* root) {
	if(root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// Searching BST
treeNode* search(treeNode* root, int key) {
	if(root==NULL || root->data==key)
		return root;
	if(root->data < key)
		return search(root->right, key);

	return search(root->left, key);
}

// Find the minVal-recursion
treeNode* minValRec(treeNode* root) {
	if(root==NULL)return NULL;
	if(root->left!=NULL)
		return minValRec(root->left);
	else
		return root;
}

// Find the maxVal - recursion
treeNode* maxValRec(treeNode* root) {
	if(root==NULL)return NULL;
	if(root->right!=NULL)
		return maxValRec(root->right);
	else
		return root;
}

// Find the minVal- Iterative
treeNode* minVal(treeNode* root) {
	if(root==NULL)return NULL;

	treeNode* p = root;
	while(p->left!=NULL)p = p->left;

	return p;
}

// Find the maxVal- Iterative
treeNode* maxVal(treeNode* root) {
	if(root==NULL)return NULL;

	treeNode* p = root;
	while(p->right!=NULL)p = p->right;

	return p;
}


// The main function lads... fuck yeah!
int main() {
	/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80
	*/
	treeNode* root = NULL;
	int i = 0;
	int a[] = {50, 30, 70, 20, 40, 60, 80};
	for(i=0;i<7;i++) {
		root = insert(root, a[i]);
	}

	printf("Trvaersals: \n");

	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	printf("\n Deleting 50: \n");
	root = delete(root, 50);
	inorder(root);

	printf("\n\nSearching 30: \n");
	treeNode* node = search(root, 30);
	if(node)
		printf("Found: %d\n", node->data);
	else
		printf("\nNo such element");

	printf("\nMin Value: ");
	node = minVal(root);
	printf("%d\n", node->data);

	printf("\n Max Value: ");
	node = maxVal(root);
	printf("%d\n", node->data);

	return 0;
}

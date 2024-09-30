struct tree_el 
{
	int val;
	struct tree_el * right , * left;
};
typedef struct tree_el node; //declare a datatype: node
node *current; //declare a varibale of type node : *current

//funtion that counts elements in a tree

int count(node *current) //first pass *root as current node
{
	if(current==NULL)
		return 0; //no element in tree if root is NULL
	
	return 1+count(current->right)+count(current->left);
	//if root is not NULL, there are at least 1+(1+0+0)+(1+0+0) =3 elements on tree
	//suppose there are only root, right, left, right and left don't have child nodes
}

//funtion that counts sum of elemetns in a tree
int sum(node *current)
{
	//base case1:
	if(current==NULL)
		return 0; //no element at all, sum=0 or already at the bottom of the tree
	//base case2
	if(current->right == NULL && current->left == NULL)
		return current->val; //there's only current node and no child codes
	
	if(current->right != NULL && current->left == NULL)	
		return current->val + sum(current->right); //only right node

	if (current->right == NULL && current->left != NULL)
		return current->val + sum(current->left)//only left nodes
	
	return current->val + sum(current->right) + sum(current->left);
	//return current->val +((current->right!=NULL) ? sum(current->right) : 0)+((current->left!=NULL) ? sum(current->left) : 0)
}

//search an element on tree
tree_el *search(node *current, int target)
{
	if(current== NULL)
		return NULL;

	if(current->val == target)
		return current;

	node *left = search(current->left, target);
	node *right = search(current->right, target);

	if(left != NULL)
		return left;
	//if left result = NULL, means there's no target found, return right result, which could be found or NULL
	return right;
			
}

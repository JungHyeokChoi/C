#include <stdio.h>

struct node {
	int data;
	struct node* left_link;
	struct node* right_link;
};

int main() {

	struct node n1 = {10,NULL,NULL},
				n2 = { 20,NULL,NULL },
				n3 = { 30,NULL,NULL },
				n4 = { 40,NULL,NULL },
				n5 = { 50,NULL,NULL },
				n6 = { 60,NULL,NULL },
				n7 = { 70,NULL,NULL };

	n1.left_link = &n2;
	n1.right_link = &n3;

	n2.left_link = &n4;
	n2.right_link = &n5;

	n3.left_link = &n6;
	n3.right_link = &n7;

	printf("%d %d %d %d %d %d %d\n", n1.data, n2.data, n3.data, n4.data, n5.data, n6.data, n7.data);
	printf("%d %d %d %d %d %d %d\n", n1.data, n1.left_link->data, n1.right_link->data, n1.left_link->left_link->data,
		n1.left_link->right_link->data, n1.right_link->left_link->data, n1.right_link->right_link->data);

	return 0;
}
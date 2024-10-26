#include <stdio.h>
#include "bst.h"

void displayMenu(){
	printf("\nMENU: (Enter option no.)\n");
	printf("01. Insert Node.\n");
	printf("02. Remove Node.\n");
	printf("03. Preorder Traverse.\n");
	printf("04. Inorder Traverse.\n");
	printf("05. Postorder Traverse.\n");
	printf("06. Exit Program.\n");
	printf("\nEnter your choice: ");
	return;
}

int main(){
	int is_on = 1;
	int user_ip;
	char month[9];
	BST t;
	initBST(&t);
	while(is_on){
		displayMenu();
		scanf("%d", &user_ip);
		switch(user_ip){
			case 1:
				printf("Enter Valid Month: ");
				scanf("%s", month);
				insertNode(&t, month);
				break;

			case 2:
				printf("Enter Valid Month: ");
				scanf("%s", month);
				removeNode(&t, month);
				break;

			case 3:
				preorderTraverse(t);
				printf("\n");
				break;

			case 4:
				inorderTraverse(t);
				printf("\n");
				break;

			case 5:
				postorderTraverse(t);
				printf("\n");
				break;

			case 6:
				is_on = 0;
				break;

			default:
				printf("Invalid Menu Option.");
				break;
		}
	}
	destroyTree(&t);
	inorderTraverse(t);
	return 0;
}
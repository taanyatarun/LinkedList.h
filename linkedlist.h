/*	1- Primary Operations on Singly Linked List

	2- Operations of Singly Linked List:	a) Polynomial:	i) Representation
															ii) Addition
											b) Sparse Matrix
											
	3- Primary Operations on Circular Linked List
	
	4- Some Secondary Operations on Singly Linked List: a) Insert Middle
														b) Delete Middle
														c) Reverse
														d) Node Swapping
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	void* data;
	struct Node* next;
	int type;
}node;

typedef struct Sparse{
	void* data;
	int RN;
	int CN;
	int type;
	struct Sparse *next;
}SP;

typedef struct Poly{
	void* Co;
	void* Ex;
	int type_co;
	int type_ex;
	struct Poly *next;
}PL;


//Primary Operations of Linked List


void displayDataMenu(){
	printf("\n\t1- Integer \n\t2- Character \n\t3- Float \n\t4- String \n");
	printf("\tEnter choice: ");
}

void displayPrimaryFunc(){
	printf("\n------------------MENU-------------------------------\n");
	printf("\t1- Insert First \n\t2- Insert Random \n\t3- Insert Last \n\t4- Delete First \n\t5- Delete Random \n\t6- Delete Last \n\t7- Size \n\t8- Display \n");
}

int size(node *Head){
	node *p;
	int sz = 0;
	for(p = Head; p != NULL; p = p->next, sz++);
	return sz;
}

void insertFirst(node** Head, void* new_data, size_t data_size){
	int type;
	
	if(data_size == sizeof(int))
		type = 1;
	else if(data_size == sizeof(char))
		type = 2;
	else if(data_size == sizeof(float))
		type = 3;
	else
		type = 4;
		
	node* temp = (node*)malloc(sizeof(node));
	temp->data = malloc(data_size);
	temp->next = NULL;
	temp->type = type;
	memcpy(temp->data, new_data, data_size + 1);
		
	if(*Head == NULL){
		*Head = temp;
		return;
	}
	
	temp->next = *Head;
	*Head = temp;
}

void insertLast(node **Head, void* new_data, size_t data_size){
	int type;
	
	if(data_size == sizeof(int))
		type = 1;
	else if(data_size == sizeof(char))
		type = 2;
	else if(data_size == sizeof(float))
		type = 3;
	else
		type = 4;
	
	node *p, *temp = (node*)malloc(sizeof(node));
	temp->data = malloc(data_size);
	temp->next = NULL;
	temp->type = type;
	memcpy(temp->data, new_data, data_size + 1);
		
	if(*Head == NULL){
		*Head = temp;
		return;
	}
	
	for(p = *Head; p->next != NULL; p = p->next);
	p->next = temp;
}

void insertRandom(node **Head, void* new_data, size_t data_size, int pos){
	int type, i, l = size(*Head);;
	
	if(data_size == sizeof(int))
		type = 1;
	else if(data_size == sizeof(char))
		type = 2;
	else if(data_size == sizeof(float))
		type = 3;
	else
		type = 4;
	
	node *p, *temp = (node*)malloc(sizeof(node)); 
	temp->data = malloc(data_size);
	temp->next = NULL;
	temp->type = type;
	memcpy(temp->data, new_data, data_size + 1);
	
	if (pos == 1)
		insertFirst(Head, new_data, data_size);
		
	else if(pos == l + 1)
		insertLast(Head, new_data, data_size);
		
	else if(pos < 1 || pos > l + 1)
		printf("\nInvalid Position!\n");
		
	else if(pos > 1 && pos <= l)
	{
		for(p = *Head, i = 1; i < (pos - 1); p = p->next, i++);
		temp->next = p->next;
		p->next = temp;
	}
}

void display(node* Head){
	node *p = Head;
	
	printf("\n");
	while (p != NULL)
	{
		switch(p->type){
			case 1: printf("%d --> ", *(int*)p->data);
					break;
					
			case 2: printf("%c --> ", *(char*)p->data);
					break;
			
			case 3: printf("%f --> ", *(float*)p->data);
					break;
					
			case 4: printf("%s --> ", (char*)p->data);
					break;
			
		}
		p = p->next;
	}
	printf("NULL\n");
}


void derefDeleted(node *p){
	
	switch(p->type){
		case 1: printf("\nElement Deleted:  %d\n", *(int*)p->data);
				break;
				
		case 2: printf("\nElement Deleted:  %c\n", *(char*)p->data);
				break;
		
		case 3: printf("\nElement Deleted:  %f\n", *(float*)p->data);
				break;
					
		case 4: printf("\nElement Deleted:  %s\n", (char*)p->data);
				break;
	}
}

void* deleteFirst(node **Head){
	node *p = *Head;
	void *x;
	
	if(*Head == NULL){
		printf("\nLinked List is empty!\n");
		return NULL;
	}
	
	*Head = p->next;
	x = p->data;
	derefDeleted(p);
	free(p);
	return x;
}

void* deleteLast(node **Head){
	node *p, *t;
	void* x;
	
	if(*Head == NULL){
		printf("\nLinked List is empty!\n");
		return NULL;
	}
	
	for(p = *Head; p->next != NULL; t = p, p = p->next);
	
	if(p == *Head)
		*Head = NULL;
	else
		t->next = NULL;
		
	x = p->data;
	derefDeleted(p);
	free(p);
	return x;
}

void* deleteRandom(node **Head, int pos){
	node *p, *t;
	int i, l = size(*Head);
	void* x;
	
	if(*Head == NULL){
		printf("\nLinked List is empty!\n");
		return NULL;
	}
	
	if(pos == 1)
		return deleteFirst(Head);
		
	else if(pos == l)
		return deleteLast(Head);
		
	else if(pos < 1 || pos > l){
		printf("\nInvalid Position\n");
		return NULL;
	}
	
	else{
		for(p = *Head, i = 1; i < (pos - 1); p = p->next, i++);
		t = p->next;
		p->next = t->next;
		x = t->data;
		derefDeleted(t);
		free(t);
		return x;
	}
}

void freeAll(node **Head){
	node *temp = *Head, *temp1;
	
	while (temp != NULL)
	{
		temp1 = temp;
		temp = temp->next;
		free(temp1);
	}

	*Head = NULL;
}

//Polynomial using Linked List

void displayPolynomialDataTypes(){
	printf("\n------------------Data Types allowed for polynomial------------------\n");
	printf("\t1- Integer \n\t2- Float \n");
}

void insertPoly(PL **Head, void *co, int type_co, void *ex, int type_ex){
	PL *p, *temp = (PL*)malloc(sizeof(PL));
	int data_size_co, data_size_ex;
	
	switch(type_co){
		case 1: data_size_co = sizeof(int);
				break;
		case 2: data_size_co = sizeof(float);
				break;
	}
	
	switch(type_ex){
		case 1: data_size_ex = sizeof(int);
				break;
		case 2: data_size_ex = sizeof(float);
				break;
	}
	
	temp->Co = malloc(data_size_co);
	temp->Ex = malloc(data_size_ex);
	temp->type_co = type_co;
	temp->type_ex = type_ex;
	temp->next = NULL;
	memcpy(temp->Co, co, data_size_co);
	memcpy(temp->Ex, ex, data_size_ex);
		
	if(*Head == NULL){
		*Head = temp;
		return;
	}
	
	for(p = *Head; p->next != NULL; p = p->next);
	p->next = temp;
}

void displayPoly(PL* Head){
	PL *p = Head;
	printf("\n");
	
	while (p->next != NULL)
	{
		switch(p->type_co){
			case 1: printf("%d^", *(int*)p->Co);
					break;
					
			case 2: printf("%f^", *(float*)p->Co);
					break;
					
		}
		
		switch(p->type_ex){
			case 1: printf("%d + ", *(int*)p->Ex);
					break;
					
			case 2: printf("%f + ", *(float*)p->Ex);
					break;
					
		}
		
		p = p->next;
	}
	
	switch(p->type_co){
		case 1: printf("%d^", *(int*)p->Co);
				break;
			
		case 2: printf("%f^", *(float*)p->Co);
				break;
			
	}
	
	switch(p->type_ex){
		case 1: printf("%d", *(int*)p->Ex);
				break;
				
		case 2: printf("%f", *(float*)p->Ex);
				break;
	}
	printf("\n\n");
}

PL* addPoly(PL *H1, PL *H2){
	PL *H = NULL, *p = H1, *t = H2;
	float p_Ex, t_Ex, p_Co_fl, t_Co_fl, x;
	int p_Co_in, t_Co_in;
	
	while(p != NULL && t != NULL){
		
		switch(p->type_ex){
			case 1: p_Ex = *(int*)p->Ex;
					break;
			case 2: p_Ex = *(float*)p->Ex;
					break;
		}
		
		switch(t->type_ex){
			case 1: t_Ex = *(int*)t->Ex;
					break;
			case 2: t_Ex = *(float*)t->Ex;
					break;
		}
		
		if(p_Ex > t_Ex){
			insertPoly(&H, p->Co, p->type_co, p->Ex, p->type_ex);
			p = p->next;
		}
		
		else if(t_Ex > p_Ex){
			insertPoly(&H, t->Co, t->type_co, t->Ex, t->type_ex);
			t = t->next;
		}
		
		else{
			x = 0;	
			switch(p->type_co){
				case 1: p_Co_in = *(int*)p->Co;
						x += p_Co_in;
						break;
				case 2: p_Co_fl = *(float*)p->Co;
						x += p_Co_fl;
						break;
			}
			
			switch(t->type_co){
				case 1: t_Co_in = *(int*)t->Co;
						x += t_Co_in;
						break;
				case 2: t_Co_fl = *(float*)t->Co;
						x += t_Co_fl;
						break;
			}
			
			insertPoly(&H, &x, 2, p->Ex, p->type_ex);
			p = p->next;
			t = t->next;
		}
	}
	
	while(p != NULL){
		insertPoly(&H, p->Co, p->type_co, p->Ex, p->type_ex);
		p = p->next;
	}
	
	while(t != NULL){
		insertPoly(&H, t->Co, t->type_co, t->Ex, t->type_ex);
		t = t->next;
	}
	return H;	
}

//Sparse Matrix using Linked List

void displaySparseDataTypes(){
	printf("\n------------------Data Types allowed for Sparse Matrix------------------\n");
	printf("\t1- Integer \n\t2- Float \n");
}

void initSparse(SP **Head){
	*Head = (SP*)malloc(sizeof(SP));
	(*Head)->RN = 0;
	(*Head)->CN = 0;
	(*Head)->next = NULL;
	return;
}

void insertSparse(SP **Head, int rn, int cn, void* element, int type){
	SP *p, *temp = (SP*)malloc(sizeof(SP));
	int data_size;
	
	switch(type){
		case 1: data_size = sizeof(int);
				break;
		case 2: data_size = sizeof(float);
				break;
	}
	
	temp->data = malloc(data_size);
	memcpy(temp->data, element, data_size);
	temp->RN = rn;
	temp->CN = cn;
	temp->next = NULL;
	temp->type = type;
	
	if((*Head)->next == NULL){
		(*Head)->next = temp;
		return;
	}
	
	for(p = (*Head)->next; p->next != NULL; p = p->next);
	p->next = temp;
}

void displaySparse(SP *Head){
	SP *p = Head->next;
	int i, j;
	
	if(p == NULL)
		printf("\nList is empty!\n");
		
	else{
		printf("\n  ");
		for(i = 0; i < Head->RN; i++){
			for(j = 0; j < Head->CN; j++){
				if((p != NULL) && (i == p->RN - 1) && (j == p->CN - 1)){
					switch(p->type){
						case 1: printf("%8d  ", *(int*)p->data);
							break;
					
						case 2: printf("%f  ", *(float*)p->data);
								break;
					
					}
					p = p->next;
				}
				
				else{
					printf("00000000  ");
				}
			}
			printf("\n\n  ");
		}
	}
}

//Primary Operations on Circular Linked List

void insertFirstCircular(node** Head, node **Last, void* new_data, size_t data_size){
	node* temp = (node*)malloc(sizeof(node));
	int type;
	
	if(data_size == sizeof(int))
		type = 1;
	else if(data_size == sizeof(char))
		type = 2;
	else if(data_size == sizeof(float))
		type = 3;
	else
		type = 4;
		
	temp->data = malloc(data_size);
	temp->next = NULL;
	temp->type = type;
	memcpy(temp->data, new_data, data_size);
		
	if(*Head == NULL){
		*Head = *Last = temp;
		(*Last)->next = *Head;
		return;
	}
	
	temp->next = *Head;
	*Head = temp;
	(*Last)->next = *Head;
}

void insertLastCircular(node **Head, node **Last, void* new_data, size_t data_size){
	node *p, *temp = (node*)malloc(sizeof(node));
	int type;
	
	if(data_size == sizeof(int))
		type = 1;
	else if(data_size == sizeof(char))
		type = 2;
	else if(data_size == sizeof(float))
		type = 3;
	else
		type = 4;
		
	temp->data = malloc(data_size);
	temp->next = NULL;
	temp->type = type;
	memcpy(temp->data, new_data, data_size);
		
	if(*Head == NULL){
		*Head = *Last = temp;
		(*Last)->next = *Head;
		return;
	}
	
	(*Last)->next = temp;
	*Last = temp;
	(*Last)->next = *Head;
}

void insertRandomCircular(node **Head, node **Last, void* new_data, size_t data_size, int pos){
	node *p, *temp = (node*)malloc(sizeof(node));
	int i, l = size(*Head);
	int type;
	
	if(data_size == sizeof(int))
		type = 1;
	else if(data_size == sizeof(char))
		type = 2;
	else if(data_size == sizeof(float))
		type = 3;
	else
		type = 4;
		
	temp->data = malloc(data_size);
	temp->next = NULL;
	temp->type = type;
	memcpy(temp->data, new_data, data_size);
	
	if (pos == 1)
		insertFirstCircular(Head, Last, new_data, data_size);
		
	else if(pos == l + 1)
		insertLastCircular(Head, Last, new_data, data_size);
		
	else if(pos < 1 || pos > l + 1)
		printf("\nInvalid Position!\n");
		
	else if(pos > 1 && pos <= l)
	{
		for(p = *Head, i = 1; i < (pos - 1); p = p->next, i++);
		temp->next = p->next;
		p->next = temp;
	}
}

void* deleteFirstCircular(node **Head, node **Last){
	node *p = *Head;
	void *x;
	
	if(*Head == NULL){
		printf("\nLinked List is empty!\n");
		return NULL;
	}
	
	x = p->data;	
	if(*Head == *Last)
		*Head = *Last = NULL;
	
	else{
		*Head = p->next;
		(*Last)->next = *Head;
	}
	
	derefDeleted(p);
	free(p);
	return x;
}

void* deleteLastCircular(node **Head, node **Last){
	node *p = *Head;
	void* x;
	
	if(*Head == NULL){
		printf("\nLinked List is empty!\n");
		return NULL;
	}
		
	if(*Head == *Last){
		*Head = *Last = NULL;
	}
	else{
		for(p = *Head; p->next != *Last; p = p->next);
		*Last = p;
		p = p->next;
		(*Last)->next = *Head;
	}
	x = p->data;
	derefDeleted(p);
	free(p);
	return x;
}

void* deleteRandomCircular(node **Head, node **Last, int pos){
	node *p, *t;
	int i, l = size(*Head);
	void* x;
	
	if(*Head == NULL){
		printf("\nLinked List is empty!\n");
		return NULL;
	}
	
	if(pos == 1)
		return deleteFirstCircular(Head, Last);
		
	else if(pos == l)
		return deleteLastCircular(Head, Last);
		
	else if(pos < 1 || pos > l){
		printf("\nInvalid Position\n");
		return NULL;
	}
	
	else{
		for(p = *Head, i = 1; i < (pos - 1); p = p->next, i++);
		t = p->next;
		p->next = t->next;
		x = t->data;
		derefDeleted(t);
		free(t);
		return x;
	}
}

void displayCircular(node *Head){
	node *p;
	p = Head;
	if(Head == NULL) 
		printf("\nList is empty!\n");
	else{
		do{
			switch(p->type){
				case 1: printf("%d --> ", *(int*)p->data);
						break;
					
				case 2: printf("%c --> ", *(char*)p->data);
						break;
				
				case 3: printf("%f --> ", *(float*)p->data);
						break;
					
				case 4: printf("%s --> ", (char*)p->data);
						break;
			
			}
			p = p->next;
		}while(p != Head);
		
		printf("NULL");
	}
}

//Some Secondary Operations of Singly Linked List

void insertMiddle(node **Head, void* new_data, size_t data_size){
	int i, l = size(*Head), pos = (l / 2) + 1, type;
	
	if(data_size == sizeof(int))
		type = 1;
	else if(data_size == sizeof(char))
		type = 2;
	else if(data_size == sizeof(float))
		type = 3;
	else
		type = 4;
		
	node *p, *temp = (node*)malloc(sizeof(node));
	temp->data = malloc(data_size);
	temp->next = NULL;
	temp->type = type;
	memcpy(temp->data, new_data, data_size + 1);
	
	if (pos == 1)
		insertFirst(Head, new_data, data_size);
		
	else if(pos == l + 1)
		insertLast(Head, new_data, data_size);
		
	else if(pos > 1 && pos <= l)
	{
		for(p = *Head, i = 1; i < (pos - 1); p = p->next, i++);
		temp->next = p->next;
		p->next = temp;
	}
}

void* deleteMiddle(node **Head){
	node *p, *t;
	int i, l = size(*Head), pos;
	void* x;
	
	if(*Head == NULL){
		printf("\nLinked List is empty!\n");
		return NULL;
	}
	
	if (l % 2 == 0)
		pos = l / 2;
	else
		pos = (l / 2) + 1;
	
	if(pos == 1)
		return deleteFirst(Head);
		
	else if(pos == l)
		return deleteLast(Head);
	
	else{
		for(p = *Head, i = 1; i < (pos - 1); p = p->next, i++);
		t = p->next;
		p->next = t->next;
		x = t->data;
		derefDeleted(t);
		free(t);
		return x;
	}
}

void reverse(node **Head){
	node *F, *p, *t;
	
	for(F = *Head; F->next != NULL; F = F->next);
	do{
		for(p = *Head; p->next != NULL; t = p, p = p->next);
		p->next = t;
		t->next = NULL;
	}while((*Head)->next != NULL);
	*Head = F;
}

void nodeSwap(node **Head, int pos1, int pos2){
	node *p1, *p2, *q, *t, *temp;
	int i, tem;
	
	if(pos1 > pos2){
		tem = pos1;
		pos1 = pos2;
		pos2 = tem;
	}
	
	for(p1 = *Head, i = 1; i < pos1; t = p1, i++, p1 = p1->next);
	for(p2 = *Head, i = 1; i < pos2; q = p2, i++, p2 = p2->next);
	if(p1 == *Head)
		*Head = p2;
	else
		t->next = p2;
	q->next = p1;
	temp = p2->next;
	p2->next = p1->next;
	p1->next = temp;
}


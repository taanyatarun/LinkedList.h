#include "linkedlist.h"

void main(){
	node *Head = NULL;
	PL *H1 = NULL, *H2 = NULL, *H = NULL;
	SP *HeadS;
	void *deleted, *temp;
	int choice, ch, data_int, pos, sz, flag, int_co, int_ex, ch_co, ch_ex, i, x, rn, cn, n, pos1, pos2;
	char data_char, data_str[50];
	float data_float, float_co, float_ex, xf;
	do{
		printf("\n------------------MENU-------------------------------\n");
		printf("\t1- Insert First \n\t2- Insert Random \n\t3- Insert Middle \n\t4- Insert Last \n\t5- Delete First \n\t6- Delete Random \n\t7- Delete Middle \n\t8- Delete Last \n\t9- Size \n\t10- Display \n\t11- Polynomial \n\t12- Sparse matrix \n\t13- Reverse \n\t14- Node Swapping \n\t15- Search \n\t16- Exit \n");
		printf("Enter Choice: ");
		scanf("%d", &choice);
		switch(choice){
			
			case 1: displayDataMenu();
					scanf("%d", &ch);
					printf("\n\tEnter Data: ");
					switch(ch){
						case 1: scanf("%d", &data_int);
								insertFirst(&Head, &data_int, sizeof(int));
								break; 
								
						case 2: fflush(stdin);
								scanf("%c", &data_char);
								insertFirst(&Head, &data_char, sizeof(char));
								break; 
								
						case 3: scanf("%f", &data_float);
								insertFirst(&Head, &data_float, sizeof(float));
								break; 
								
						case 4: fflush(stdin);
								scanf("%s", &data_str);
								insertFirst(&Head, &data_str, (sizeof(char) * strlen(data_str)));
								break; 
					}
					break;
					
			case 2: printf("\nEnter position: ");
					scanf("%d", &pos);
					displayDataMenu();
					scanf("%d", &ch);
					printf("\n\tEnter Data: ");
					switch(ch){
						case 1: scanf("%d", &data_int);
								insertRandom(&Head, &data_int, sizeof(int), pos);
								break; 
								
						case 2: fflush(stdin);
								scanf("%c", &data_char);
								insertRandom(&Head, &data_char, sizeof(char), pos);
								break; 
								
						case 3: scanf("%f", &data_float);
								insertRandom(&Head, &data_float, sizeof(float), pos);
								break; 
								
						case 4: fflush(stdin);
								scanf("%s", &data_str);
								insertRandom(&Head, &data_str, (sizeof(char) * strlen(data_str)), pos);
								break; 
					}
					break;
					
			case 3: displayDataMenu();
					scanf("%d", &ch);
					printf("\n\tEnter Data: ");
					switch(ch){
						case 1: scanf("%d", &data_int);
								insertMiddle(&Head, &data_int, sizeof(int));
								break; 
								
						case 2: fflush(stdin);
								scanf("%c", &data_char);
								insertMiddle(&Head, &data_char, sizeof(char));
								break; 
								
						case 3: scanf("%f", &data_float);
								insertMiddle(&Head, &data_float, sizeof(float));
								break; 
								
						case 4: fflush(stdin);
								scanf("%s", &data_str);
								insertMiddle(&Head, &data_str, (sizeof(char) * strlen(data_str)));
								break; 
					}
					break;
					
			case 4: displayDataMenu();
					scanf("%d", &ch);
					printf("\n\tEnter Data: ");
					switch(ch){
						case 1: scanf("%d", &data_int);
								insertLast(&Head, &data_int, sizeof(int));
								break; 
								
						case 2: fflush(stdin);
								scanf("%c", &data_char);\
								insertLast(&Head, &data_char, sizeof(char));
								break; 
								
						case 3: scanf("%f", &data_float);
								insertLast(&Head, &data_float, sizeof(float));
								break; 
								
						case 4: fflush(stdin);
								scanf("%s", &data_str);
								insertLast(&Head, &data_str, (sizeof(char) * strlen(data_str)));
								break; 
					}
					break;
					
			case 5: deleted = deleteFirst(&Head);
					break;
					
			case 6: printf("\nEnter position: ");
					scanf("%d", &pos);
					deleted = deleteRandom(&Head, pos);
					break;
			
			case 7: deleted = deleteMiddle(&Head);
					break;
					
			case 8: deleted = deleteLast(&Head);
					break;
					
			case 9: sz = size(Head);
					printf("\nSize of Linked List: %d", sz);
					break;
					
			case 10: display(Head);
					break;
					
			case 11: displayPolynomialDataTypes();
					printf("\nEnter number of terms in First polynomial: ");
					scanf("%d", &x);
					for(i = 0; i < x; i++){
						printf("\nEnter data type for coefficient: ");
						scanf("%d", &ch_co);
						printf("\nEnter coefficient: ");
						switch(ch_co){
							case 1: scanf("%d", &int_co);
									temp = &int_co;
									break;
							case 2: scanf("%f", &float_co);
									temp = &float_co;
									break;
						}
						printf("\nEnter data type for exponent: ");
						scanf("%d", &ch_ex);
						
						printf("\nEnter exponent: ");
						switch(ch_ex){
							case 1: scanf("%d", &int_ex);
									insertPoly(&H1, temp, ch_co, &int_ex, ch_ex);
									break;
							case 2: scanf("%f", &float_ex);
									insertPoly(&H1, temp, ch_co, &float_ex, ch_ex);
									break;
						}
					}
					displayPoly(H1);
					printf("\nEnter number of terms in Second polynomial: ");
					scanf("%d", &x);
					for(i = 0; i < x; i++){
						printf("\nEnter data type for coefficient: ");
						scanf("%d", &ch_co);
						printf("\nEnter coefficient: ");
						switch(ch_co){
							case 1: scanf("%d", &int_co);
									temp = &int_co;
									break;
							case 2: scanf("%f", &float_co);
									temp = &float_co;
									break;
						}
						printf("\nEnter data type for exponent: ");
						scanf("%d", &ch_ex);
						printf("\nEnter exponent: ");
						switch(ch_ex){
							case 1: scanf("%d", &int_ex);
									insertPoly(&H2, temp, ch_co, &int_ex, ch_ex);
									break;
							case 2: scanf("%f", &float_ex);
									insertPoly(&H2, temp, ch_co, &float_ex, ch_ex);
									break;
						}
					}
					displayPoly(H2);
					
					printf("\nAddition of the above two polynomials: \n");
					H = addPoly(H1, H2);
					displayPoly(H);
					break;
				
			case 12: initSparse(&HeadS);
					printf("\nEnter max rows: ");
					scanf("%d", &rn);
					printf("\nEnter max columns: ");
					scanf("%d", &cn);
	
					HeadS->RN = rn;
					HeadS->CN = cn;
	
					printf("\nEnter no. of info: ");
					scanf("%d", &n);
					for(i = 0; i < n; i++){
						printf("\nEnter row: ");
						scanf("%d", &rn);
						printf("\nEnter column: ");
						scanf("%d", &cn);
						printf("\nData types of info: ");
						printf("\n\t1- Integer \n\t2- Float");
						printf("\n\tEnter choice: ");
						scanf("%d", &ch);
						printf("\nEnter info: ");
						switch(ch){
							case 1: scanf("%d", &x);
									insertSparse(&HeadS, rn, cn, &x, 1);
									break;
									
							case 2: scanf("%f", &xf);
									insertSparse(&HeadS, rn, cn, &xf, 2);
									break;
						}
					}
					displaySparse(HeadS);
					break;
			
			case 13: reverse(&Head);
					display(Head);
					break;
			
			case 14: printf("\nEnter 2 positions: ");
					scanf("%d%d", &pos1, &pos2);
					nodeSwap(&Head, pos1, pos2);
					display(Head);
					break;
			
			case 15: displayDataMenu();
					scanf("%d", &ch);
					printf("\n\tEnter element to be searched: ");
					switch(ch){
						case 1: scanf("%d", &data_int);
								flag = search(Head, &data_int, ch);
								break; 
								
						case 2: fflush(stdin);
								scanf("%c", &data_char);\
								flag = search(Head, &data_char, ch);
								break; 
								
						case 3: scanf("%f", &data_float);
								flag = search(Head, &data_float, ch);
								break; 
								
						case 4: fflush(stdin);
								gets(data_str);
								flag = search(Head, &data_str, ch);
								break; 
					}
					if(flag == 1)
						printf("\nElement Found!");
					else
						printf("\nElement not found!");
					break;
			
			case 16: printf("\n---------------------------BYE BYE----------------------------------\n");
					break;
					
		}
	}while(choice != 16);
	
	freeAll(&Head);
}

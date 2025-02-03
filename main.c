//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;

    typedef struct node Node;
    typedef Node* NodePtr;

    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    struct node ex1;
    b.next = &ex1;
    //ex1.value = 11;
    b.next->value = 11;
    ex1.next = NULL;
    printf("ex1\n%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf ("%d\n", head->next->next->value);
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    struct node ex2;
    ex2.next = &a;
    head = &ex2;
    ex2.value = 2;
    printf("ex2\n%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf ("%d\n", head->next->next->value);
    printf ("%d\n", head->next->next->next->value);

    NodePtr tmp=head; //add temp value to faciliate
        
    //Exercise III Use loop to print everything
        printf("ex3\n");
        int i,n=5;
        for(i=0;i<n && tmp != NULL;i++){
            printf("%d)%-3d",i+1 , tmp->value);
            tmp = tmp->next;
          // What is missing???
        }
    
    
    
   //Exercise IV change to while loop!! (you can use NULL to help)
        printf("\n ex4\n");
        for(tmp = head; tmp != NULL; tmp = tmp->next){
            printf("%-3d", tmp->value);
           // What is missing???
        }
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
        */
        printf("\n ex5\n");
        head = (NodePtr)malloc(sizeof(Node));
        tmp = head;
        for(i=0; i<3; i++){
            tmp->value = i + 3;
            tmp->next = (NodePtr)malloc(sizeof(Node));
            tmp = tmp->next;
        }
        tmp->value = i + 3;
        tmp->next = NULL;

        for(tmp = head; tmp != NULL; tmp = tmp->next){
            printf("%-3d", tmp->value);
           // What is missing???
        }

    /*  Exercise VI Free all node !!
         //use a loop to help
         */
        for(tmp = head; tmp != NULL; tmp = head){
            head = head->next;
            printf("\nFree %d", tmp->value);
            free(tmp);
        }
        printf("\n");
    
    return 0;
}

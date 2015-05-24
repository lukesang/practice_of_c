
/* ch11 linklist.c */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
   	char name[8];
   	char id[8];
   	int age;
   	int weight;
   	struct node *link;
} head;

void getNode(struct node);
void show();
void insert(struct node );
void delete(char *);




int main()
{
    char key;
    char name[8];
	struct node data;
    head.link = NULL;
      
    printf("\nFunction : 0 [EXIT]     1 [SHOW]");
    printf("\n           2 [INSERT]   3 [DELETE]");
	printf("\n\n");
	  
    while(1) {
        key = getch();
        switch (key) {
      	    case '0' : printf("\nBye Bye !\n");
			    	   exit(1);
    	    case '1' : printf("\n <%c : Listing... >",key);
    		           show();
    		           break;
            case '2' : printf("\n <%c : INSERT ONE CHARACTER> Input : ", key);
            		   printf("\n");
    		           getNode(data);
      			       break;
      		case '3' : printf("\n <%c : DELETE ONE CHARACTER> Delete : ", key);
      			       scanf("%s",name);
      			       delete(name);
      			       break;
      		default  : continue;
        }
    }
    
    system("PAUSE");
    return 0;
}
/***************************************************************/
void getNode(struct node who)
{
	   printf("    Who ? ");
   	   scanf("%s", who.name);
   	   
   	   printf("    ID number ? ");
   	   scanf("%s", who.id);
   	   
   	   printf("    How old ? ");
   	   scanf("%d", &(who.age));
   	   
   	   printf("    Weight ? ");
   	   scanf("%d", &(who.weight));
   	   
   	   printf("\n");
   	   insert(who);
}

/***************************************************************/
void show()
{
    struct node *current;
    int count;
    current=head.link;
    printf("\nDATA LISTING ...\n\n");
    printf("  NUMBER       NAME         ID       AGE   WEIGHT");
    printf("\n\n");
    for (count=0; current!=NULL; current=current->link,count++){
   	   printf("    #%d",count+1);
   	   printf("	   %8s   %8s",current->name,current->id);
   	   printf("	   %5d %8d",current->age,current->weight);
   	   printf("\n");
   	}

}
  
/***************************************************************/

void insert(struct node data)
{
    struct node *current, *prev, *ptr;
    prev=&head;
    current=prev->link;
	while(current != NULL) {
	    prev=current;
		current=current->link;
		
    }

	if ((current != NULL) && (current->name == data.name)) {
      	printf("\n	Character '%s' existed!\n",&(data.name));
      	return;
    }
      
    if ((ptr = (struct node *) malloc(sizeof(struct node))) == NULL) {
      	printf("\nNot enough memory\n");
      	return;
    }
      
    /* construct link list */
    *ptr = data;
    ptr->link = prev->link;
    prev->link = ptr;
      
    printf("\n	Character '%s' inserted OK\n",&(data.name));
}
 
/***************************************************************/

void delete(char *del)
{
    struct node *current, *prev;
    prev=&head;
    current=prev->link;
	while(current != NULL && strcmp((current->name),del)<0) {
	    prev=current;
		current=current->link;
    }
    
    if (strcmp((current->name),del)==0) {
      	prev->link = current->link;
       	free(current);
      	printf("\n	Character '%s' deleted OK!\n", del);
    }
    else
        printf("\n	Character '%s' Not existed!\n", del);
}

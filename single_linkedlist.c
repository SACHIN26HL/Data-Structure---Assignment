#include <stdio.h>
#include <stdlib.h>


/*1. Insert First\n2. Insert Last\n3.Insert After Node\n4.Print \n5.Delete all nodes bigger than given data from the list \n");
   6.Delete all nodes between given numbers\n7.Delete all nodes less than given number from the list\n");
	8.Delete all nodes other than between given numbers\n9.Delete node at given position\n");
	10.Delete the node at given position from end.\n11.Count load in Linked list\n");
	12.Delete all nodes from at given position to beginning from end.\n13.Delete the node from list based on data after given occurrence\n");
	14. Delete all nodes at given position from end.
	*/

typedef struct node
{
	struct node *next;
	int data;

}single_ll;

enum
{
	FAILURE = 0,
	SUCCESS,
	DATA_NOTFOUND,
	EMPTY,
	NOT_POSS,
};

int llnode_count =0;

int insert_first(struct node **head, int value);
int print_list(struct node *head);
int insert_last(struct node **head, int value);
int delete_nbgnum( struct node **head, int data);
int delete_anbgnum(struct node **head, int data, int data1);
int delete_nlessgnum( struct node **head, int data);
int delete_othanbgnum( struct node **head, int data, int data1);
int delete_position(struct node **head, int pos);
int delete_position_fromend(struct node **head, int pos);
int count_node(struct node **head);
int delete_position_fromgptoend(struct node **head, int pos);
int delete_node_bgivenoccrrence(struct node **head, int data);
int delete_allnode_gpfromend(struct node **head, int pos);

int insert_afternode(struct node **head, int node, int data);

int main()
{
	int options;
	int value, value2;
	struct node *head = NULL;

       int status;


	while(1)
	{

		printf("\n\n1. Insert First\n2. Insert Last\n3.Insert After Node\n4.Print \n5.Delete all nodes bigger than given data from the list \n");
		printf("6.Delete all nodes between given numbers\n7.Delete all nodes less than given number from the list\n");
		printf("8.Delete all nodes other than between given numbers\n9.Delete node at given position\n");
		printf("10.Delete the node at given position from end.\n11.Count load in Linked list\n");
		printf("12.Delete all nodes from at given position to beginning from end.\n13.Delete the node from list based on data after given occurrence\n");
		printf("14. Delete all nodes at given position from end.\n");

		printf("Select options : ");
		scanf("%d",&options);

   		switch(options)
		{

			case 1:
				printf("Enter a value : ");
				scanf("%d", &value);

				status = insert_first(&head, value);

				if(status == SUCCESS)
				{
					printf("Data Inserted successfully\n");
				}
				break;
			case 2:
				printf("Enter a value : ");
				scanf("%d", &value);

				status = insert_last(&head, value);

				if(status == SUCCESS)
				{
					printf("Data Inserted successfully\n");
				}
				break;

			case 3:

					printf("Enter a node : ");
					scanf("%d", &value);
					printf("Enter a value : ");
					scanf("%d", &value2);
					count_node(&head);
					insert_afternode(&head, value, value2);
				break;


			case 4:
				printf("data is :");
				print_list(head);
				break;

			case 5:

				printf("Enter a value : ");
				scanf("%d", &value);
				status = delete_nbgnum(&head, value);
				if(status == DATA_NOTFOUND)
				{
					printf("Data not found in list\n");
				}
				else
				{
					printf("data removed successfully \n");
				}
				break;

			case 6:

				printf("Enter a value data and data1: \n" );
				scanf("%d %d", &value, &value2 );
				delete_anbgnum(&head, value, value2);
				break;

			case 7:
				printf("Enter a value : ");
				scanf("%d", &value);
			    delete_nlessgnum(&head, value);
				break;
			case 8:
				printf("Enter a value data and data1: \n" );
				scanf("%d %d", &value, &value2 );
				delete_othanbgnum(&head, value,value2);
				break;
			case 9:
				printf("Enter a position : ");
				scanf("%d", &value);
				delete_position(&head, value);
				break;

			case 10:
				printf("Enter a position : ");
				scanf("%d", &value);
				count_node(&head);
				delete_position_fromend(&head, value);
				break;
			case 11:
					count_node(&head);

					printf("Total Node is : %d", llnode_count);

				break;

			case 12:
				printf("Enter a position: ");
				scanf("%d", &value);
				count_node(&head);
				delete_position_fromgptoend(&head, value); 
				break;

			case 13:
				printf("Enter a position: ");
				scanf("%d", &value);
				delete_node_bgivenoccrrence(&head, value);
				break;

			case 14:
				printf("Enter a position: ");
				scanf("%d", &value);
				count_node(&head);
			   delete_allnode_gpfromend(&head, value);
			   break;
			default :

				printf("Select a valid number\n");
				break;
		}
	}
	return 0;
}

int insert_first(struct node **head, int value)
{
   struct node *temp = (struct node *) malloc(sizeof(struct node));

   temp->next = NULL;
   temp->data = value;

	
   if(*head == NULL)
   {
      *head = temp;
      return SUCCESS;      
   }

   temp->next = *head;
   *head = temp;

   return SUCCESS;

}


int print_list(struct node *head)
{
	if(head == NULL)
	{
		return EMPTY;
	}


	struct node *temp= head;
	while(temp)
	{
		printf("%d-->", temp->data);
		temp= temp->next;
	}

	return SUCCESS;

}


int insert_last(struct node**head , int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->next =NULL;
	temp->data = value;

	if(*head == NULL)
	{
		*head = temp;
		return SUCCESS;
	}


	struct node *temp_h = *head;
	while(temp_h->next)
	{
		temp_h = temp_h->next;
	}

	temp_h->next= temp;

	return SUCCESS;

}

int delete_nbgnum( struct node **head, int data) 
{

   struct node *temp;
   struct node *prev;
 
	
   temp =*head;

   printf("data : %d", temp->data);
	prev = temp;
   while(temp)
   {
   //	printf("data : %d", temp->data);
   	if(temp->data >= data)
   	{

   		//bigger data is in first node
   		if(prev == temp)
   		{
   			prev = temp->next;
   			free(temp);
   			temp = prev;
   			*head = prev;
   			continue;

   		}
   		//middle part 
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		continue;
   	}
   	
   	prev = temp;
   	temp = temp->next;

   }
 
   return SUCCESS;


}

int delete_anbgnum(struct node **head, int data, int data1)
{
	struct node *temp;
   struct node *prev;
 
	
   temp =*head;

   printf("data : %d", temp->data);
	prev = temp;
   while(temp)
   {
   //	printf("data : %d", temp->data);
   	if(temp->data >= data && temp->data <= data1)
   	{

   		//bigger data is in first node
   		if(prev == temp)
   		{
   			prev = temp->next;
   			free(temp);
   			temp = prev;
   			*head = prev;
   			continue;

   		}
   		//middle part 
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		continue;
   	}
   	
   	prev = temp;
   	temp = temp->next;
   }
}

int delete_nlessgnum( struct node **head, int data) 
{

   struct node *temp;
   struct node *prev;
 
	
   temp =*head;

   printf("data : %d", temp->data);
	prev = temp;
   while(temp)
   {
   //	printf("data : %d", temp->data);
   	if(temp->data <= data)
   	{

   		//bigger data is in first node
   		if(prev == temp)
   		{
   			prev = temp->next;
   			free(temp);
   			temp = prev;
   			*head = prev;
   			continue;

   		}
   		//middle part 
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		continue;
   	}
   	
   	prev = temp;
   	temp = temp->next;

   }
 
   return SUCCESS;


}

int delete_othanbgnum( struct node **head, int data, int data1) 
{

   struct node *temp;
   struct node *prev;
 
	
   temp =*head;

   printf("data : %d", temp->data);
	prev = temp;
   while(temp)
   {
   //	printf("data : %d", temp->data);
   	if((temp->data < data || temp->data > data1))
   	{

   		//bigger data is in first node
   		if(prev == temp)
   		{
   			prev = temp->next;
   			free(temp);
   			temp = prev;
   			*head = prev;
   			continue;

   		}
   		//middle part 
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		continue;
   	}
   	
   	prev = temp;
   	temp = temp->next;

   }
 
   return SUCCESS;
}

int delete_position(struct node **head, int pos)
{
	int flag =1;

	struct node *temp;
   struct node *prev;
   temp =*head;

   if(pos == 1 && temp != NULL)
   {
   	*head = temp->next;
   	free(temp);
   	return SUCCESS;
   }

  	prev = temp;
   while(temp)
   {
     	if(flag == pos)
   	{
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		break;
   	}
   	flag++;
   	prev = temp;
	  	temp = temp->next;
   }
   return SUCCESS;
}

int count_node(struct node **head)
{
	llnode_count=0;
	struct node *temp;
	 temp =*head;

   if(temp == NULL)
   {
   	llnode_count= 0;
   	return SUCCESS;
   }

   while(temp)
   {
     	llnode_count++;
	  	temp = temp->next;
   }
   return SUCCESS;
}

int delete_position_fromend(struct node **head, int pos)
{
	

	struct node *temp;
   struct node *prev;
   temp =*head;

	int flag =1;
	int count=1;

	if(pos > llnode_count)
		return DATA_NOTFOUND;

	flag = llnode_count - pos+1;


   if(flag == 1 && temp != NULL)
   {
   	*head = temp->next;
   	free(temp);
   	return SUCCESS;
   }

  	prev = temp;
   while(temp)
   {
     	if(flag == count)
   	{
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		break;
   	}
   	count++;
   	prev = temp;
	  	temp = temp->next;
   }
   return SUCCESS;
}


int delete_position_fromgptoend(struct node **head, int pos)
{

	int flag = 1;
	struct node *temp;
	struct node *prev;
   temp =*head;
	if(pos > llnode_count)
		return NOT_POSS;

	prev = temp;
   while(temp)
   {

     	if(flag > pos)
   	{
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		continue;
   	}
   	flag++;
   	prev = temp;
	  	temp = temp->next;
   }

   return SUCCESS;

}

int delete_node_bgivenoccrrence(struct node **head, int data)
{

	struct node *temp;
   struct node *prev;
 
	
   temp =*head;
	prev = temp;
   while(temp)
   {
   	if(temp->data == data)
   	{

   		//bigger data is in first node
   		if(prev == temp)
   		{
   			prev = temp->next;
   			free(temp);
   			temp = prev;
   			*head = prev;
   			continue;

   		}
   		//middle part 
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		continue;
   	}
   	
   	prev = temp;
   	temp = temp->next;
   }
   return SUCCESS;

}

int delete_allnode_gpfromend(struct node **head, int pos)
{
	struct node *temp;
   struct node *prev;
   temp =*head;

	int flag =1;
	int count=1;

	if(pos > llnode_count)
		return DATA_NOTFOUND;

	flag = llnode_count - pos+1;


   if(flag == 1 && temp != NULL)
   {
   	*head = temp->next;
   	free(temp);
   	return SUCCESS;
   }

  	prev = temp;
   while(temp)
   {
     	if(flag == count)
   	{
   		prev->next = temp->next;
   		free(temp);
   		temp = prev->next;
   		continue;
   	}
   	count++;
   	prev = temp;
	  	temp = temp->next;
   }
   return SUCCESS;
}

int insert_afternode(struct node **head, int node, int data)
{

	struct node *temp = *head;
	int flag = 1;

	if(temp == NULL || node > llnode_count)
	{
		printf("List empty\n node or position is greater than available list \n");
		return 0;
	}


	while(temp)
	{

		if(flag == node)
		{
			struct node * temp2 = malloc(sizeof(struct node));
			temp2->data = data;
			temp2->next = temp->next;
			temp->next =temp2;
			break;

		}
		temp= temp->next;
		flag++;
	}

	return 0;
}
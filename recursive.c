//F0=0 F1=1, Fn=Fn-1 + Fn-2, calculate the n-th number of the sequence

//use iterative function (calculate by repeating steps multiple times)
int fibonacci(int n)
{
	int first_num=0;//first num
	int second_num=1;//second num
	int next_num;
	
	if(n==1)
	{
		return first_num;
	}
	else if(n==2)
	{
		return second_num;
	}
	
	for(int i=0; i<n-2; ++i) //start from n=3
	{
		next_num = first_num + second_num;
		first_num = second_num;
		second_num = next_num;
	}

	return next_num; //this is the n-th num in sequence
}

//use recursive function
int fibonacci2(int n)
{
	if(n==1) //1-th number is 0
		return 0;

	else if(n==2) //2-th number is 1
		return 1;

	else 
		return fibonacci2(n-1)+fibonacci2(n-2);	
}

//sequence where F0=0, F1=0, F2=1, Fn=Fn-1+Fn-2+Fn-3
//use iterative function
int IterFun(int n)
{
	int first=0;
	int second=0;
	int third=1;
	int next_num;

	if(n==1)
		return first;
	else if(n==2)
		return second;
	else if(n==3)
		return third;
	
	for(int i=0; i<n-3; ++i)
	{
		next_num = first + second + third;
		first = second;
		second = third;
		third = next_num;
	}

	return next_num;
}

//use recursive

int RecFun(int n)
{
	if(n==1) //1-th number is 0
		return 0;

	else if(n==2) //2-th number is 1
		return 0;

	else if(n==3)
		return 1;

	else return RecFun(n-1) + RecFun(n-2) +RecFun(n-3);

}

struct list_el
{
	int val; //the value of current element
	struct list_el * next; // the adress of next element
}

typedef struct list_el *head; //define a pointer head pointing to the first element on the list
	
//iterative
int count_element(list_el *head) //pass the first element on the list to function
{
	int count = 0;
	int sum = 0;
	list_el *current = head; //create a new variable to mark the current element
	
	while(current!=NULL)
	{
		count++;
		sum += current->val;
		current = current->next;
	//if current is the last element, current->next will be NULL
	//so in next iteration current == NULL, loop ends
	}

	return count;
}

//recursive count
int count_element2(list_el *current) //the first call should pass *head as current element
{
	if (current == NULL)
		return 0;

	return count_element2(current->next)+1; //here count num of element in return
}
//number of element = 0, current = NULL, return 0
//from second call current->next is passed to function.
//number of element = 1, next = NULL, return 1+0;
//number of element = 2, first next is not NULL, second next is NULL, return 1+1+0 

//recursive calculate sum
int sum(list_el *current)
{
	if(current==NULL)
		return 0; //sum=0 when number of elements =0
	
	return current->val+sum(curernt->next); //calculate sum her
}
//the first call pass *head as current element
//number of element = 1, next = NULL, return first val+0
//number of elemetn = 2, next = second, return first+second val +0;

//remove an element
//the purpose of this function is to perform an action, modify smth, so no need to return.

//iterative
void remove(list_el **head, int value_to_remove)
//consider that we might need to remove *head, since head is originally a pointer, we need to use double pointer to pass it to function, so that we can modify its orignal value
//for integer, if we need to modify its orginal value, then we use single pointer in function
//here value doesn't need to be modified, so we use it in function without pointer 
//inside the function, head is a double pointer, so we use * when refer to it, current and previous were defined as a single pointer, so we don't need to use * when refer to it
{
	list_el *current = *head;
	list_el *previous; //without initialization, previous == NULL

	while(current!= NULL && current->val != value_to_remove)
		//when current is not the end of list and value is not found yet
	{
		previous = current;
		current = current->next;
		//current moves to next element
	}

	if(current == NULL) //current at the end of list
		printf("Element Not Found\n");

	else if(previous == NULL) //head is the value, means the while loop hasn't be excueted
		*head = current->next; 
	//remove head, next element becomes head, all pointers after will be ajusted to one element ahead
	
	//else, current->val == value_to_remove, element is found
	//before previous next is current, after removing current, it should become current next.
	previous->next = current->next;
	
	free(current);

}

//recurtive
void remove2(list_el **current, int value_to_remove) //pass head as current element)
{

//base case
	if(*current==NULL) //all elments were checked, current->next passed to function = NULL
	{
		printf("Element Not Found\n");
		return;
	}

//element is found
	if((*current)->val == value_to_remove) //check the current element
	{
		list_el *temp = *current;
		*current = (*current)->next;//remove current, change it by current next
		free(temp);//free memeory allcoation of current using temp
		return;
	}

//element is not found	
	remove2(&current->next, value_to_remove); //pass current->next as new current to check
}


//add an element 
//1. at the beginning of the list
//2. at the end of the list
//3. to the list keeping the ordering of the list (assuming that the list is always order(which means the list is sorted in ascending order

//iterative
void add_element(list_el **head, int new_value, int position)
{
	list_el *new_element =(list_el*)malloc(sizeof(list_el));
	new_element->val = new_val;
	if (position == 1) //add to beginning 
	{
		//initialize new_element
		new_element->next = *head; //original head becomes next element after new element
		*head = new_element //new element takes the place of head
	}

	if (position == 2) //add to the end
	{
		//intiialize new_element
		new_element->next = NULL; // new element is the last because next is NULL
		
		if(*head == NULL) //if there's no element on the list
			*head = new_element; //change original head to new element

		list_el *current = *head; //use new variable *current to not change original head
		while(current->next != NULL) // if current is not the last element
		{
			current = current->next; // change current to next element
		}//loop ends when current is the last element

		current->next = new_element; //new element takes the place of current->next
		return;
	}

	if (position ==3) //add to the list with order
	{
		if(*head == NULL || new_value < (*head)->val)
			new_element->next = *head;
			*head = new_element;

		list_el *current = *head;
		while(current!=NULL && current->next->val<new_value)
		{
			current = current->next; //change current to next element
		}//loope ends when new value is less then next value but larger than current value

		new_element->next = current_next;
		current->next = new_element; //new element takes the place of current->next
	}
}

//recursive 
void add2(list_el **current, int new_value, int position) //head passed to function as current
{
	list_el *new_element =(list_el*)malloc(sizeof(list_el));
	new_element->val = new_val;

	if(position==1) // add to beginning
	{
		new_element->next = *current;
		*current = new_element;
	}//no need of recursive call here

	if(position==2) //add to the end
	{
		new_element->next = NULL; //no more element after it
		
		//base case, when *current is empty at the end of list
		if(*current== NULL)
		{
			*current = new_element; //new_element added to the last place
			return;
		}
		//if *current is not the last NULL place, than go to the next
		add2(&current->next, new_value, position);
	}

	if(position==3) //add to the list with order
	{
		//base case, when *current is the last place, or *current > new element
		if(*current == NULL || new_value < (*current)->val)
		{
			new_element->next = *current //current is larger, so it's after new element
			*current = new_element; //new element takes the place of current 
			return;
		}

		add2(&current->next, new_value, position);
	}
}

//search an element and return the pointer to it
//iterative
list_el *search(list_el *current, int target) //a function that returns a pointer to struct list_el
{
	if(current != NULL && current->val != target)
		current = current->next;

	if(current == NULL)
		return NULL; //the element is not found
	
	//else if(current->val == target)
	return current;
}

//recursive
list_el *search_recursive(list_el*current, int target)
{
	//base case: when current is already the last place and element is not found
	if(current == NULL)
		return NULL;

	//target case: return poitner to element
	if(current->val == target) 
		return current;

	return search_recursive(current->next, target)
}

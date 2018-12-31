
#include<iostream>
#include<cassert>
#include<string>

using namespace std;
#define MAXSIZE 26


typedef struct Node
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
	int weight;
	int capcity;
}MHNode,*MHTree;


void FindTwoMinNode(MHTree arr[], int& max_index, int& min_index,int& len)
{
	int temp = 0;
	while(arr[temp] == NULL)
		++temp;
	max_index = temp;

	int cur =temp + 1;
	while(cur < len)
	{
		if((arr[cur] != NULL) && (arr[cur]->weight < arr[max_index]->weight))
			max_index = cur;
		++cur;
	}

	if(max_index != temp)
		min_index = temp;
	else
	{
		++temp;
		while(arr[temp] == NULL)
			++temp;
		min_index = temp;
	}

	cur = temp + 1;
	while(cur < len)
	{
		if((arr[cur] != NULL) && (arr[cur]->weight < arr[min_index]->weight) && (cur != max_index))
			min_index = cur;
		++cur;
	}
}


void InsertMHNode(MHTree& root, MHTree arr[], int len)
{
	int max = 0;
	int min = 0;
	int count = 0;
	MHTree head = NULL;
	while(count < len - 1)
	{
		FindTwoMinNode(arr,max,min,len);
		head = new MHNode;
		head->data   = '#';
		head->weight = (arr[max]->weight) + (arr[min]->weight);
		head->capcity = (arr[max]->capcity) + (arr[min]->capcity);
		head->lchild = arr[max];
		head->rchild = arr[min];
		arr[max] = NULL;
		arr[min] = head;
		++count;
	}
	root = head;
}




void PreOrder(MHTree root)
{
	if(root == NULL)
	{
    	return;
	}
	PreOrder(root->lchild);
	cout<<root->data<<" "<<flush;
	PreOrder(root->rchild);
}


void PrintMHCode(const MHTree root)
{
	MHTree parent = NULL;
	MHTree head   = root;
	while(head->data == '#')
	{
		while(head->data == '#' && head->lchild->capcity != 0)
		{
			cout<<0<<flush;
			parent = head;
			--head->capcity;
			head   = head->lchild;
		}
		if(head->data == '#' && head->rchild->capcity != 0)
		{
			cout<<1<<flush;
			parent = head;
			--head->capcity;
			head   = head->rchild;
		}
	}
	--head->capcity;
	cout<<"  "<<head->data<<endl;
}



int main()
{
	string str;
	MHTree root = NULL;
	MHTree arrptr[MAXSIZE] = {NULL};
	int count[MAXSIZE] = {0};
    cout<<"ÇëÊäÈë×Ö·û´®"<<endl;
	cin>>str;

	for(int i = 0; str[i] != '\0'; ++i)
	{
		++count[str[i] - 'a'];
	}

	int len = 0;
	for(int j = 0; j < 26; ++j)
	{
		if(count[j] != 0)
		{
			arrptr[len] = new MHNode;
			arrptr[len]->data   = (char)('a' + j);
			cout<<arrptr[len]->data<<" "<<count[j]<<endl;
			arrptr[len]->weight = count[j];
			arrptr[len]->capcity = 1;
			arrptr[len]->lchild = NULL;
			arrptr[len]->rchild = NULL;
			++len;
		}
	}

	if(len == 1)
		cout<<"code of ManHaDun is: "<<0<<" or "<<1<<endl;
	else
	{
		InsertMHNode(root,arrptr,len);
		//PreOrder(root);
		cout<<endl<<"¸÷×Ö·ûµÄ¹þ·òÂü±àÂëÈçÏÂ:"<<endl;
		int temp = 0;
		while(temp++ < len)
			PrintMHCode(root);
	}

	return 0;
}


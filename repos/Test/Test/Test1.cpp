/*
#include<iostream>

int main()
{
	
}
*/
#include<iostream>

int main()
{
	
}




/*
Binary Tree
#include<iostream>
#include<string>

struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};

BSTNode* insert(BSTNode*, int);
void printTree(BSTNode*);

int main()
{
	BSTNode* rootPtr = nullptr;
	rootPtr = insert(rootPtr, 15);
	rootPtr = insert(rootPtr, 10);
	rootPtr = insert(rootPtr, 20);
	rootPtr = insert(rootPtr, 25);
	rootPtr = insert(rootPtr, 8);
	rootPtr = insert(rootPtr, 12);
	printTree(rootPtr);
	return 0;
}

BSTNode* insert(BSTNode* root, int num)
{
	if (root == nullptr)
	{
		root = new BSTNode;
		root->data = num;
		root->left = nullptr;
		root->right = nullptr;
		return root;
	}
	else if (root->data < num)
	{
		root->right = insert(root->right, num);
		return root;
	}
	else
	{
		root->left = insert(root->left, num);
		return root;
	}
}

void printTree(BSTNode* root)
{
	if (root == nullptr)
		return;
	std::cout << root->data << std::endl;
	if (root->left != nullptr)
		printTree(root->left);
	if (root->right != nullptr)
		printTree(root->right);
	return;
}
*/



/*
Stack Deletion Algorithm
#include<iostream>

int main()
{
	const int MAX = 10;
	int arr[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* MAXSTACK = &arr[9];
	int* top = MAXSTACK;
	int i = 1;
	char choice;
	while (i != 0)
	{
		i = 0;
		if (top == &arr[-1])
		{
			std::cout << "Underflow.\n";
			for (int i = 0; i < 10; i++)
				std::cout << arr[i] << " ";
			return 0;
		}
		else
		{
			*top = NULL;
			top--;
		}
		std::cout << "Delete another number? ";
		std::cin >> choice;
		if (choice == 'y')
			i = 1;
	}
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";
	return 0;
}*/



/*
Stack Push Algorithm
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int arr[10];
	int* MAX = &arr[9];
	int* top = &arr[-1];
	int newNumber, i = 1;
	char choice;
	for (int i = 0; i < 10; i++)
		arr[i] = 0;
	while (i != 0)
	{
		i = 0;
		cout << "Enter the number: ";
		cin >> newNumber;
		if (top == MAX)
		{
			cout << "Overflow.\n";
			for (int i = 0; i < 10; i++)
				cout << arr[i] << " ";
			return 0;
		}
		else
		{
			top++;
			*top = newNumber;
		}
		cout << "\nAdd another number? ";
		cin >> choice;
		if (choice == 'y')
			i = 1;
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
}
*/



/*
Selection Sort
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

int main(void)
{
	
	vector<int> list = { 12, 59, 69, 66, 7, 2, 58, 27, 68, 99, 100, 22, 14, 5 };
	int ptr;
	for (unsigned int i = 0; i < list.size() - 1; ++i)
	{
		ptr = i;

		for (unsigned int j = i + 1; j < list.size(); ++j)
		{
			if (list[ptr] > list[j])
				ptr = j;
		}
		if (ptr != i)
		{
			list[ptr] = list[i] + list[ptr];
			list[i] = list[ptr] - list[i];
			list[ptr] = list[ptr] - list[i];
		}
	}
	unsigned int q = 0;
	while (q < list.size())
	{
		cout << list[q] << " ";
		q++;
	}
}

*/

/*
	ENHANCED INSERTION SORT

	unsigned int i = 0, p = 1;
	vector<int> list = { 12, 59, 69, 66, 7, 2, 58, 27, 68, 99, 100, 22, 14, 5 };
	auto start = high_resolution_clock::now();
	for (; p < list.size(); ++p)
	{
		int temp = list[p];
		int j = p;
		if (list[p] < list[p - 1])
		{
			if (list[p] < list[0])
			{
				while (j > 0)
				{
					list[j] = std::move(list[j - 1]);
					--j;
				}
				list[0] = std::move(temp);
			}
			else
			{
				int k= p / 2;
				if (list[p] < list[k])
				{
					while ((k - 2) >= 0 && list[k - 2] > list[p])
					{
						k = k - 2;
					}
					if (list[k - 1] < list[p])
					{
						while (j > k)
						{
							list[j] = std::move(list[j - 1]);;
							--j;
						}
						list[k] = std::move(temp);
					}
					else
					{
						while (j > k - 1)
						{
							list[j] = std::move(list[j - 1]);
							--j;
						}
						list[k - 1] = std::move(temp);
					}
				}
				else
				{
					while ((k + 2) <= list.size() && list[k + 2] < list[p])
					{
						k = k + 2;
					}
					if (list[k + 1] > list[p])
					{
						while (j > k + 1)
						{
							list[j] = std::move(list[j - 1]);
							--j;
						}
						list[k + 1] = std::move(temp);
					}
					else
					{
						while (j > k + 2)
						{
							list[j] = std::move(list[j - 1]);
							--j;
						}
						list[k + 2] = std::move(temp);
					}
				}
			}
		}
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	while (i < list.size())
	{
		cout << list[i] << " ";
		i++;
	}
	cout << "\n\n Enhanced Insertion Sort Runtime: " << duration.count() << " ns";*/



/*template <typename Comparable>
void insertionSort(vector<Comparable> &list)
{
	main proigram code
	for (; p < list.size(); ++p)
	{
		int temp = list[p];
		int j = p;
		for (; j > 0 && temp < list[j - 1]; --j)
		{
			list[j] = std::move(list[j - 1]);
		}
		list[j] = std::move(temp);
	}
	
	
	
	int p = 1;
	for (; p < list.size(); ++p)
	{
		Comparable temp = list[p];
		int j = p;
		for (; j > 0 && temp < list[j - 1]; --j)
		{
			list[j] = std::move(list[j - 1]);
		}
		list[j] = std::move(temp);
	}
}*/

/*const int N = 10, NUM = 2;
	int k = 0, data[N] = {32, 45, 98, 2, 101, 56, 89, 78, 24, 100}, loc[NUM], temp[NUM];

	while (k < NUM)
	{
		int i = 0, loop = 0, j = 1;
		while (loop < N)
		{
			if (data[i] < data[i + j])
				{
					i = i + j;
					j = 1;
					loop++;
				}
			else
			{
				j++;
				loop++;
			}
		}
		loc[k] = i;
		temp[k] = data[i];
		data[i] = 0;
		k++;
	}
	int i = 0;
	while (i < NUM)
	{
		data[loc[i]] = temp[i];
		cout << loc[i] << " " << temp[i] << endl;
		i++;
	}*/

	/*int a, b;
	cin >> a >> b;
	cout << "a = " << a << "\n" << "b = " << b << endl;
	cout << "Swapping";
	a = a + b;
	b = a - b;
	a = a - b;
	cout << "a = " << a << "\n" << "b = " << b << endl;*/
#include <iostream>
#include <queue>
#include <stack>

using std::queue;
using std::stack;

struct node
{
    int vertex;
    node* originalNode;
    node* next;
};

void addEdge(node* vertex, node* vertex2);
node* emptyPlace(node* vertex);
void DFS(node* vertex, stack<node*> toVisit, stack<node*> visited);
bool check(stack<node*>, node*);
const unsigned int N = 5;

int main()
{
    node* vertices[N];
    stack<node*> toVisit;
    stack<node*> visited;
    for (int j = 0; j < N; j++)
    {
        vertices[j] = new(node);
        vertices[j]->vertex = j;
        vertices[j]->next = NULL;
        vertices[j]->originalNode = vertices[j];
    }
    addEdge(vertices[0], vertices[3]);
    addEdge(vertices[0], vertices[1]);
    addEdge(vertices[1], vertices[3]);
    addEdge(vertices[1], vertices[2]);
    addEdge(vertices[2], vertices[4]);
    addEdge(vertices[3], vertices[4]);
    DFS(vertices[0], toVisit, visited);
}

void addEdge(node* vertex, node* vertex2)
{
    node* temp;
    temp = emptyPlace(vertex);
    temp->next = new(node);
    temp->next->next = NULL;
    temp->next->originalNode = vertex2;
    temp->next->vertex = vertex2->vertex;
}
node* emptyPlace(node* vertex)
{
    if (vertex->next == NULL)
        return vertex;
    else
        return emptyPlace(vertex->next);
}

void DFS(node* vertex, stack<node*> toVisit, stack<node*> visited)
{
    node* temp = vertex->next;
    if (!check(visited, vertex) && !check(toVisit, vertex))
        toVisit.push(vertex);
    if (!check(visited, vertex))
    {
        visited.push(toVisit.top());
        std::cout << toVisit.top()->vertex << " ";
    }
    toVisit.pop();
    while (temp != NULL)
    {
        if (!check(visited, temp) && !check(toVisit, temp))
            toVisit.push(temp->originalNode);
        temp = temp->next;
    }
    if (toVisit.empty())
        return;
    DFS(toVisit.top(), toVisit, visited);
}

bool check(stack<node*> stac, node* vertexToCheck)
{
    if (stac.empty())
        return false;
    else if (vertexToCheck->vertex == stac.top()->vertex)
        return true;
    node* temp = stac.top();
    stac.pop();
    if (check(stac, vertexToCheck))
    {
        stac.push(temp);
        return true;
    }
    stac.push(temp);
    return false;
}



/*
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{

}
*/



/*
DFS Implementation(SMH) (Revision 1)
#include <iostream>
#include <queue>
#include <stack>

using std::queue;
using std::stack;

struct node
{
    int vertex;
    node* originalNode;
    node* next;
};

void addEdge(node* vertex, node* vertex2);
node* emptyPlace(node* vertex);
void DFS(node* vertex, stack<node*> toVisit, stack<node*> visited);
bool check(stack<node*> , node*);
const unsigned int N = 5;

int main()
{
    node* vertices[N];
    stack<node*> toVisit;
    stack<node*> visited;
    for (int j = 0; j < N; j++)
    {
        vertices[j] = new(node);
        vertices[j]->vertex = j;
        vertices[j]->next = NULL;
        vertices[j]->originalNode = vertices[j];
    }
    addEdge(vertices[0], vertices[3]);
    addEdge(vertices[0], vertices[1]);
    addEdge(vertices[1], vertices[3]);
    addEdge(vertices[1], vertices[2]);
    addEdge(vertices[2], vertices[4]);
    addEdge(vertices[3], vertices[4]);
    DFS(vertices[0], toVisit, visited);
}

void addEdge(node* vertex, node* vertex2)
{
    node* temp;
    temp = emptyPlace(vertex);
    temp->next = new(node);
    temp->next->next = NULL;
    temp->next->originalNode = vertex2;
    temp->next->vertex = vertex2->vertex;
}
node* emptyPlace(node* vertex)
{
    if (vertex->next == NULL)
        return vertex;
    else
        return emptyPlace(vertex->next);
}

 void DFS(node* vertex, stack<node*> toVisit, stack<node*> visited)
{
    node* temp = vertex->next;
    if (!check(visited, vertex) && !check(toVisit, vertex))
        toVisit.push(vertex);
    if (!check(visited, vertex))
    {
        visited.push(toVisit.top());
        std::cout << toVisit.top()->vertex << " ";
    }
    toVisit.pop();
    while (temp != NULL)
    {
        if (!check(visited, temp) && !check(toVisit, temp))
            toVisit.push(temp->originalNode);
        temp = temp->next;
    }
    if (toVisit.empty())
        return;
    DFS(toVisit.top(), toVisit, visited);
}

bool check(stack<node*> stac, node* vertexToCheck)
{
    if (stac.empty())
        return false;
    else if (vertexToCheck->vertex == stac.top()->vertex)
        return true;
    node* temp = stac.top();
    visited.pop();
    if (check(stac, vertexToCheck))
    {
        stac.push(temp);
        return true;
    }
    stac.push(temp);
    return false;
}
*/



/*
BFS (FIXED)
#include <iostream>
#include <queue>
#include <stack>

using std::queue;
using std::stack;

struct node
{
    int vertex;
    node* originalNode;
    node* next;
};

void addEdge(node* vertex, node* vertex2);
node* emptyPlace(node* vertex);
void BFS(node* vertex, queue<node*> toVisit, stack<node*> visited);
bool check(stack<node*> visited, node* vertexToCheck);

const unsigned int N = 6;

int main()
{
    node* vertices[N];
    queue<node*> toVisit;
    stack<node*> visited;
    for (int j = 0; j < N; j++)
    {
        vertices[j] = new(node);
        vertices[j]->vertex = j;
        vertices[j]->next = NULL;
        vertices[j]->originalNode = vertices[j];
    }
    addEdge(vertices[0], vertices[1]);
    addEdge(vertices[0], vertices[2]);
    addEdge(vertices[1], vertices[0]);
    addEdge(vertices[1], vertices[2]);
    addEdge(vertices[1], vertices[3]);
    addEdge(vertices[1], vertices[4]);
    addEdge(vertices[2], vertices[3]);
    addEdge(vertices[3], vertices[2]);
    addEdge(vertices[3], vertices[5]);
    BFS(vertices[0], toVisit, visited);
}

void addEdge(node* vertex, node* vertex2)
{
    node* temp;
    temp = emptyPlace(vertex);
    temp->next = new(node);
    temp->next->next = NULL;
    temp->next->originalNode = vertex2;
    temp->next->vertex = vertex2->vertex;
}
node* emptyPlace(node* vertex)
{
    if (vertex->next == NULL)
        return vertex;
    else
        return emptyPlace(vertex->next);
}

void BFS(node* vertex, queue<node*> toVisit, stack<node*> visited)
{
    node* temp = vertex;
    while (temp != NULL)
    {
        if (!check(visited, temp))
            toVisit.push(temp->originalNode);
        temp = temp->next;
    }
    if (!check(visited, vertex))
    {
        visited.push(toVisit.front());
        std::cout << toVisit.front()->vertex << " ";
    }
    toVisit.pop();
    if (toVisit.empty())
        return;
    BFS(toVisit.front(), toVisit, visited);
}

bool check(stack<node*> visited, node* vertexToCheck)
{
    if (visited.empty())
        return false;
    else if (vertexToCheck->vertex == visited.top()->vertex)
        return true;
    node* temp = visited.top();
    visited.pop();
    if (check(visited, vertexToCheck))
    {
        visited.push(temp);
        return true;
    }
    visited.push(temp);
    return false;
}
*/



/*
Graph Implementation (Adjacency Matrix) (Revision 1)
#include <iostream>

struct node
{
    int vertex;
    node* originalNode;
    node* next;
};
const unsigned int N = 4;
void addEdge(node* vertex, node* vertex2);
node* emptyPlace(node* vertex);

int main()
{
    node* vertices[N];
    for (int j = 0; j < N; j++)
    {
        vertices[j] = new(node);
        vertices[j]->vertex = j;
        vertices[j]->next = NULL;
        vertices[j]->originalNode = NULL;
    }
    addEdge(vertices[0], vertices[1]);
    addEdge(vertices[0], vertices[2]);
    addEdge(vertices[1], vertices[0]);
    addEdge(vertices[1], vertices[2]);
    addEdge(vertices[2], vertices[3]);
    addEdge(vertices[3], vertices[2]);
    for (int i = 0; i < N; i++)
    {
        node* temp = vertices[i];
        while (temp != NULL)
        {
            std::cout << temp->vertex << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
}

void addEdge(node* vertex, node* vertex2)
{
    node* temp;
    temp = emptyPlace(vertex);
    temp->next = new(node);
    temp->next->next = NULL;
    temp->next->originalNode = vertex2;
    temp->next->vertex = vertex2->vertex;
}
node* emptyPlace(node* vertex)
{
    if (vertex->next == NULL)
        return vertex;
    else
        return emptyPlace(vertex->next);
}
*/



/*
Stack using queue
#include <iostream>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::queue;

int main()
{
    int temp1, temp;
    char choice;
    queue<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    while (true)
    {
        cout << "Remove an element from the queue? ";
        cin >> choice;
        stack.front() = stack.front() + stack.back();
        stack.back() = stack.front() - stack.back();
        stack.front() = stack.front() - stack.back();
        temp1 = stack.back();
        stack.pop();
        while (stack.front() != temp1)
        {
            temp = stack.front();
            stack.pop();
            stack.push(temp);
            cout << temp << " ";
        }
        cout << endl;
        if (choice == 'Y' || choice == 'y')
            continue;
        else
            break;
    }
}
*/




/*
Traversal
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int i = 0, LA[4] = { 2, 4, 6, 8 };
    while (i < 4)
    {
        cout << LA[i]  << " ";
        i++;
    }
}

*/



/*
Insertion
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const int MAX = 5;
    int i = MAX - 1, index, number, LA[MAX] = { 2, 4, 6, 8 };
    cout << "Enter the index: ";
    cin >> index;
    cout << "Enter the number: ";
    cin >> number;
    while (i != index)
    {
        LA[i] = LA[i - 1];
        i--;
    }
    LA[i] = number;

    int j = 0;
    while (j < MAX)
    {
        cout << LA[j] << " ";
        j++;
    }
}

*/



/*
Deletion
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const int MAX = 5;
    int index, LA[MAX] = { 1, 4, 2, 8, 3 };
    cout << "Enter the index from which the number is to be deleted: ";
    cin >> index;
    while (index < MAX - 1)
    {
        LA[index] = LA[index + 1];
        index++;
    }
    LA[MAX - 1] = NULL;

    int j = 0;
    while (j < MAX - 1)
    {
        cout << LA[j] << " ";
        j++;
    }
}

*/



/*
Linear Search
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const int MAX = 4;
    bool found = false;
    int i = 0, number, LA[MAX] = { 2, 4, 6, 8 };
    cout << "Enter the number to search: ";
    cin >> number;
    while (i < MAX)
    {
        if (number == LA[i])
        {
            cout << "Found at index " << i << ".\n";
            found = true;
            break;
        }
        else if (i == MAX - 1 && found == false)
            cout << "Not found.\n";
        i++;
    }
}

*/



/*
Duplicate Numbers
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const int MAX = 10;
    bool found = false;
    int start = 0, end = MAX - 1, i = (start + end) / 2, number, occurrences = 0;
    int LA[MAX] = { 2, 5, 5, 5, 6, 6, 8, 9, 9, 9 };
    cout << "Enter the number to search: ";
    cin >> number;
    while (true)
    {
        if (LA[i] == number)
        {
            occurrences++;
            found = true;
            int j = 1;
            if (LA[i - 1] == number)
            {
                while (LA[i - j] == number)
                {
                    occurrences++;
                    j--;
                }
            }
            j = 1;
            if (LA[i + 1] == number)
            {
                while (LA[i + j] == number)
                {
                    occurrences++;
                    j++;
                }
            }
            break;
        }
        else if (start == end)
        {
            found = false;
            break;
        }
        else if (number > LA[i])
        {
            start = i + 1;
            i = (start + end) / 2;
            continue;
        }
        else
        {
            end = i - 1;
            i = (start + end) / 2;
            continue;
        }
    }
    if (found == true)
        cout << "The number " << number << " occurs " << occurrences << " times.\n";
    else
        cout << "Not found.\n";
}

*/



/*
Bubble Sort
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const int MAX = 6;
    int A[MAX] = { 6, 5, 4, 3, 2, 1 }, i = 0, ptr;
    while (i < MAX - 1)
    {
        ptr = 0;
        while (ptr < MAX - i - 1)
        {
            if (A[ptr] > A[ptr + 1])
            {
                A[ptr] = A[ptr] + A[ptr + 1];
                A[ptr + 1] = A[ptr] - A[ptr + 1];
                A[ptr] = A[ptr] - A[ptr + 1];
            }
            ptr++;
        }
        i++;
    }
    i = 0;
    while (i < MAX)
    {
        cout << A[i] << " ";
        i++;
    }
}

*/



/*
Bubble Sort (Recursion)
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void bubblesort(int[], int, int);
int main()
{
    const int MAX = 13;
    int A[MAX] = { 6, 5, 4, 3, 2, 1, 12, 98, 4, 6, 13, 5, 0 }, i = 0;
    bubblesort(A, i, MAX);
    while (i < MAX)
    {
        cout << A[i] << " ";
        i++;
    }
}

void bubblesort(int A[], int i, int MAX)
{
    int ptr = 0;
    while (ptr < MAX - i - 1)
    {
        if (A[ptr] > A[ptr + 1])
        {
            A[ptr] = A[ptr] + A[ptr + 1];
            A[ptr + 1] = A[ptr] - A[ptr + 1];
            A[ptr] = A[ptr] - A[ptr + 1];
        }
        ptr++;
    }
    if (i == MAX - 1)
    {
        return;
    }
    i++;
    bubblesort(A, i, MAX);
    return;
}

*/



/*
Prefix Solver
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int isOperator(char);

int main()
{
    string exp;
    vector<float> stack;
    float temp;
    cout << "Enter the expression: ";
    cin >> exp;
    for (int i = exp.size() - 1, j = 0; i >= 0; --i)
    {
        if (isalpha(exp[i]))
        {
            cout << "Enter the value of " << exp[i] << ":";
            cin >> temp;
            stack.push_back(temp);
        }
        if (int num = isOperator(exp[i]))
        {
            float A = stack[stack.size() - 1];
            float B = stack[stack.size() - 2];
            stack.pop_back();
            stack.pop_back();
            if (num == 42)
                stack.push_back(A * B);
            else if (num == 43)
                stack.push_back(A + B);
            else if (num == 45)
                stack.push_back(A - B);
            else if (num == 47)
                stack.push_back(A / B);
            else if (num == 94)
                stack.push_back(pow(A, B));
        }
    }
    cout << endl << "The solution is: " << stack[0];
}

int isOperator(char c)
{
    if (static_cast<int>(c) == 42)
        return 42;
    if (static_cast<int>(c) == 43)
        return 43;
    if (static_cast<int>(c) == 45)
        return 45;
    if (static_cast<int>(c) == 47)
        return 47;
    if (static_cast<int>(c) == 94)
        return 94;
    else
        return 0;
}
*/



/*
RAT in maze
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int MAX = 4;

bool found(int*, int[][MAX], int[][MAX], int, int, int);
int main()
{
    int maze[MAX][MAX] = {
                            {1, 0, 0, 0},
                            {1, 1, 0, 1},
                            {0, 1, 0, 0},
                            {1, 1, 1, 1}
                         };

    int sol[MAX][MAX] = {
                            {1, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0}
                        };
    if (found(&maze[0][0], maze, sol, MAX, 0, 0))
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "No path found.";
}

bool found(int* rat, int maze[][MAX], int sol[][MAX], int MAX, int optr, int iptr)
{
    if (rat == &maze[MAX - 1][MAX - 1])
    {
        sol[MAX - 1][MAX - 1] = 1;
        return true;
    }
    else
    {
        if (maze[optr][iptr + 1] == 1 && (iptr + 1) < MAX)
        {
            sol[optr][iptr + 1] = 1;
            rat = &maze[optr][iptr + 1];
            if (found(rat, maze, sol, MAX, optr, iptr + 1))
                return true;
        }
        if (maze[optr + 1][iptr] == 1 && (optr + 1) < MAX)
        {
            sol[optr + 1][iptr] = 1;
            rat = &maze[optr + 1][iptr];
            if (found(rat, maze, sol, MAX, optr + 1, iptr))
                return true;
        }
    }
    sol[optr][iptr] = 0;
    return false;
}
*/



/*
N Queen problem
#include<iostream>
using namespace std;
#define N 8
void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
bool isValid(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQueen(int board[N][N], int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if (isValid(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQueen(board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
bool checkSolution()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    if (solveNQueen(board, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
    printBoard(board);
    return true;
}
int main()
{
    checkSolution();
}
*/
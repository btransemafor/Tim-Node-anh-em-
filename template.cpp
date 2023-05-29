/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;


void CreateEmptyTree(TREE &T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
//###INSERT CODE HERE -
void CreateTree(TREE& t)
{
	int n; cin >> n; 
	while (n != -1)
	{
		TNODE* p = CreateTNode(n);
		Insert(t, p); 
		cin >> n; 
	}
}
TNODE* TimNode( TREE & t , int x )
{
	if (t == NULL) return t; 
	else
	{
		if (x == t->key) return t; 
		else if (x < t->key) return TimNode(t->pLeft, x);
		else return  TimNode(t->pRight, x); 
	}
}
void FindSiblings(TREE & t , int  x)
{
	if (t == NULL) {
		cout << "Empty Tree.";
		return;
	}
	else if (x == t->key) {
		cout << x << "is Root.";
		return;
	}
	else if (TimNode(t, x) == NULL) cout << "Not found " << x << ".";
	TNODE* parent = new TNODE;
	TNODE* current = t; 
	// tim nut x 
	while (current && current->key != x)
	{
		parent = current; 
		if (x < current->key) current = current->pLeft;
		else current = current->pRight; 
	}
	if (x < parent->key) {
		if (parent->pRight != NULL && parent->pRight->key != x) {
			cout << x << " and " << parent->pRight->key << " are siblings.";
		}
		else cout << x << " has no siblings."; 
	}
	else if (x > parent->key)
	{
		if ( parent ->pLeft != NULL && parent->pLeft->key != x  )
			cout << parent->pLeft->key << " and " << x << " are siblings.";
		else cout << x << " has no siblings.";
	}
 
}
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	FindSiblings(T, x);

	return 0;
}

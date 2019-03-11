#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

/* Date de intrare:
n = numarul de legaturi tata-fiu
radacina
n-1 linii:
t f
cu semnificatia t este tatal lui f
Se presupune ca fiecare t se afla deja in arbore
*/

class NodArbore
{
private:
	int value;
	NodArbore* children;
	NodArbore* nextFrate;
public:
	NodArbore()
	{

	}
	NodArbore(int value)
	{
		this->value = value;
		children = nullptr;
		nextFrate = nullptr;
	}
	friend class Arbore;
};
class Arbore
{
private:
	NodArbore root;
	ostream& os;
public:

	friend istream& operator >> (istream& is, Arbore &arbore)
	{
		int n, tata, fiu;
		is >> n;
		is >> tata;
		arbore.root = NodArbore(tata);
		for (int i = 0; i < n - 1; i++)
		{
			is >> tata >> fiu;
			arbore.InsertNode(tata, fiu);
		}

		return is;
	}
	friend ostream& operator << (ostream& os, Arbore& arbore)
	{

		NodArbore* root = &arbore.root;
		arbore.PrintTree(os, root);

		return os;
	}
	Arbore& operator +(Arbore& arbore)
	{
		NodArbore* children = this->root.children;
		while (children->nextFrate)
		{
			children = children->nextFrate;
		}
		children->nextFrate = &arbore.root;
		return *this;
	}

	void InsertNode(int tata, int fiu)
	{
		NodArbore* nodTata = SearchNode(tata, &root);
		AddChild(*nodTata, fiu);
	}

	void PrintTree(ostream& os, NodArbore* arbore)
	{
		if (arbore == nullptr)
			return;
		os << "Node: " << (arbore->value);
		PrintChildren(*arbore);

		NodArbore* children = arbore->children;

		while (children)
		{
			PrintTree(os, children);
			children = children->nextFrate;
		}
	}

	void PrintChildren(NodArbore& arbore)
	{
		NodArbore* children = arbore.children;
		if (children == nullptr) {
			os << " has no children \n";
			return;
		}
		os << " has children \n";
		while (children)
		{
			os << children->value << " ";
			children = children->nextFrate;
		}
		os << endl;
	}

	NodArbore* SearchNode(int value, NodArbore* arbore)
	{
		if (!arbore)
			return nullptr;
		if (arbore->value == value)
			return arbore;

		NodArbore* child = arbore->children;
		NodArbore* returnedNode;
		while (child)
		{
			returnedNode = SearchNode(value, child);
			if (returnedNode)
				return returnedNode;
			child = child->nextFrate;
		}
		return NULL;
	}

	void AddChild(NodArbore& tata, int value)
	{
		if (!tata.children)
		{
			tata.children = new NodArbore(value);
			return;
		}
		NodArbore* children = tata.children;
		while (children->nextFrate)
		{
			children = children->nextFrate;
		}
		children->nextFrate = new NodArbore(value);
	}

	void BFS(int value)
	{
		cout << "BFS: ";
		NodArbore* foundNode = SearchNode(value, &root);
		if (foundNode == nullptr)
		{
			os << "Nodul " << value << " nu exista\n";
			return;
		}
		queue<NodArbore*> coada;
		coada.push(foundNode);
		while (!coada.empty())
		{
			NodArbore* nodCurent = coada.front();
			coada.pop();

			os << nodCurent->value << " ";
			NodArbore* children = nodCurent->children;
			while (children)
			{
				coada.push(children);
				children = children->nextFrate;
			}
		}
		os << endl;
	}

	void DFS(int value)
	{
		cout << "DFS: ";
		NodArbore* foundNode = SearchNode(value, &root);
		if (foundNode == nullptr)
		{
			os << "Nodul " << value << " nu exista\n";
			return;
		}
		stack<NodArbore*> stiva;
		stiva.push(foundNode);
		//unordered_set<int> vizitat;
		while (!stiva.empty())
		{
			NodArbore* nodCurent = stiva.top();
			stiva.pop();
			//vizitat.insert(nodCurent->value);
			os << nodCurent->value << " ";
			NodArbore* children = nodCurent->children;
			while (children)
			{
				//if (vizitat.find(children->value) == vizitat.end())
				stiva.push(children);
				children = children->nextFrate;
			}
		}
		os << endl;
	}

	int GetHight()
	{
		queue< pair<NodArbore*, int> > coada;
		coada.push(make_pair(&root, 0));
		int maxHeight = -1;
		while (!coada.empty())
		{
			NodArbore* nodCurent = coada.front().first;
			int currentHight = coada.front().second;
			coada.pop();
			maxHeight = max(maxHeight, currentHight);

			os << nodCurent->value << " ";
			NodArbore* children = nodCurent->children;
			while (children)
			{
				coada.push(make_pair(children, currentHight + 1));
				children = children->nextFrate;
			}
		}
		os << endl;
		return maxHeight;
	}

	void PrintLeafs()
	{
		os << "Frunzele sunt: ";
		queue<NodArbore*> coada;
		coada.push(&root);
		while (!coada.empty())
		{
			NodArbore* nodCurent = coada.front();
			coada.pop();
			if (nodCurent->children == nullptr) {
				os << nodCurent->value << " ";
				continue;
			}
			NodArbore* children = nodCurent->children;
			while (children)
			{
				coada.push(children);
				children = children->nextFrate;
			}
		}
		os << endl;
	}

	Arbore(ostream& out) : os(out)
	{
		os.rdbuf(out.rdbuf());
		root = NodArbore(-1);
	}
	void SetOstream(ostream& out)
	{
		os.rdbuf(out.rdbuf());
	}
};

int main()
{
	ifstream fin("../arbore.in");
	ostream os(cout.rdbuf());
	//ofstream os("arbore.out");
	//os.rdbuf();
	Arbore arbore(os);
	//arbore.AddChild(10, 1);
	arbore.SetOstream(os);
	fin >> arbore;
	os << arbore;

	arbore.BFS(10);
	arbore.DFS(1);
	arbore.PrintLeafs();
	Arbore arbore2(os);
	fin = ifstream("../arbore.in");
	fin >> arbore2;
	//os << arbore2 << "----------------------\n";
	//os << arbore + arbore2;
	return 0;
}

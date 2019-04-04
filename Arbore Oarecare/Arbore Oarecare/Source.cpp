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
class Nod
{
	int value;
};
class Nod_fiu_frate : Nod
{
private:
	Nod_fiu_frate* children;
	Nod_fiu_frate* nextFrate;
public:
	Nod_fiu_frate()
	{

	}
	Nod_fiu_frate(int value)
	{
		this->value = value;
		children = nullptr;
		nextFrate = nullptr;
	}
	friend class AB_oarecare;
};
class Nod_ABC : Nod
{

};

class Arbore
{
	int nr_noduri;
};

class ABC : Arbore
{

};

class AB_oarecare
{
private:
	Nod root;
	ostream& os;
public:

	friend istream& operator >> (istream& is, AB_oarecare &arbore)
	{
		int n, tata, fiu;
		is >> n;
		is >> tata;
		arbore.root = Nod(tata);
		for (int i = 0; i < n - 1; i++)
		{
			is >> tata >> fiu;
			arbore.InsertNode(tata, fiu);
		}

		return is;
	}
	friend ostream& operator << (ostream& os, AB_oarecare& arbore)
	{

		Nod* root = &arbore.root;
		arbore.PrintTree(os, root);

		return os;
	}
	AB_oarecare& operator +(AB_oarecare& arbore)
	{
		Nod* children = this->root.children;
		while (children->nextFrate)
		{
			children = children->nextFrate;
		}
		children->nextFrate = &arbore.root;
		return *this;
	}

	void InsertNode(int tata, int fiu)
	{
		Nod* nodTata = SearchNode(tata, &root);
		AddChild(*nodTata, fiu);
	}

	void PrintTree(ostream& os, Nod* arbore)
	{
		if (arbore == nullptr)
			return;
		os << "Node: " << (arbore->value);
		PrintChildren(*arbore);

		Nod* children = arbore->children;

		while (children)
		{
			PrintTree(os, children);
			children = children->nextFrate;
		}
	}

	void PrintChildren(Nod& arbore)
	{
		Nod* children = arbore.children;
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

	Nod* SearchNode(int value, Nod* arbore)
	{
		if (!arbore)
			return nullptr;
		if (arbore->value == value)
			return arbore;

		Nod* child = arbore->children;
		Nod* returnedNode;
		while (child)
		{
			returnedNode = SearchNode(value, child);
			if (returnedNode)
				return returnedNode;
			child = child->nextFrate;
		}
		return NULL;
	}

	void AddChild(Nod& tata, int value)
	{
		if (!tata.children)
		{
			tata.children = new Nod(value);
			return;
		}
		Nod* children = tata.children;
		while (children->nextFrate)
		{
			children = children->nextFrate;
		}
		children->nextFrate = new Nod(value);
	}

	void BFS(int value)
	{
		cout << "BFS: ";
		Nod* foundNode = SearchNode(value, &root);
		if (foundNode == nullptr)
		{
			os << "Nodul " << value << " nu exista\n";
			return;
		}
		queue<Nod*> coada;
		coada.push(foundNode);
		while (!coada.empty())
		{
			Nod* nodCurent = coada.front();
			coada.pop();

			os << nodCurent->value << " ";
			Nod* children = nodCurent->children;
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
		Nod* foundNode = SearchNode(value, &root);
		if (foundNode == nullptr)
		{
			os << "Nodul " << value << " nu exista\n";
			return;
		}
		stack<Nod*> stiva;
		stiva.push(foundNode);
		//unordered_set<int> vizitat;
		while (!stiva.empty())
		{
			Nod* nodCurent = stiva.top();
			stiva.pop();
			//vizitat.insert(nodCurent->value);
			os << nodCurent->value << " ";
			Nod_fiu_frate* children = nodCurent->children;
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
		queue< pair<Nod*, int> > coada;
		coada.push(make_pair(&root, 0));
		int maxHeight = -1;
		while (!coada.empty())
		{
			Nod* nodCurent = coada.front().first;
			int currentHight = coada.front().second;
			coada.pop();
			maxHeight = max(maxHeight, currentHight);

			os << nodCurent->value << " ";
			Nod* children = nodCurent->children;
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
		queue<Nod*> coada;
		coada.push(&root);
		while (!coada.empty())
		{
			Nod* nodCurent = coada.front();
			coada.pop();
			if (nodCurent->children == nullptr) {
				os << nodCurent->value << " ";
				continue;
			}
			Nod* children = nodCurent->children;
			while (children)
			{
				coada.push(children);
				children = children->nextFrate;
			}
		}
		os << endl;
	}

	AB_oarecare(ostream& out) : os(out)
	{
		os.rdbuf(out.rdbuf());
		root = Nod(-1);
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
	AB_oarecare arbore(os);
	//arbore.AddChild(10, 1);
	arbore.SetOstream(os);
	fin >> arbore;
	os << arbore;

	arbore.BFS(10);
	arbore.DFS(1);
	arbore.PrintLeafs();
	AB_oarecare arbore2(os);
	fin = ifstream("../arbore.in");
	fin >> arbore2;
	//os << arbore2 << "----------------------\n";
	//os << arbore + arbore2;
	return 0;
}

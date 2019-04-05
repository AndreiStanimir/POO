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
protected:
	int value;
public:
	Nod(int value)
	{
		this->value = value;
	}
	Nod(const Nod& nod)
	{
		value = nod.value;
	}
	Nod& operator =(const Nod& nod)
	{
		value = nod.value;
		return *this;
	}

	friend istream& operator>> (istream& is, Nod& nod)
	{
		is >> nod.value;
		return is;
	}
	friend ostream& operator<< (ostream& os, Nod& nod)
	{
		os << nod.value<<endl;
		return os;
	}
	~Nod()
	{
	}
};
class Nod_fiu_frate : Nod
{
private:
	int nrCopii;
	Nod_fiu_frate* children;
	Nod_fiu_frate* nextFrate;
public:
	Nod_fiu_frate() : Nod(0)
	{
		nrCopii = 0;
		children = nullptr;
		nextFrate = nullptr;
	}
	Nod_fiu_frate(int val) : Nod(val)
	{
		nrCopii = 0;
		children = nullptr;
		nextFrate = nullptr;
	}

	Nod_fiu_frate(const Nod_fiu_frate& nod) : Nod(nod.value)
	{
		nrCopii = nod.nrCopii;
		children = nod.children;
		nextFrate = nod.nextFrate;
	}
	Nod_fiu_frate& operator =(const Nod_fiu_frate& nod)
	{
		value = nod.value;
		nrCopii = nod.nrCopii;
		children = nod.children;
		nextFrate = nod.nextFrate;
		return *this;
	}

	friend istream& operator>> (istream& is, Nod_fiu_frate& nod)
	{
		is >> nod.value;
		return is;
	}
	friend ostream& operator<< (ostream& os, Nod_fiu_frate& nod)
	{
		os << nod.value << endl;
		return os;
	}

	~Nod_fiu_frate()
	{
	}

	friend class AB_oarecare;
};
class Nod_ABC : Nod
{
	Nod_ABC* st;
	Nod_ABC* dr;

public:
	Nod_ABC(int val=0,Nod_ABC* stanga=nullptr, Nod_ABC* dreapta=nullptr): Nod(val)
	{
		value = val;
		st = stanga;
		dr = dreapta;
	}
};

class Arbore
{
protected:
	int nr_noduri;
	Nod_fiu_frate* root;
	Arbore(int nrNoduri=0,int rootValue=0)
	{
		nr_noduri = nrNoduri;
		root = new Nod_fiu_frate(rootValue);
	}
};

class ABC : Arbore
{
	
};

class AB_oarecare
{
private:
	Nod_fiu_frate root;
	ostream& os;
public:

	friend istream& operator >> (istream& is, AB_oarecare &arbore)
	{
		int n, tata, fiu;
		is >> n;
		is >> tata;
		arbore.root = Nod_fiu_frate(tata);
		for (int i = 0; i < n - 1; i++)
		{
			is >> tata >> fiu;
			arbore.InsertNode(tata, fiu);
		}

		return is;
	}
	friend ostream& operator << (ostream& os, AB_oarecare& arbore)
	{

		Nod_fiu_frate* root = &arbore.root;
		arbore.PrintTree(os, root);

		return os;
	}
	AB_oarecare& operator +(AB_oarecare& arbore)
	{
		Nod_fiu_frate* children = this->root.children;
		while (children->nextFrate)
		{
			children = children->nextFrate;
		}
		children->nextFrate = &arbore.root;
		return *this;
	}

	void InsertNode(int tata, int fiu)
	{
		Nod_fiu_frate* nodTata = SearchNode(tata, &root);
		AddChild(*nodTata, fiu);
	}

	void PrintTree(ostream& os, Nod_fiu_frate* arbore)
	{
		if (arbore == nullptr)
			return;
		os << "Node: " << (arbore->value);
		PrintChildren(*arbore);

		Nod_fiu_frate* children = arbore->children;

		while (children)
		{
			PrintTree(os, children);
			children = children->nextFrate;
		}
	}

	void PrintChildren(Nod_fiu_frate& arbore)
	{
		Nod_fiu_frate* children = arbore.children;
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

	Nod_fiu_frate* SearchNode(int value, Nod_fiu_frate* arbore)
	{
		if (!arbore)
			return nullptr;
		if (arbore->value == value)
			return arbore;

		Nod_fiu_frate* child = arbore->children;
		Nod_fiu_frate* returnedNode;
		while (child)
		{
			returnedNode = SearchNode(value, child);
			if (returnedNode)
				return returnedNode;
			child = child->nextFrate;
		}
		return NULL;
	}

	void AddChild(Nod_fiu_frate& tata, int value)
	{
		if (!tata.children)
		{
			tata.children = new Nod_fiu_frate(value);
			return;
		}
		Nod_fiu_frate* children = tata.children;
		while (children->nextFrate)
		{
			children = children->nextFrate;
		}
		children->nextFrate = new Nod_fiu_frate(value);
	}

	void BFS(int value)
	{
		cout << "BFS: ";
		Nod_fiu_frate* foundNode = SearchNode(value, &root);
		if (foundNode == nullptr)
		{
			os << "Nodul " << value << " nu exista\n";
			return;
		}
		queue<Nod_fiu_frate*> coada;
		coada.push(foundNode);
		while (!coada.empty())
		{
			Nod_fiu_frate* nodCurent = coada.front();
			coada.pop();

			os << nodCurent->value << " ";
			Nod_fiu_frate* children = nodCurent->children;
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
		Nod_fiu_frate* foundNode = SearchNode(value, &root);
		if (foundNode == nullptr)
		{
			os << "Nodul " << value << " nu exista\n";
			return;
		}
		stack<Nod_fiu_frate*> stiva;
		stiva.push(foundNode);
		//unordered_set<int> vizitat;
		while (!stiva.empty())
		{
			Nod_fiu_frate* nodCurent = stiva.top();
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
		queue< pair<Nod_fiu_frate*, int> > coada;
		coada.push(make_pair(&root, 0));
		int maxHeight = -1;
		while (!coada.empty())
		{
			Nod_fiu_frate* nodCurent = coada.front().first;
			int currentHight = coada.front().second;
			coada.pop();
			maxHeight = max(maxHeight, currentHight);

			os << nodCurent->value << " ";
			Nod_fiu_frate* children = nodCurent->children;
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
		queue<Nod_fiu_frate*> coada;
		coada.push(&root);
		while (!coada.empty())
		{
			Nod_fiu_frate* nodCurent = coada.front();
			coada.pop();
			if (nodCurent->children == nullptr) {
				os << nodCurent->value << " ";
				continue;
			}
			Nod_fiu_frate* children = nodCurent->children;
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
		root =*new Nod_fiu_frate(-1);
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

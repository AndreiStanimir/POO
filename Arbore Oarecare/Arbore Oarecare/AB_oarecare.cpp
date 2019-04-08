#include "AB_oarecare.h"

istream& operator >> (istream& is, AB_oarecare &arbore)
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
ostream& operator << (ostream& os, AB_oarecare& arbore)
{

	Nod_fiu_frate* root = &arbore.root;
	arbore.PrintTree(os, root);

	return os;
}
AB_oarecare& AB_oarecare::operator +(AB_oarecare& arbore)
{
	Nod_fiu_frate* children = this->root.children;
	while (children->nextFrate)
	{
		children = children->nextFrate;
	}
	children->nextFrate = &arbore.root;
	return *this;
}

AB_oarecare & AB_oarecare::operator=(AB_oarecare & arbore)
{
	CopyTree(&this->root , &arbore.root);
	return *this;
}

void AB_oarecare::CopyTree(Nod_fiu_frate* arbore1, Nod_fiu_frate* arbore2)
{
	arbore1 = new Nod_fiu_frate(*arbore2);
	Nod_fiu_frate* head2 = arbore2->children;
	if (head2 == NULL) {
		arbore1->children = NULL;
		return;
	}
	else {
		arbore1->children = new Nod_fiu_frate(head2->value);
	}
	Nod_fiu_frate* head1 = arbore1->children;
	head2 = head2->nextFrate;
	while (head2)
	{
		head1->nextFrate = new Nod_fiu_frate(head2->value);
		CopyTree(head1, head2);
		head1 = head1->nextFrate;
		head2 = head2->nextFrate;
	}
}

void AB_oarecare::InsertNode(int tata, int fiu)
{
	Nod_fiu_frate* nodTata = SearchNode(tata, &root);
	AddChild(*nodTata, fiu);
	nr_noduri++;
}

void AB_oarecare::PrintTree(ostream& os, Nod_fiu_frate* arbore)
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

void AB_oarecare::PrintChildren(Nod_fiu_frate& arbore)
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

Nod_fiu_frate* AB_oarecare::SearchNode(int value, Nod_fiu_frate* arbore)
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

void AB_oarecare::AddChild(Nod_fiu_frate& tata, int value)
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

void AB_oarecare::BFS(int value)
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

void AB_oarecare::DFS(int value)
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

int AB_oarecare::GetHight()
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

void AB_oarecare::PrintLeafs()
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

AB_oarecare::AB_oarecare(ostream& out) : os(out)
{
	os.rdbuf(out.rdbuf());
	root = *new Nod_fiu_frate(-1);
}
void AB_oarecare::SetOstream(ostream& out)
{
	os.rdbuf(out.rdbuf());
}

void AB_oarecare::Afisare()
{
	PrintTree(os, &root);
}

void AB_oarecare::DeleteTree(Nod_fiu_frate* root)
{
	if (!root)
		return;
	Nod_fiu_frate* head = root->children;
	while (head)
	{
		DeleteTree(head);
		head = head->nextFrate;

	}

	delete root;
}
AB_oarecare::~AB_oarecare()
{
	DeleteTree(&root);
}

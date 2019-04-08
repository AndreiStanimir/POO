#include "ABC.h"


ArboreDeCautare::ArboreDeCautare(int value)
{
	root = new Nod_ABC(value);
}

ArboreDeCautare::ArboreDeCautare(const ArboreDeCautare & arbore)
{
	CopyTree(root, arbore.root);
}
void ArboreDeCautare::CopyTree(Nod_ABC* root1, Nod_ABC* root2)
{
	if (!root2)
	{
		*root1 = Nod_ABC(*root2);
	}
	root1 = new Nod_ABC(*root2);
	CopyTree(root1->stanga, root2->stanga);
	CopyTree(root1->dreapta, root2->dreapta);
}
void ArboreDeCautare::Insert(int value)
{
	InsertUtility(value, root);
}

void ArboreDeCautare::InsertUtility(int value, Nod_ABC* head)
{
	if (value<head->value) {
		if (head->stanga == nullptr)
			head->stanga = new Nod_ABC(+
				value);
		else
			InsertUtility(value, head->stanga);
	}
	if (value>head->value)
	{
		if (head->dreapta == nullptr)
			head->dreapta = new Nod_ABC(value);
		else
			InsertUtility(value, head->dreapta);
	}
}

Nod_ABC* ArboreDeCautare::Search(int value)
{
	return SearchUtility(value, root);
}
Nod_ABC* ArboreDeCautare::SearchUtility(int value, Nod_ABC* head)
{
	if (head == nullptr)
		return nullptr;
	if (head->value == value)
		return head;
	if (head->value > value) {
		return SearchUtility(value, head->stanga);
	}
	if (head->value < value)
	{
		return SearchUtility(value, head->dreapta);
	}
}
Nod_ABC* ArboreDeCautare::SearchParent(int value, Nod_ABC* head)
{
	if (head == nullptr)
		return nullptr;
	if (head->stanga->value == value)
		return head;
	if (head->dreapta->value == value)
		return head;
	if (head->value < value) {
		return SearchParent(value, head->stanga);
	}
	if (head->value > value)
	{
		return SearchParent(value, head->dreapta);
	}
}
int ArboreDeCautare::FindMax(Nod_ABC *root)
{
	Nod_ABC* head = root;
	while (head->dreapta)
	{
		head = head->dreapta;
	}
	return head->value;
}

void ArboreDeCautare::Delete(int value)
{
	if (root == nullptr)
		return; 
	DeleteUtility(value, root);
}
Nod_ABC* ArboreDeCautare::DeleteUtility(int value, Nod_ABC* head)
{
	if (head->value > value)
		head->stanga = DeleteUtility(value, head->stanga);
	else if (head->value < value)
		head->dreapta = DeleteUtility(value, head->dreapta);
	else
	{
		if (head->stanga == nullptr)
		{
			Nod_ABC* temp = head->dreapta;
			delete head;
			return temp;
		}
		else if (head->dreapta == nullptr)
		{
			Nod_ABC* temp = head->stanga;
			delete head;
			return temp;
		}
		Nod_ABC* temp = Search(FindMax(head->stanga));

		head->value = temp->value;
		head->stanga = DeleteUtility(temp->value, head->stanga	);
	}
	return head;
}
void ArboreDeCautare::StergeNod(Nod_ABC* &tata, Nod_ABC* &nod)
{
	if (tata->stanga == nod)
		tata->stanga = nullptr;
	else
		tata->dreapta = nullptr;
}

void ArboreDeCautare::DestroyTree(Nod_ABC* nod)
{
	if (nod != nullptr)
	{
		DestroyTree(nod->stanga);
		DestroyTree(nod->dreapta);
		delete nod;
	}
}

void ArboreDeCautare::Afisare()
{
	cout << "RSD:\n";
	RSD(root);
	cout << "SRD:\n";
	SRD(root);
	cout << "SDR:\n";
	SDR(root);
}

void ArboreDeCautare::RSD(Nod_ABC* root)
{
	if (root == NULL)
		return;
	cout << root->value << " ";
	RSD(root->stanga);
	RSD(root->dreapta);
}
void ArboreDeCautare::SRD(Nod_ABC* root)
{
	if (root == NULL)
		return;
	SRD(root->stanga);
	cout << root->value << " ";
	SRD(root->dreapta);
}
void ArboreDeCautare::SDR(Nod_ABC* root)
{
	if (root == NULL)
		return;
	SDR(root->stanga);
	SDR(root->dreapta);
	cout << root->value << " ";
}


ArboreDeCautare::~ArboreDeCautare()
{
	DestroyTree(root);
}
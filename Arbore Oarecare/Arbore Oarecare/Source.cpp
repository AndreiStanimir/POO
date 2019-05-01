#include <vector>
#include <fstream>
#include <set>

#include <algorithm>
#include <unordered_set>

#include "AB_oarecare.h"
#include "ABC.h"
#include "Source.h"

using namespace std;

/* Date de intrare:
n = numarul de legaturi tata-fiu
radacina
n-1 linii:
t f
cu semnificatia t este tatal lui f
Se presupune ca fiecare t se afla deja in arbore
*/

int main()
{
	//DemoArboreOarecare();
	//DemoArboreBinarDeCautare();
	DemoFunctieVirtuala();
	//os << arbore2 << "----------------------\n";
	//os << arbore + arbore2;
	return 0;
}

void DemoArboreOarecare()
{
	ifstream fin("../arbore.in");
	ostream os(cout.rdbuf());
	//ofstream os("arbore.out");
	AB_oarecare arbore(os);
	//arbore.AddChild(10, 1);
	arbore.SetOstream(os);
	fin >> arbore;
	os << arbore;

	arbore.BFS(10);
	arbore.DFS(1);
	arbore.PrintLeafs();
	AB_oarecare arbore2; 
	arbore2=arbore;
	//fin = ifstream("../arbore.in");
	//fin >> arbore2;
	cout << arbore2 << endl;
	//arbore = arbore2;
}
void DemoArboreBinarDeCautare()
{
	ifstream fin("ABC.txt");
	ostream os(cout.rdbuf());
	//ofstream os("arbore.out");
	//os.rdbuf();
	ArboreDeCautare abc;
	fin >> abc;
	os << abc;
	//arbore.SetOstream(os);

 }
void DemoFunctieVirtuala()
{
	ifstream fin("../arbore.in");
	ostream os(cout.rdbuf());
	AB_oarecare arbore_oarecare(os);
	//arbore.AddChild(10, 1);
	arbore_oarecare.SetOstream(os);
	fin >> arbore_oarecare;
	os << arbore_oarecare;
	
	ifstream fin2("ABC.txt");
	ArboreDeCautare abc;
	fin2 >> abc;
	os << abc;

	Arbore* arbore = &arbore_oarecare;
	arbore->Afisare();

	arbore = &abc;
	arbore->Afisare();
}
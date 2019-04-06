#include <vector>
#include <fstream>
#include <set>

#include <algorithm>
#include <unordered_set>

#include "AB_oarecare.h"
#include "ABC.h"

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

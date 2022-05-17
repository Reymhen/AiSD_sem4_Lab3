#include <iostream>
#include"BellmanFord.h"
using namespace std;
int main() {
	Route listRoute;
	List<string> helpList;
	parser(listRoute, helpList);

	cout << "We will find the best price flight from St. Petersburg to Vladivostok\n";
	cout <<"Optimal price: " << cheapFlight("St.Petersburg", "Vladivostok", listRoute, helpList);
}
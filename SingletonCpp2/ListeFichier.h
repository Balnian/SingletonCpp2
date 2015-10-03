#pragma once

#include <string>
#include "NodeFichier.h"

using namespace std;

class ListeFichier
{
	weak_ptr<NodeFichier> First;
	weak_ptr<NodeFichier> Last;

	shared_ptr<NodeFichier> AddNode(string path);
	 

public:
	ListeFichier();
	~ListeFichier();



	shared_ptr<NodeFichier> getResource(string path);


};


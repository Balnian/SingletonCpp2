#include "ListeFichier.h"


ListeFichier::ListeFichier() :First(), Last()
{
}


ListeFichier::~ListeFichier()
{
}

shared_ptr<NodeFichier> ListeFichier::AddNode(string path)
{
	shared_ptr<NodeFichier> carry = make_shared<NodeFichier>(path);
	if (First.expired() && Last.expired())
		First = Last = carry;
	return carry;

}

shared_ptr<NodeFichier> ListeFichier::getResource(string path)
{
	weak_ptr<NodeFichier> carry = First;
	while (!(carry = carry.lock()->getNext()).expired())
	{
		if (carry.lock()->getPath() == path)
			return shared_ptr<NodeFichier>(carry);
	}
	return AddNode(path);

}

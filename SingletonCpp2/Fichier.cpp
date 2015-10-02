#include "Fichier.h"
#include <iterator>

int Fichier::count = 0;


Fichier::Fichier(string path)
{
   /*pair<map<string,unsigned int>::iterator,bool> find = instance.emplace(path, 1);
   if (!find.second)
      find.first->second++;*/
   this->path = path;
   file.open(path);
}


Fichier::~Fichier()
{

   if (file.is_open())
   {
      file.close();
   }
}

weak_ptr<Fichier> Fichier::getNext()
{
   return Next;
}

weak_ptr<Fichier> Fichier::getPrevious()
{
   return Previous;
}

void Fichier::setNext(weak_ptr<Fichier> ptr)
{
   Next = ptr;
}

void Fichier::setPrevious(weak_ptr<Fichier> ptr)
{
   Previous = ptr;
}

string Fichier::getPath()
{
   return path;
}

void Fichier::write(string str)
{
   try
   {
      file << str;
   }
   catch (exception e)
   {
      throw e;
   }
   
}

string Fichier::read()
{
   try
   {
      char c;
     
      file.read(&c, 1);
      
      return ""+c;
   }
   catch (exception e)
   {
      throw e;
   }
   
}

void Fichier::writeline(string str)
{
   try
   {
      file << str << endl;
   }
   catch (exception e)
   {
      throw e;
   }
}

string Fichier::readline()
{
   try
   {
      string str;
      getline(file, str);
      return str;
   }
   catch (exception e)
   {
      throw e;
   }

}

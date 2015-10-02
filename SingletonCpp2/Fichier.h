#pragma once
#include <fstream>
#include <string>
#include <memory>
#include <map>

using namespace std;

class Fichier
{
   string path;
   fstream file;
   static int count;

   weak_ptr<Fichier> Previous;
   weak_ptr<Fichier> Next;
   weak_ptr<Fichier> First;
   weak_ptr<Fichier> Last;

   //map<string, unsigned int> instance;

public:
   Fichier(string path);
   ~Fichier();

   weak_ptr<Fichier> getNext();
   weak_ptr<Fichier> getPrevious();

   void setNext(weak_ptr<Fichier>);
   void setPrevious(weak_ptr<Fichier>);

   string getPath();
   static int instanceCount();

   void write(string str);
   string read();

   void writeline(string str);
   string readline();
   


};


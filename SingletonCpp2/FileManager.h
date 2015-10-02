#pragma once
#include <string>
#include <memory>
#include <map>

using namespace std;



class FileManager
{
   map<string, shared_ptr<fstream>> Instances;
   FileManager();

   FileManager & operator = (const FileManager & mgr)
   {
      return FileManager::getInstance();
   }

public:

   ~FileManager();

   static FileManager& getInstance()
   {
      static FileManager fmngr;
      return fmngr;
   }

   shared_ptr<fstream> open()

   

};


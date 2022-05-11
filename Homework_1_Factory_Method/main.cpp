#include <iostream>
#include <string>
#include <memory>
using namespace std;

#include "src/DirContainer.hpp"
#include "src/FilesInfoReport/FilesInfoReportCreator.hpp"

void getReport(const list<File*> &Files, FilesInfoReportCreator *report_creator) 
{
   const string REPORT_FILENAME = "report";
   report_creator->createReport(Files, REPORT_FILENAME);
}

int main()
{  
   string DIR_PATH = "testDir";
   unique_ptr<DirContainer> container(new DirContainer());
   try 
   {
      container->readFilesFromFolder(DIR_PATH);
      unique_ptr<FilesInfoReportCreator> report_creator_csv(new FilesInfoReportCreatorCsv());
      getReport(container->getFiles(), report_creator_csv.get());

      unique_ptr<FilesInfoReportCreator> report_creator_txt(new FilesInfoReportCreatorTxt());
      getReport(container->getFiles(), report_creator_txt.get());
   }
   catch (const runtime_error& errorInReadingWritingFiles)
   {
      cerr << errorInReadingWritingFiles.what() << endl;
      cerr << "Fail to read dir and write it files info" << endl;
   }
   return 0;
}

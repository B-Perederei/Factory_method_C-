#ifndef FILESINFOREPORT_HPP
#define FILESINFOREPORT_HPP

#include <fstream>
#include <string>
#include <list>
#include "../File.hpp"
class File;
using namespace std;

class IFilesInfoReport 
{
    public:
        virtual void writeFilesInfo(const list<File*> &Files, string report_filename) = 0;
        virtual ~IFilesInfoReport() = default;
};

class FilesInfoReportTxt : public IFilesInfoReport
{
    public: 
        void writeFilesInfo(const list<File*> &Files, string report_filename);
};

class FilesInfoReportCsv : public IFilesInfoReport 
{
    public: 
        void writeFilesInfo(const list<File*> &Files, string report_filename);
};

#endif
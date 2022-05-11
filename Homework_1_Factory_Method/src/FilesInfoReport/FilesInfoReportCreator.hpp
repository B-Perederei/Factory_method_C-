#ifndef FILESINFOREPORTCREATOR_HPP
#define FILESINFOREPORTCREATOR_HPP
#include <string>
#include <list>
#include <memory>

#include "FilesInfoReport.hpp"
#include "../File.hpp"
class File;

class FilesInfoReportCreator 
{
    public:
        void createReport(const list<File*> &Files, string report_filename) 
        {
            // Calling factoryMethod to create appropriet FilesInfoReport object
            unique_ptr<IFilesInfoReport> report(this->factoryMethod());
            report->writeFilesInfo(Files, report_filename);
        };
        // Our factory method 
        virtual IFilesInfoReport* factoryMethod() = 0;
        virtual ~FilesInfoReportCreator() = default;
};

class FilesInfoReportCreatorTxt : public FilesInfoReportCreator 
{
    IFilesInfoReport* factoryMethod()
    {
        return new FilesInfoReportTxt();
    }
};

class FilesInfoReportCreatorCsv : public FilesInfoReportCreator 
{
    IFilesInfoReport* factoryMethod()
    {
        return new FilesInfoReportCsv();
    }
};

#endif
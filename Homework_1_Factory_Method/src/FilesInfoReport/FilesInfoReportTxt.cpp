#include <iostream>
#include <fstream>

#include "FilesInfoReport.hpp"

void FilesInfoReportTxt::writeFilesInfo(const list<File*> &Files, string report_filename) 
{
    // Probably in this part exceptions are not handaled properly
    std::ofstream reportfile;
    reportfile.open(report_filename + ".txt");
    reportfile << "Name size_in_bytes last_write_UNIX_timestamp number_of_hard_links" << std::endl;
    for(const auto &file : Files) 
    {
        reportfile << file->name << " ";
        reportfile << file->size << " ";
        reportfile << file->last_write_time << " ";
        reportfile << file->hard_link_count << std::endl;
    }
    reportfile.close();
}
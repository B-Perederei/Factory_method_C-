#include <iostream>
#include <filesystem>
#include <chrono>

#include "DirContainer.hpp"

void DirContainer::readFilesFromFolder(string filepath)
{
    int length_filepath = filepath.length();
    for (const auto &entry : filesystem::directory_iterator(filepath))
    {
        unique_ptr<File> file (new File());
        // File* file = new File();
        file->name = ((entry.path()).filename()).string();
        file->size = entry.file_size();
        file->last_write_time = file->to_time_t(entry.last_write_time());
        file->hard_link_count = entry.hard_link_count();
        try
        {
           Files.push_back(std::move(file));
        }
        catch (const runtime_error& errorInAddingToList)
        {
            cerr << errorInAddingToList.what() << endl;
            cerr << "Can't add file " << file->name << "to container" << endl;
        }
    }
}

const std::list<File*> DirContainer::getFiles() 
{
    // For future we need to give access to function to read files in containers
    // For that we get raw pointers from smart ones
    std::list<File*> files_raw_pointers;
    std::list<std::unique_ptr<File>>::iterator it;
    for (it = Files.begin(); it != Files.end(); ++it)
    {
        files_raw_pointers.push_back(it->get());
    }
    return files_raw_pointers;
};



#ifndef DIRCONTAINER_HPP
#define DIRCONTAINER_HPP

#include <memory>
#include <list>
#include "File.hpp"
class File;

class DirContainer
{
	public:
		const std::list<File*> getFiles();
		void readFilesFromFolder(string filepath);
		void deleteFilesFromContainer();
	private:
		std::list<std::unique_ptr<File>> Files;
};

#endif
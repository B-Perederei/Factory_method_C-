#ifndef FILE_HPP
#define FILE_HPP
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

class File
{
	public:
		string name;
		long size;
		time_t last_write_time;
		int hard_link_count;
		
		// Function for transforming file_time or other type of time to t_time (C++17 or higher)
		template <typename TP>
		static std::time_t to_time_t(TP tp)
		{
    		using namespace std::chrono;
    		auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
        	  + system_clock::now());
    		return system_clock::to_time_t(sctp);
		}  
		// Converting file_time type of last_write_time to t_time (C++20 only) 
        // system_clock::to_time_t(file_clock::to_sys(last_write_time))
        // It's more efficient, but is accesable only in newer versions of C++

};

#endif




#include "DataStruct.h"

#include <iostream>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace boost::interprocess;


int main(int argc, const char * argv[]) {
    
    // in case the shared memory named shared_memory already exists
    
    shared_memory_object::remove("shared_memory");
    shared_memory_object shmObj (create_only, "shared_memory", read_write);
    shmObj.truncate(sizeof(MyData)); // size of shared memory
    
    MyData myData = {440, 0.5, 24.1};
    mapped_region region(shmObj, read_write); // map to this process
    std::memcpy(region.get_address(), &myData, region.get_size());

    std::string str;
    std::cout << "type somthing to exit" << std::endl;
    std::cin >> str;
    shared_memory_object::remove("shared_memory");
    return 0;
}

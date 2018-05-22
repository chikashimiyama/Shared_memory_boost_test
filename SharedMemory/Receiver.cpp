
#include "DataStruct.h"

#include <iostream>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace boost::interprocess;

int main(int argc, const char * argv[]) {
    
    // in case the shared memory named shared_memory already exists
    
    shared_memory_object shmObj (open_only, "shared_memory", read_only);
    
    MyData myData;
    mapped_region region(shmObj, read_only); // map to this process
    std::memcpy(&myData, region.get_address(), region.get_size());
    
    
    std::cout << "freq:" << myData.freq << std::endl;
    std::cout << "amp:" << myData.amp << std::endl;
    std::cout << "mod:" << myData.modulation << std::endl;

    return 0;
}

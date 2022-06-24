#include <iostream>
#include <tbb/tbb.h>

int main(){
    tbb::parallel_invoke(
        [](){ std::cout<<"Hello "<<std::endl; },
        [](){ std::cout<<"TBB!"<<std::endl; }
        printf("one changed")
    );
    return 0;
}
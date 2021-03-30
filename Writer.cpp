#include "Writer.h"

#include <iostream>

Writer::Writer()
{

}

void Writer::writeMessageOnCout(const std::string &mess)
{
    std::lock_guard<std::mutex> lock (_mutex);

    std::cout << mess << std::endl;
}

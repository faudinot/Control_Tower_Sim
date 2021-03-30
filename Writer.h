#ifndef WRITER_H
#define WRITER_H

#include <mutex>
#include <string>


class Writer
{
public:
    Writer();

    void writeMessageOnCout(const std::string& mess);

private:
    std::mutex _mutex;
};

#endif // WRITER_H

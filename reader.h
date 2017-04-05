#ifndef READER_H
#define READER_H

#include<vector>
#include<set>

#include"data.h"

class Reader
{
public:
    Reader();
    ~Reader();
    virtual std::vector<Data> Read()=0;
    virtual std::set<std::string> GetSet()=0;
};

#endif // READER_H

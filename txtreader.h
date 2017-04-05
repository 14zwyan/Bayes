#ifndef TXTREADER_H
#define TXTREADER_H

#include<vector>
#include<string>
#include<set>

#include"reader.h"
#include"data.h"

class TXTReader: public Reader
{
public:
    TXTReader(std::string fn):m_fileName(fn)
    {
        m_kindSet=std::set<std::string>();
    }
    ~TXTReader();
    std::vector<Data> Read() override ;
    std::set<std::string> GetSet() override { return m_kindSet; }


private:
    std::string m_fileName;
    std::set<std::string> m_kindSet;
};

#endif // TXTREADER_H

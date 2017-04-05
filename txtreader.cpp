#include "txtreader.h"

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using std::ifstream; using std::cout; using std::endl;
using std::vector; using std::string;
using std::stringstream;

vector<Data> TXTReader::Read()
{
    vector<Data> result;


    ifstream file(m_fileName.c_str());
    char temp[1024];
    while(file.getline(temp,512))
    {
        stringstream stream(temp);
        string kind;  stream>>kind;
        double attr; vector<double> attributes;
        while(stream>>attr)
        {
            attributes.push_back(attr);
        }
        Data temp(kind,attributes);
        result.push_back(temp);
        //temp.Show();
    }
    //cout<<result.size()<<endl;

    for(int i=0; i != result.size(); ++i)
    {
        m_kindSet.insert( result[i].Kind() );
    }
    //cout<<m_kindSet.size()<<endl;

    return result;
}



TXTReader::~TXTReader()
{

}


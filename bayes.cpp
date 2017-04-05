#include<sstream>
#include<vector>
#include<set>
#include<cmath>

#include "bayes.h"


using std::string; using std::vector;
using std::set;



Bayes::Bayes(int readerKind,string fileName)
{
    m_reader=CreateReader(readerKind,fileName);
    m_datas=m_reader->Read();
    m_kindSet=m_reader->GetSet();
}

Reader* Bayes::CreateReader(int kind,string fileName)
{
    if(kind==1)
        return new TXTReader(fileName);
    else
        return NULL;
}

string Bayes::Classify(vector<double> attributes)
{
    set<string>::iterator beg=m_kindSet.begin();
    set<string>::iterator end=m_kindSet.end();
    double max=-1;
    std::string max_kind;

    while( beg != end)
    {
        double temp=ComputeClassP(*beg,attributes);
        if( temp > max)
        {
            max=temp;
            max_kind=*beg;
        }
        ++beg;
    }

    if(max==-1)
        return NULL;
    else
        return max_kind;

}


double Bayes::ComputeAverage(int index,string kind) const
{
    int kindCount=0;
    double sum=0;
    size_t len=m_datas.size();

    for(unsigned int i=0; i != len; ++i)
    {
        if(m_datas[i].Kind()==kind )
        {
            ++kindCount;
            sum+=m_datas[i].GetAttribute(index);
        }
    }
    return sum/kindCount;
}

double Bayes::ComputeVariance(int index, string kind) const
{
    double average=ComputeAverage(index,kind);
    int kindCount=0;
    double sum=0;
    size_t len=m_datas.size();

    for(unsigned int i=0; i != len; ++i)
    {
        if(m_datas[i].Kind() == kind)
        {
            ++kindCount;
            sum+=pow( m_datas[i].GetAttribute(index) - average,2);
        }
    }

    return sum/kindCount;
}

double Bayes::ComputeCond_P(int index, std::__cxx11::string kind,double value) const
{
   double average=ComputeAverage(index,kind);
   double variance=ComputeVariance(index,kind);

   double p=(1/sqrt(2*3.14*variance))*exp(-pow(value-average,2)/(2*variance));
   return p;
}

double Bayes::ComputeClassP(string kind,vector<double> attributes)
{
    double result=1;
    for(unsigned i=0; i != attributes.size() ; ++i)
    {
        result*=ComputeCond_P(i,kind,attributes[i]);
    }
    return result;
}



string Bayes::GetData(int index)
{
    string result="类别:";
    result+=m_datas[index].Kind()+"\n";
    result+="属性:\n";
    for(int i=0; i != m_datas[index].GetAttributeSize(); ++i)
    {
        double value=m_datas[index].GetAttribute(i);
        string temp;
        std::stringstream stream;
        stream<<value;
        stream>>temp;
        result+=temp+" ";
    }

    result+="\n";
    return result;

}






Bayes::~Bayes()
{

}


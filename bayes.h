#ifndef BAYES_H
#define BAYES_H

#include<vector>
#include<set>
#include<map>
#include<iostream>

#include"data.h"
#include"testdata.h"
#include"reader.h"
#include"txtreader.h"

class Bayes
{
public:
    Bayes(int readerKind=1,std::string file_name="data.txt");
    ~Bayes();

    std::string Classify(std::vector<double> attributes);


    std::string GetData(int index);
    int GetDataNumber() { return m_datas.size(); }


private:
    std::vector<Data> m_datas;
    std::set<std::string> m_kindSet;
    Reader* m_reader;

    Reader* CreateReader(int kind=1,std::string file_name="data.txt");
//    double GetP(double value,int index);
//    double GetP(std::string kind);
//    double Get_CondP(std::string  kind,double value,int index);
//    double Get_PostCondition(std::string kind,std::vector<double> attributes);

    double ComputeAverage(int index, std::string kind) const;
    double ComputeVariance(int index,std::string kind) const;
    double ComputeCond_P(int index, std::string kind,double value) const ;
    double ComputeClassP(std::string kind,std::vector<double> attributes);
};

#endif // BAYES_H

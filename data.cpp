#include "data.h"

#include<iostream>

using std::cout; using std::endl;

Data::~Data()
{

}

/*just for test**/
void Data::Show()
{
    cout<<"Kind:"<<m_kind<<endl;
    for(int i=0; i != m_attributes.size() ;++i)
    {
        cout<<"att:"<<m_attributes[i]<<" ";
    }
    cout<<endl;
}


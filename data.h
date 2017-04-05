#ifndef DATA_H
#define DATA_H


#include<string>
#include<vector>


class Data
{
public:
    Data( const std::string& kind,
          const std::vector<double> attr):
        m_kind(kind),m_attributes(attr)
    {/*empty**/}
    ~Data();

    void Show();
    std::string Kind() const   { return m_kind; }
    double GetAttribute(int index) const  { return m_attributes[index]; }
    int GetAttributeSize()  const { return m_attributes.size(); }

private:
    std::string  m_kind;
    std::vector<double> m_attributes;
};

#endif // DATA_H

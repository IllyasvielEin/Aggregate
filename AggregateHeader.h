//
// Created by Milu Charle on 2021/3/26.
//

#ifndef AGGREGATE_AGGREGATEHEADER_H
#define AGGREGATE_AGGREGATEHEADER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "vector"
#include <initializer_list>
#include <utility>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <set>
#include <map>
#include <utility>
#include <memory>
#include <bits/stdc++.h>
using namespace std;

void distinguish(bool flag);

class Aggregate
{
public:
    Aggregate() = default;
    Aggregate& operator=(Aggregate B)
    {
        swap(num,B.num);
        swap(size,B.size);
        return *this;
    }

    int whatSize() const { return size;};
    void display(ostream& os);
    void input(istream& is);
private:
    int num[100]{};
    int size = 0;
};

void Aggregate::input(istream &is)
{
    int count = 0;
    int temp;
    int tempArray[80] = {0};
    while ( cin >> temp )
    {
        if (count == 80 )
        {
            break;
        }
        tempArray[count] = temp;
        count++;
    }
    if ( count == 80 )
    {
        int biggerArray[160] = {0};
        memcpy(biggerArray,tempArray,sizeof(tempArray));
    }
}

void Aggregate::display(ostream& os)
{
    os << "(";
    for ( auto i : num )
    {
         os << i << " ";
    }
    os << ")";
}



#endif //AGGREGATE_AGGREGATEHEADER_H

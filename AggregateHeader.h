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
void display(int num[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void sort(int *pNum, int size)
{
    int temp;
    int loc;
    for (int i = 0; i < size; ++i)
    {
        loc = i;
        int min = pNum[i];
        for (int j = i+1; j < size; ++j)
        {
            if ( pNum[j]<min )
            {
                min = pNum[j];
                loc = j;
            }
        }
        swap(pNum[i],pNum[loc]);
    }
}
int Unique(int *pNum, int size)
{
    int tempSize = size;
    for (int i = 0; i < size-1; ++i)
    {
        int flag = 0;
        int j = i+1;
        while ( pNum[i] == pNum[j] )
        {
            cout << pNum[i]  << " = " << pNum[j] << endl;
            pNum[j] = 0;
            tempSize--;
            j++;
        }
    }
//    display(pNum,size);
    for (int i = 0; i < size-1; ++i)
    {
        if ( pNum[i] == 0 )
        {
            for (int j = i+1; j < size; ++j)
            {
                if ( pNum[j] != 0 )
                {
                    swap(pNum[i],pNum[j]);
                    break;
                }
            }
        }
    }
    return tempSize;
}

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
    bool isSub(const Aggregate& B);
    int find(const Aggregate& B);
private:
    int *num{};
    int size = 0;
};

void Aggregate::input(istream &is)
{
    int temp;
    int it = 0;
    int count = 10;
    int *pNum = new int[count];

    cout << "Enter aggregate:";
    while ( cin >> temp, temp != 114514 )
    {
        if ( size > count )
        {
            int* pTemp = pNum;
            count += 80;
            pNum = new int[count];
            memcpy(pNum,pTemp, sizeof(*pTemp));
        }
        pNum[it] = temp;
        it++;
        size++;

    }
//    ::display(pNum,size);
    sort(pNum,size);
//    cout << "Sort: ";
//    ::display(pNum,size);
//    cout << "Unique:";
    size = Unique(pNum,size);
//    ::display(pNum,size);
    num = pNum;
}

void Aggregate::display(ostream& os)
{
    os << "( ";
    for (int i = 0; i<size ;i++ )
    {
         os << num[i] << " ";
    }
    os << ")";
}

bool Aggregate::isSub(const Aggregate &B) {
    if ( size > B.size )
    {
        cout << "The size of the first aggregate is bigger than the later.";
        return false;
    }
    else if ( size == B.size && num[0] != B.num[0] )
    {
        return false;
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < B.size; ++i)
        {
            if ( )
        }
    }
    return false;
}


#endif //AGGREGATE_AGGREGATEHEADER_H

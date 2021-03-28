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
//        display(pNum,5);
    }
}
int Unique(int *pNum, int size)
{
    int* pTemp = pNum;
    int tempSize = size;
    for (int i = 0; i < size; ++i)
    {
        if (pTemp[i] == 114514 )
        {
            continue;
        }
        int j = i+1;
        while (pTemp[i] == pTemp[j] )
        {
//            cout << pTemp[i]  << " = " << pTemp[j] << endl;
            pTemp[j] = 114514;
            tempSize--;
            j++;
        }
    }
//    display(pTemp,size);
    for (int i = 0; i < size-1; ++i)
    {
        if (pTemp[i] == 114514 )
        {
            for (int j = i+1; j < size; ++j)
            {
                if (pTemp[j] != 114514 )
                {
                    swap(pTemp[i], pTemp[j]);
                    break;
                }
            }
        }
    }
//    cout << tempSize << endl;
    display(pTemp,size);
    pNum = new int[tempSize];
    memcpy(pNum,pTemp,sizeof(int)*tempSize);
//    delete pTemp;
    return tempSize;
}
void swap(int *a, int *b)
{
    auto temp = a;
    a = b;
    b = temp;
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
        if ( size == count )
        {
            int* pTemp = pNum;
            count += 80;
            pNum = new int[count];
            memcpy(pNum, pTemp, sizeof(int)*10 );
            pTemp = nullptr;
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
        int tag;
        tag = find(B);
//        cout << "tag: " << tag << endl;
        if ( tag == -1 )
        {
            return false;
        }
        else
        {
            int mark = 0;
            for (int i = 0; i<size && tag < B.size ; ++i,tag++)
            {
                if ( num[i] == B.num[tag])
                {
                    mark++;
//                    cout << "mark: " << mark << endl;
                }
            }
            if ( mark != size)
            {
                return false;
            }
        }
    }
    return true;
}

int Aggregate::find(const Aggregate &B) {
    for (int i = 0; i < B.size; ++i)
    {
        if ( num[0] == B.num[i] )
        {
            return i;
        }
    }
    return -1;
}


#endif //AGGREGATE_AGGREGATEHEADER_H

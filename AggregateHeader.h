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
void display(int *num, int size)
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
    int tempSize = size;
    for (int i = 0; i < size; ++i)
    {
        if (pNum[i] == 114514 )
        {
            continue;
        }
        int j = i+1;
        while (pNum[i] == pNum[j] )
        {
//            cout << pNum[i]  << " = " << pNum[j] << endl;
            pNum[j] = 114514;
            tempSize--;
            j++;
        }
    }
//    display(pNum,size);
    for (int i = 0; i < size-1; ++i)
    {
        if (pNum[i] == 114514 )
        {
            for (int j = i+1; j < size; ++j)
            {
                if (pNum[j] != 114514 )
                {
                    swap(pNum[i], pNum[j]);
                    break;
                }
            }
        }
    }
    return tempSize;
}   //可以对size使用引用
void swap(int *a, int *b)
{
    auto temp = a;
    a = b;
    b = temp;
}
int deleRepe(int *p, int size)
{
    int repe = 0;
    for (int i = 0; i < size; ++i)
    {
        int j = i+1;
        if ( p[i] == p[j] )
        {
            cout << p[i] << " = " << p[j] << endl;
            repe++;
        }
        else
        {
            p[j-repe] = p[j];
        }
    }
    return size-=repe;
}
int UnionA(int *A, const int *B, int sizeA, int sizeB)
{
    int repe = 0;
    int distance = 0;
    for (int i = 0; i < sizeA; ++i) {
        for (int j = 0; j < sizeB; ++j) {
            if ( A[i] == B[j] )
            {
                A[i-distance] = A[i];
                repe++;
                distance = 0;
            }
            else
            {
                distance++;
            }
        }
    }
    return sizeA-=repe;
}

class Aggregate
{
public:
    Aggregate() = default;
    Aggregate(int *p,int n):num(p),size(n){};
    Aggregate& operator=(Aggregate B)
    {
        num = B.num;
        size = B.size;
        return *this;
    }

    int whatSize() const { return size;};
    void display(ostream& os);
    void input(istream& is);
    bool isSub(const Aggregate& B);
    int find(const Aggregate& B);
    Aggregate Intersect(const Aggregate& B);
    Aggregate Union(const Aggregate& B);
    Aggregate DiffAgg(const Aggregate& B);
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
    if ( size == 0)
    {
        cout << "->Empty aggregate." << endl;
    }
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

Aggregate Aggregate::Intersect(const Aggregate& B)
{
    int it = 0;
    int temp[100];
    int totalSize = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < B.size; ++j)
        {
            if ( num[i] == B.num[j] )
            {
                temp[it] = num[i];
                totalSize++;
                it++;
            }
        }
    }
    int* p = new int[totalSize];
    memcpy(p,temp,sizeof(int)*totalSize);
    sort(p,totalSize);
    totalSize = Unique(p,totalSize);
    return Aggregate(p,totalSize);
}

Aggregate Aggregate::Union(const Aggregate &B) {
    int totalSize = size+B.size;
    int* pTemp = new int[size+B.size];
    memcpy(pTemp,num,size*sizeof(int) );
    memcpy(pTemp+size,B.num,B.size* sizeof(int) );
//    ::display(pNum,size+B.size);
//    ::display(pNum,totalSize);
    sort(pTemp,totalSize);
//    ::display(pNum,totalSize);
//    cout << "TotalSize: " << totalSize;
    totalSize = Unique(pTemp,totalSize);
    int *p = new int[totalSize];
    memcpy(p,pTemp,sizeof(int)*totalSize);
    delete[] pTemp;
    pTemp = p;
//    cout << "Unique TotalSize: " << totalSize;
//    cout << "Intersect inside num: ";
//    ::display(pTemp,totalSize+4);
    return Aggregate(pTemp,totalSize);
}

Aggregate Aggregate::DiffAgg(const Aggregate &B) {
    Aggregate interC = Intersect(B);
    Aggregate uniD = Union(B);

    int diffCount = uniD.size;
    for (int i = 0; i < uniD.size ; ++i)
    {
        for (int j = 0; j < interC.size ; ++j)
        {
            if ( interC.num[i] == uniD.num[j] )
            {
                uniD.num[i] = 114514;
                diffCount--;
            }
        }
    }
//    cout << "interC: ";
    sort(uniD.num,uniD.size);
    int *p = new int[diffCount];
    memcpy(p,uniD.num, sizeof(int)*diffCount);
    return Aggregate(p,diffCount);
}

#endif //AGGREGATE_AGGREGATEHEADER_H

#include "AggregateHeader.h"

int main() {
//    int count = 10;
//    int num[10] = {1,0,1,0,5,3,0,1,0,0};
//    display(num,count);
//    sort(num,count);
//    display(num,count);
//    Unique(num,count);
//    display(num,count);

//    Aggregate A;
//    A.input(cin);
//    A.display(cout);
//    cout << " Size: " << A.whatSize() << endl;
//    Aggregate B;
//    B.input(cin);
//    B.display(cout);
//    cout << " Size: " << B.whatSize() << endl;
//
//    Aggregate C;
//    C = A.DiffAgg(B) ;
//    C.display(cout);
//    cout << " Size: " << C.whatSize() << endl;

    int A[18] = {1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,8,9};
    int size = deleRepe(A,18);
    display(A,size);
    system("pause");
    return 0;
}


void distinguish(bool flag)
{
    if  ( flag )
    {
        cout << "A is a subAggregate of B.";
    }
    else
    {
        cout << "A is Not a subAggregate of B.";
    }
}

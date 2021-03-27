#include "AggregateHeader.h"

int main() {
    Aggregate A;
    A.input(cin);
    A.display(cout);
    cout << A.whatSize() << endl;
    Aggregate B;
    B.input(cin);
    B.display(cout);
    cout << B.whatSize() << endl;
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

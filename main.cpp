#include "AggregateHeader.h"

int main() {
    Aggregate A;
    A.input(cin);
    A.display(cout);
//    cout << A.whatSize();

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
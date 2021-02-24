#ifndef POLYTERMH
#define POLYTERMH

struct PolyTerm
{
    int coeff;
    int expo;
    struct PolyTerm *next;
};

#endif
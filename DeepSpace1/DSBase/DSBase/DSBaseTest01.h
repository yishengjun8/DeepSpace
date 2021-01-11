#pragma once
#include "DSBaseTest00.h"


namespace DeepSpace
{
    class DSBaseTest01 :
        public DSBaseTest00
    {
        DSOBJECT(DSBaseTest01);
    public:
        DSBaseTest01();
        ~DSBaseTest01();
        DSReturn Clone(DSBase** ret);
        BOOL operator==(DSBase& rhs);
        DSBase& operator=(DSBase& rhs);

    public:
        DSReturn SayHello(int set);
        DSReturn SayGoodBy();
        DSReturn SetData(int set);
    protected:
        int myData;
    };
}


#pragma once
#include "DSBase.h"

namespace DeepSpace
{
    class DSBaseTest00 :
        public DSBase
    {
        DSOBJECT(DSBaseTest00);
    public:
        DSBaseTest00();
        ~DSBaseTest00();
        DSReturn Clone(DSBase** ret);
        DSBase& operator=(DSBase& rhs);

    public:
        DSReturn SayHello(int set);
        DSReturn SayGoodBy();
        DSReturn SetData(int set);
    protected:
        int myData;
    };
}


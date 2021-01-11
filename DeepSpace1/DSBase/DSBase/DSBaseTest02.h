#pragma once
#include "DSBaseTest01.h"


namespace DeepSpace
{
    class DSBaseTest02 :
        public DSBaseTest01
    {
        DSOBJECT(DSBaseTest02);
    public:
        DSBaseTest02();
        ~DSBaseTest02();
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


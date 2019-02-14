//
//  main.cpp
//  testc
//
//  Created by Florent Jacquemard on 17/06/17.
//  Copyright © 2017 Florent Jacquemard. All rights reserved.
//

#include <iostream>



class A
{
public:
    A(int i):content(i) {}
    
    virtual void hi() { std::cout << "c'est A\n"; }
    
    int content;
};


class B: public A
{
public:
    B(int i):A(i) {}

    virtual void hi() { std::cout << "c'est B\n"; }
};

class C: public B
{
public:
    virtual void hi() { std::cout << "c'est C\n"; }
};


class Run
{
public:
    Run()
    {
        content = new A(0);
    }

    Run(int i)
    {
        content = new B(1);
    }

    A* content;

};


class Cont
{
public:
    void eval(Run& r)
    {
        r.content->hi();
    }
    
    
};


class Pipo
{
public:
    Pipo(A* p)
    {
        p->hi();
    }
};


class S
{
public:
    S()
    {
        c = 0;
        std::cout << "constructor S0 " << c << " \n";
    }
    
    S(int a):c(a)
    {
        init();
        std::cout << "constructor S " << c << " \n";
    }
    
    virtual void pipo(int i)
    {
        std::cout << "S.pipo " << i << " \n";
    }
    
    virtual void init()
    {
        std::cout << "S.init\n";
        c = 1;
        pipo(c);
    }
    
    int c;
    
};


class SI : public S
{
public:
    SI(int a):S()
    {
        init();
        std::cout << "constructor SI " << c << " \n";
    }

    virtual void pipo(int i)
    {
        std::cout << "SI.pipo " << i << " \n";
    }
    
//    virtual void init()
//    {
//        std::cout << "SI.init SI\n";
//        c = 8;
//    }
    
};


int main(int argc, const char * argv[])
{
//    Pipo pi = Pipo(b);

    // test polymorphisme
    Run r = Run(2);
    r.content->hi();
    Cont c = Cont();
    c.eval(r);
    
    
//    SI si(0);   
//    std::cout << "SI.c = " << si.c << " \n";
    
    return 0;
}

#pragma once

#include <iostream>

class FooPureVirtual {
public:
    ~FooPureVirtual() = default;

    virtual void foo() = 0;
    virtual void bar() = 0;
};

class FooConcrete : public FooPureVirtual {
public:
    FooConcrete() = default;
    ~FooConcrete() = default;

    void foo() override {
        // do something
        a_ = 1+1;
        std::cout << "FooConcrete::foo() called: " << a_ << std::endl;
    };

    void bar() override {
        // do something
        a_ = 2+2;
        std::cout << "FooConcrete::bar() called: " << a_ << std::endl;
    };

private:
    int a_{0};

};

class UseFoo {
public:
    UseFoo(FooPureVirtual* foo) : foo_(foo) {};
    ~UseFoo() = default;

    void useFoo() {
        foo_->foo();
    }

    void useBar() {
        foo_->bar();
    }

public:
    FooPureVirtual* foo_;
};

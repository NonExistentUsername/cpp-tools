#pragma once

template<class T, class FuncT>
class Lazy {
private:
    FuncT func;
    T* x = nullptr;
public:
    Lazy(T*, FuncT func): func(func) {}

    T* get() {
        if(!x) x = func();
        return x;
    }

    ~Lazy() {
        if(x) delete x;
    }
};

template<class T, class... Args>
auto createLazy(Args... args) {
    auto func = [args...]() {
        return new T(args...);
    };
    return Lazy((T*)(nullptr), func);
}
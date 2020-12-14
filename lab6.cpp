#include "make_random_vector.hpp"
#include <iostream>
#include <list>
#include <vector>

int glob;

struct comp
{
    template < typename T >
    bool operator()(const T& l, const T& r) const
    {
        return l > r;
    }
};

struct bigger7
{
    template < typename T >
    bool operator()(const T& a) const
    {
        return a >= 7;
    }
};

struct K
{
    K(int tmp) { k = tmp; }
    int k;
    template < typename T >
    bool operator()(const T& a) const
    {
        return a >= k;
    }
};

struct test
{
    test() { a = 10; }
    test(int tmp) { a = tmp; }
    int  a;
    void print() { std::cout << "Print! " << a << "\n"; }
    bool check()
    {
        if (a == 10) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{
    auto                print = [](char& c) { std::cout << " " << c << "\n"; };
    auto                fill  = [](char& c) { c = 'f'; };
    std::vector< char > ret_v(10);
    std::for_each(ret_v.begin(), ret_v.end(), fill);
    std::for_each(ret_v.begin(), ret_v.end(), print);

    std::list< test > T;
    T.push_back(test(11));
    T.push_back(test());
    auto sprawdzenie = [](test& tmp) {
        if (tmp.check()) {
            return 'y';
        }
        else {
            return 'n';
        }
    };

    std::for_each(T.begin(), T.end(), [](test& tmp) { tmp.print(); });
    std::transform(T.begin(), T.end(), ret_v.rbegin(), sprawdzenie);
    std::for_each(ret_v.begin(), ret_v.end(), print);

    // std::for_each(ret_v.begin(), ret_v.end(), [](char& c) { std::cout << c << "\n"; });
}
#pragma once

#include "Human.hpp"

#include <algorithm>
#include <list>
#include <vector>

std::vector< char > foo(std::list< Human >& people)
{
    std::vector< char > ret_v(people.size());

    std::for_each(people.begin(), people.end(),[](Human& h){h.birthday();} );

  auto sprawdzenie = [](Human& tmp) {
        if (tmp.isMonster()) {
            return 'n';
        }
        else {
            return 'y';
        }
    };

    std::transform(people.begin(),people.end(), ret_v.rbegin(),sprawdzenie);

    return ret_v;
}

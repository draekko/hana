/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

<% if input_size > 10 %>
    #define FUSION_MAX_VECTOR_SIZE <%= ((input_size + 9) / 10) * 10 %>
<% end %>

#include <boost/fusion/include/count_if.hpp>
#include <boost/fusion/include/make_vector.hpp>

#include "measure.hpp"
#include <cstdlib>
namespace fusion = boost::fusion;
namespace hana = boost::hana;


int main () {
    hana::benchmark::measure([] {
        unsigned long long result = 0;
        for (int iteration = 0; iteration < 1 << 10; ++iteration) {
            auto values = fusion::make_vector(
                <%= input_size.times.map { 'std::rand()' }.join(', ') %>
            );

            result += fusion::count_if(values, [](auto i) {
                return i % 2 == 0;
            });
        }
    });
}
#ifndef VECTORS_OF_TUPLES_HPP
#define VECTORS_OF_TUPLES_HPP

#include <vector>
#include <tuple>
#include <algorithm>

#include <boost/test/unit_test.hpp>

using namespace std;

void TEST_VECTORS_OF_TUPLES_3(
    vector<tuple<int, int, int> > lh,
    vector<tuple<int, int, int> > rh)
{
    BOOST_REQUIRE_EQUAL(lh.size(), rh.size());
    sort(lh.begin(), lh.end());
    sort(rh.begin(), rh.end());
    for(int i = 0; i < lh.size(); i++) {
        BOOST_REQUIRE_EQUAL(get<0>(lh.at(i)), get<0>(lh.at(i)));
        BOOST_REQUIRE_EQUAL(get<1>(lh.at(i)), get<1>(lh.at(i)));
        BOOST_REQUIRE_EQUAL(get<2>(lh.at(i)), get<2>(lh.at(i)));
    }
}

#endif

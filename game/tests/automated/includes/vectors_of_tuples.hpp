#ifndef VECTORS_OF_TUPLES_HPP
#define VECTORS_OF_TUPLES_HPP

#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

#include <boost/test/unit_test.hpp>

using namespace std;

void print_vector_of_tuples_3(vector<tuple<int, int, int>> vot) {
    for(int i = 0; i < vot.size(); i++) {
        cout << "(" << get<0>(vot.at(i)) << ", " << get<1>(vot.at(i)) 
             << ", " << get<2>(vot.at(i)) << ")" << endl;
    }
}

void TEST_VECTORS_OF_TUPLES_3(
    vector<tuple<int, int, int>> lh,
    vector<tuple<int, int, int>> rh)
{
    sort(lh.begin(), lh.end());
    sort(rh.begin(), rh.end());
    if(lh.size() != rh.size()) {
        cout << "LH != RH" << endl;
        cout << "LH (after sorting):" << endl;
        print_vector_of_tuples_3(lh);
        cout << "RH (after sorting):" << endl;
        print_vector_of_tuples_3(rh);
        BOOST_FAIL("LH != RH");
    }
    for(int i = 0; i < lh.size(); i++) {
        BOOST_REQUIRE_EQUAL(get<0>(lh.at(i)), get<0>(rh.at(i)));
        BOOST_REQUIRE_EQUAL(get<1>(lh.at(i)), get<1>(rh.at(i)));
        BOOST_REQUIRE_EQUAL(get<2>(lh.at(i)), get<2>(rh.at(i)));
    }
}

#endif

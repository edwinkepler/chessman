/**
 * @copyright 2017 Edwin Kepler
 * @license MIT
 */

#ifndef HELPERS_TEST_HPP
#define HELPERS_TEST_HPP

#include <utility>
#include <vector>
#include <tuple>

#include "helpers/comparison.hpp"
#include "helpers/conversion.hpp"

#include "debug/log.hpp"

#define BOOST_TEST_MAIN

#include "includes/vectors_of_tuples.hpp"
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(ctoi)
{
    Debug::Log::test_func_head("ctoi");
    BOOST_REQUIRE_EQUAL(2, Helper::ctoi('b'));
    Debug::Log::test_func_foot("ctoi");
}

BOOST_AUTO_TEST_CASE(itoc)
{
    Debug::Log::test_func_head("itoc");
    BOOST_REQUIRE_EQUAL('b', Helper::itoc(2));
    Debug::Log::test_func_foot("itoc");
}

BOOST_AUTO_TEST_CASE(transx_add)
{
    Debug::Log::test_func_head("transx_add");
    pair<int, int> test = make_pair(1, 1);
    pair<int, int> result = make_pair(2, 1);
    TEST_PAIRS(result, Helper::transx(test, 1));
    Debug::Log::test_func_foot("transx_add");
}

BOOST_AUTO_TEST_CASE(transx_minus)
{
    Debug::Log::test_func_head("transx_minus");
    pair<int, int> test = make_pair(2, 2);
    pair<int, int> result = make_pair(1, 2);
    TEST_PAIRS(result, Helper::transx(test, -1));
    Debug::Log::test_func_foot("transx_minus");
}

BOOST_AUTO_TEST_CASE(transy_add)
{
    Debug::Log::test_func_head("transy_add");
    pair<int, int> test = make_pair(1, 1);
    pair<int, int> result = make_pair(1, 2);
    TEST_PAIRS(result, Helper::transy(test, 1));
    Debug::Log::test_func_foot("transy_add");
}

BOOST_AUTO_TEST_CASE(transy_minus)
{
    Debug::Log::test_func_head("transy_minus");
    pair<int, int> test = make_pair(2, 2);
    pair<int, int> result = make_pair(2, 1);
    TEST_PAIRS(result, Helper::transy(test, -1));
    Debug::Log::test_func_foot("transy_minus");
}

BOOST_AUTO_TEST_CASE(greaterx)
{
    Debug::Log::test_func_head("greaterx");
    pair<int, int> test = make_pair(1, 2);
    pair<int, int> result = make_pair(2, 2);
    BOOST_REQUIRE_EQUAL(false, Helper::greaterx(test, result));
    Debug::Log::test_func_foot("greaterx");
}

BOOST_AUTO_TEST_CASE(greatery)
{
    Debug::Log::test_func_head("greatery");
    pair<int, int> test = make_pair(2, 2);
    pair<int, int> result = make_pair(2, 1);
    BOOST_REQUIRE_EQUAL(true, Helper::greatery(test, result));
    Debug::Log::test_func_foot("greatery");
}

BOOST_AUTO_TEST_CASE(contains)
{
    Debug::Log::test_func_head("contains");
    vector<tuple<int, int, int>> test;
    auto tmp = make_tuple(2, 2, 1);
    test.push_back(tmp);
    pair<int, int> result = make_pair(2, 2);
    BOOST_REQUIRE_EQUAL(true, Helper::contains(test, result));
    Debug::Log::test_func_foot("contains");
}

#endif // HELPERS_TEST_HPP

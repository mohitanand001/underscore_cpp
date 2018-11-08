#include "test_includes.hpp"

TEST_CASE("basic tests_main")
{
    std::vector<int> vec = {1, 2, 3};
    std::vector<int> rec = {2, 34, 43};
    std::vector<int> lec = {3, 54, 1};

    std::vector<int> sec = _::set_union(vec, rec, lec);

    SECTION("_::each section")
    {
        REQUIRE(vec.begin() != vec.end());

        // 1, 2, 3 don't get added again in union, size should be 6
        REQUIRE(sec.size() == (vec.size() + rec.size() + lec.size() - 3));
        _::each(sec, display);
        std::cout << std::endl;
        _::each(vec.begin(), vec.end(), display);
        std::cout << std::endl;
        _::each(rec.begin(), rec.end(), display);
        std::cout << std::endl;
        _::each(lec.begin(), lec.end(), display);
        std::cout << std::endl;
        _::each(sec.begin(), sec.end(), display);
        std::cout << std::endl;
        std::cout << std::endl;
        _::each(sec, [](int elem) { std::cout << "_::each(λdisplay) -> " << elem << std::endl; });
        std::cout << std::endl;
    }

    SECTION("_::reduce section")
    {
        std::cout << "\nReduce ";
        _::each(vec.begin(), vec.end(), display);
        std::cout << "-> " << _::reduce(vec, multiply, 1) << std::endl;
    }

    SECTION("_::group_by section")
    {
        std::cout << std::endl;
        // test group_by with bool keyed groups
        auto mp_bool = _::group_by(vec, is_odd);
        std::cout << "group_by (is_odd)" << std::endl;
        for (const auto &it : mp_bool)
        {
            std::cout << (it.first) << ": ";
            for (int j : (it.second)) std::cout << j << ", ";
            std::cout << std::endl;
        }

        REQUIRE(mp_bool.size() == 2);

        // not odds(false) -> 1 == { 2 }
        REQUIRE(mp_bool[false].size() == 1);
        REQUIRE(mp_bool[false][0] == 2);

        // odds(true) -> 2 == { 1, 3 }
        REQUIRE(mp_bool[true].size() == 2);
        REQUIRE(mp_bool[true][0] == 1);
        REQUIRE(mp_bool[true][1] == 3);

        std::cout << std::endl;
        // test group_by with int keyed groups, mulp multiplies by 10
        auto mp_int = _::group_by(vec, mulp);
        std::cout << "group_by (mulp)" << std::endl;
        for (const auto &it : mp_int)
        {
            std::cout << (it.first) << ": ";
            for (int j : (it.second)) std::cout << j << ", ";
            std::cout << std::endl;
        }
        REQUIRE(mp_int.size() == 3);
        REQUIRE(mp_int[10][0] == 1);
        REQUIRE(mp_int[20][0] == 2);
        REQUIRE(mp_int[30][0] == 3);
    }

    SECTION("_::count_by section")
    {
        std::cout << std::endl;

        // test count_by
        std::cout << std::endl << "count_by (is_odd)" << std::endl;
        auto count_by_bool = _::count_by(vec, is_odd);
        for (const auto &kv : count_by_bool)
        {
            std::cout << kv.first << " " << kv.second << std::endl;
        }
        REQUIRE(count_by_bool.size() == 2);
        REQUIRE(count_by_bool[false] == 1);
        REQUIRE(count_by_bool[true] == 2);

        std::cout << std::endl << "count_by (mulp)" << std::endl;
        auto count_by_mulp = _::count_by(vec, mulp);
        for (const auto &kv : count_by_mulp)
        {
            std::cout << kv.first << " " << kv.second << std::endl;
        }
        REQUIRE(count_by_mulp.size() == 3);
        REQUIRE(count_by_mulp[10] == 1);
        REQUIRE(count_by_mulp[20] == 1);
        REQUIRE(count_by_mulp[30] == 1);
        std::cout << std::endl;
    }

    SECTION("_::set_union section")
    {
        std::vector<int> unsorted_a = {9, 9, 6, 6, 1};     // 3 uniques
        std::vector<int> unsorted_b = {4, 4, 1, 1, 2, 2};  // 3 uniques, but 1 repeats
        std::vector<int> unsorted_c = {3, 5, 0, 7, 8};     // missing numbers to complete [0-9]
        std::vector<int> everybody_sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<int> unsorted_a_twin = {9, 9, 6, 6, 1};

        auto sorted_a_b_union = _::set_union(unsorted_a, unsorted_b);
        REQUIRE(sorted_a_b_union.size() == 5);

        std::cout << "set_union" << std::endl;
        _::each(sorted_a_b_union, display);
        std::cout << std::endl;

        std::vector<int> empty_vector = {};
        // test union with right side parameter empty
        auto unsorted_a_empty_union = _::set_union(unsorted_a, empty_vector);
        _::each(unsorted_a_empty_union, display);
        std::cout << std::endl;
        REQUIRE(unsorted_a_empty_union != empty_vector);
        REQUIRE(unsorted_a_empty_union.size() == unsorted_a.size());
        REQUIRE(unsorted_a_empty_union == unsorted_a);  // it does compare all elements

        // test union with left side parameter empty
        auto unsorted_b_empty_union = _::set_union(empty_vector, unsorted_b);
        _::each(unsorted_b_empty_union, display);
        std::cout << std::endl;
        REQUIRE(unsorted_b_empty_union != empty_vector);
        REQUIRE(unsorted_b_empty_union.size() == unsorted_b.size());
        REQUIRE(unsorted_b_empty_union == unsorted_b);  // it does compare all elementsOA
        std::cout << std::endl;

        // test when two containers that have the same elements are attempted to be united
        // if we tried to unite them, we'd get rid of the repeated elements
        // if we detect they're the same we simply return the container as is, no elements
        // are removed. TODO: discuss what to do in this case, maybe check what underscore_js does
        auto not_united_twins = _::set_union(unsorted_a, unsorted_a_twin);
        REQUIRE(not_united_twins == unsorted_a);
        _::each(not_united_twins, display);
        std::cout << std::endl;
        REQUIRE(not_united_twins == unsorted_a_twin);
        _::each(not_united_twins, display);
        std::cout << std::endl;

        // test joining all, we should have all numbers from 0 to 9
        auto everybody_united = _::set_union(empty_vector, unsorted_a, unsorted_b, unsorted_c);
        REQUIRE(everybody_united == everybody_sorted);
        _::each(everybody_united, display);
        std::cout << std::endl;
        everybody_united = _::set_union(unsorted_a, empty_vector, unsorted_c, unsorted_b);
        REQUIRE(everybody_united == everybody_sorted);
        _::each(everybody_united, display);
        std::cout << std::endl;

        // a more challenging case, repeat some elements, with several empty vectors in between
        everybody_united =
            _::set_union(unsorted_a, unsorted_a, unsorted_b, unsorted_c, empty_vector);
        REQUIRE(everybody_united == everybody_sorted);
        _::each(everybody_united, display);
        std::cout << std::endl;

        // TODO: Solve for a case with more than one empty_vector, won't build
        // TODO: Test this with other data types than naive int
    }

    SECTION("_::intersect section")
    {
        const std::vector<int> a = { 5, 1, 3, 2, 4};
        const std::vector<int> b = { 9, 6, 5, 1, 2};
        // 1, 2, 5, should be the intersection of a and b

        auto a_b_intersection = _::intersect(a, b);
        REQUIRE(a_b_intersection.size() == 3);
        REQUIRE(a_b_intersection[0] == 1);
        REQUIRE(a_b_intersection[1] == 2);
        REQUIRE(a_b_intersection[2] == 5);

        std::cout << std::endl << "intersect" << std::endl;
        _::each(a, display);
        std::cout << std::endl;
        _::each(b, display);
        std::cout << std::endl;
        _::each(a_b_intersection, display);
        std::cout << std::endl;

        // make sure original containers did not mutate
        REQUIRE(a[2] == 3);
        REQUIRE(a[4] == 4);
        REQUIRE(b[0] == 9);
        REQUIRE(b[2] == 5);
        REQUIRE(b[4] == 2);
    }
    // TODO: Way more test sections
}

/**
int main()
{
        _::each(sec.begin(), sec.end(), display);
        std::cout << std::endl;
        // std::vector<int> vec = {1, 2, 45};
        // std::vector<int> lec;
        // std::map<int, int> mp;
        // mp[1] = 3, mp[2] = 21;
        // std::pair<const int, int> p {1, 3} ;
        // std::unordered_set<int> s; s.insert(1); s.insert(2); s.insert(23);
        // std::cout << _::contains(s.begin(), s.end(), 1212) << "\n";
        // std::cout << _::contains(mp.begin(), mp.end(), p) << "\n";
        // std::vector<int> v ={-999,1,3}, c = {-999, 1, 11, 3}, x = {-999, 1, 3, 4, 5};
        // std::cout << _::min(v) - v.begin() << "\n";
        // std::cout << *_::min(v) << "\n";
        // std::cout << _::max(v) - v.begin() << "\n";
        // std::cout << *_::max(v) << "\n";
        // std::cout <<	_::size(v)<<"\n";
        // std::vector<int> result = _::intersect(v, v, c, x);
        // std::vector<int>
        // for(auto n : result) {
        // 	std::cout << n << " ";
        // }
        // result = _::set_union(v, c, x);
        // for(auto n : result)
        // {
        // 	std::cout << n << " ";
        // }

    // auto x = std::find(mp.begin(), mp.end(), p) != mp.end();
        // std::cout << x << std::endl;
        // std::cout << x << std::endl;

        // std::cout << contains(vec.begin(), vec.end(), 1);

        // each(vec.begin(), vec.end(), display);
        // each(vec.begin(), vec.end(), incr);
        // each(vec.begin(), vec.end(), display);

        // transform(vec.begin(), vec.end(), lec.begin(), incr);
        // each(lec.begin(), lec.end(), display);
        // std::cout << std::endl;
        // transform(vec.begin(), vec.end(), lec.begin(), mulp);
        // each(lec.begin(), lec.end(), display);

        // lec = filter_accept(vec, is_odd);
        // each(lec.begin(), lec.end(), display);
        // std::cout << std::endl;

        // lec = filter_reject(vec, is_odd);
        // each(lec.begin(), lec.end(), display);
        // std::cout << std::endl;

        return 0;
}
*/

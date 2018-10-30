#include "test_includes.hpp"

TEST_CASE("basic tests_main") {

	std::vector<int> vec = {1, 2, 3};
	std::vector<int> rec = {2, 34, 43};
	std::vector<int> lec = {3, 54, 1};

	std::vector<int> sec = _::set_union(vec, rec, lec);

    SECTION("_::each section")
    {
        REQUIRE(vec.begin() != vec.end());

        // 1, 2, 3 don't get added again in union, size should be 6
        REQUIRE(sec.size() == (vec.size() + rec.size() + lec.size() - 3));

	    _::each(vec.begin(), vec.end(), display);
        std::cout << std::endl;
	    _::each(rec.begin(), rec.end(), display);
	    std::cout << std::endl;
	    _::each(lec.begin(), lec.end(), display);
	    std::cout << std::endl;
        _::each(sec.begin(), sec.end(), display);
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
        for (const auto &it : mp_bool) {
            std:: cout << (it.first) << ": " ;
            for (int j : (it.second))
                std::cout << j << ", ";
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
	    for (const auto &it : mp_int) {
		    std:: cout << (it.first) << ": " ;
		    for (int j : (it.second))
			    std::cout << j << ", ";
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
        for(const auto &kv : count_by_bool) {
            std::cout << kv.first << " " << kv.second << std::endl;
        }
        REQUIRE(count_by_bool.size() == 2);
        REQUIRE(count_by_bool[false] == 1);
        REQUIRE(count_by_bool[true] == 2);

        std::cout << std::endl << "count_by (mulp)" << std::endl;
        auto count_by_mulp = _::count_by(vec, mulp);
        for(const auto &kv : count_by_mulp) {
            std::cout << kv.first << " " << kv.second << std::endl;
        }
        REQUIRE(count_by_mulp.size() == 3);
        REQUIRE(count_by_mulp[10] == 1);
        REQUIRE(count_by_mulp[20] == 1);
        REQUIRE(count_by_mulp[30] == 1);
        std::cout << std::endl;
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

# pragma once

#define FOR(x, y) \
	for (typename std::remove_cv<typename std::remove_reference<decltype(y)>::type>::type x = 0;  x < (y); ++x)
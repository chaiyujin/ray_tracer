#pragma once
#include <random>

namespace yuki {
	class Random {
	private:
		std::random_device   r;
		std::seed_seq        seed;
		std::mt19937         engine;
		std::uniform_real_distribution<> dist;
	public:
		Random() : r(),
			seed({ r(), r(), r(), r(), r() }),
			engine(seed),
			dist(0, 1) {}
		~Random() {}

		double random() {
			return dist(engine);
		}

		// return a number in [0, scale)
		template <class T>
		T random(T scale) {
			return (T)(random() * scale);
		}
	};
}
#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace EESTL {
	template <typename T1, typename T2>
	struct pair {
		pair(T1 f, T2 s) : first{f}, second{s} {}
		~pair() {}
		T1 first;
		T2 second;
	};

	template <typename T1, typename T2>
	bool operator == (const pair<T1, T2>& pl, const pair<T1, T2>& pr) {
		return (pl.first == pr.first && pl.second == pr.second);
	}

	template <typename T1, typename T2>
	bool operator != (const pair<T1, T2>& pl, const pair<T1, T2>& pr) {
		return !(pl == pr);
	}

	template <typename T1, typename T2>
	bool operator < (const pair<T1, T2>& pl, const pair<T1, T2>& pr) {
		return (pl.first < pr.first) || (pl.second < pr.second);
	}

	template <typename T1, typename T2>
	bool operator <= (const pair<T1, T2>& pl, const pair<T1, T2>& pr) {
		return (pl.first <= pr.first);
	}


	template <typename T1, typename T2>
	bool operator > (const pair<T1, T2>& pl, const pair<T1, T2>& pr) {
		return !(pl < pr);
	}

	template <typename T1, typename T2>
	bool operator >= (const pair<T1, T2>& pl, const pair<T1, T2>& pr) {
		return !(pl <= pr);
	}

	template <typename T1, typename T2>
	pair<T1,T2> make_pair(const T1 first, const T2 second) {
		return pair<T1,T2>{first, second};
	}
}
#endif

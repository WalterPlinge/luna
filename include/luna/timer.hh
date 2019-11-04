#pragma once

#include <chrono>

namespace luna
{

class
Timer
{
	using clock = std::chrono::high_resolution_clock;
	using point = clock::time_point;

	point start;

public:

	Timer(
		);

	auto
	reset(
		)
		-> void;

	auto
	elapsed(
		) const
		-> std::chrono::duration<float>;

	auto
	elapsed_seconds(
		) const
		-> float;
};

} // namespace luna

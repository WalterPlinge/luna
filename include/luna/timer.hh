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
		) :
		start(clock::now())
	{}

	auto
	reset(
		)
		-> void
	{
		start = clock::now();
	}

	auto
	elapsed(
		) const
		-> std::chrono::duration<float>
	{
		return clock::now() - start;
	}

	auto
	elapsed_seconds(
		) const
		-> float
	{
		return elapsed().count();
	}
};

} // namespace luna

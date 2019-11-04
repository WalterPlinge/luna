#include <luna/timer.hh>

using namespace std;

namespace luna
{

Timer::
Timer(
	) :
	start(clock::now())
{}

auto Timer::
reset(
	)
	-> void
{
	start = clock::now();
}

auto Timer::
elapsed(
	) const
	-> chrono::duration<float>
{
	return clock::now() - start;
}

auto Timer::
elapsed_seconds(
	) const
	-> float
{
	return elapsed().count();
}

} // namespace luna

#include <luna/strings.hh>

#include <algorithm>

using namespace std;

namespace luna
{

auto
string_tokens(
	string_view str,
	char const       d
	)
	-> vector<string_view>
{
	auto tok = vector<string_view>();
	tok.reserve(count(str.begin(), str.end(), d) + 1);
	for (auto l = 0ULL; l != str.npos; str = str.substr(l + 1, str.npos))
		if ((l = str.find(d)) && !str.empty())
			tok.push_back(str.substr(0, l));
	tok.shrink_to_fit();
	return tok;
}

} // namespace luna

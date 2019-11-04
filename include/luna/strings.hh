#pragma once

#include <algorithm>
#include <string_view>
#include <vector>

namespace luna
{

auto
string_tokens(
	std::string_view str,
	char const       d
	)
	-> std::vector<std::string_view>
{
	auto tok = std::vector<std::string_view>();
	tok.reserve(std::count(str.begin(), str.end(), d) + 1);
	for (auto l = 0ULL; l != str.npos; str = str.substr(l + 1, str.npos))
		if ((l = str.find(d)) && !str.empty())
			tok.push_back(str.substr(0, l));
	tok.shrink_to_fit();
	return tok;
}

} // namespace luna

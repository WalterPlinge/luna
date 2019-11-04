#pragma once

#include <string_view>
#include <vector>

namespace luna
{

auto
string_tokens(
	std::string_view str,
	char const       d
	)
	-> std::vector<std::string_view>;

} // namespace luna

#pragma once

#include <cctype>
#include <functional>
#include <string_view>
#include <vector>

namespace luna
{

auto
split_string(
	std::string_view          string,
	std::function<bool(char)> delim = (int(*)(int))std::isspace
	)
	-> std::vector<std::string_view>;

auto
split_string(
	std::string_view string,
	char             delim
	)
	-> std::vector<std::string_view>;

auto
split_string(
	std::string_view string,
	std::string_view delim
	)
	-> std::vector<std::string_view>;

auto
split_string_chars(
	std::string_view string,
	std::string_view delims
	)
	-> std::vector<std::string_view>;

} // namespace luna

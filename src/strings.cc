#include <luna/strings.hh>

#include <algorithm>

using namespace std;

namespace luna
{

auto
split_string(
	string_view          const string,
	function<bool(char)> const delim
	)
	-> vector<string_view>
{
	auto token_count = 0U;
	for (auto const c : string)
		if (delim(c))
			++token_count;
	auto tokens = vector<string_view>();
	tokens.reserve(token_count);
	for (auto a = 0UL, b = a; b < string.size(); ++b)
	{
		if (delim(string[b]))
		{
			if (a < b)
				tokens.push_back(string.substr(a, b - a));
			a = b + 1;
		}
	}
	tokens.shrink_to_fit();
	return tokens;
}

auto
split_string(
	string_view const string,
	char        const delim
	)
	-> vector<string_view>
{
	return split_string(string, [delim](
		char const& c
		)
		-> bool
	{
		return c == delim;
	});

	/* LEGACY CODE (stays because it's neat)
	// Count delims
	auto s      = string;
	auto tokens = vector<string_view>();
	tokens.reserve(count(s.begin(), s.end(), delim) + 1);

	// Find tokens
	for (auto i = 0UL; (i = s.find(delim)) != s.npos; s = s.substr(i + 1))
		if (i && !s.empty())
			tokens.push_back(s.substr(0, i));
	tokens.shrink_to_fit();
	return tokens;
	*/
}

auto
split_string(
	string_view const string,
	string_view const delim
	)
	-> vector<string_view>
{
	// Count delims
	auto s           = string;
	auto token_count = 0U;
	for (auto i = 0UL; (i = s.find(delim)) != s.npos; s = s.substr(i + delim.size()))
		if (i && !s.empty())
			++token_count;

	// Find tokens
	s           = string;
	auto tokens = vector<string_view>();
	tokens.reserve(token_count + 1);
	for (auto i = 0ULL; (i = s.find(delim)) != s.npos; s = s.substr(i + delim.size()))
		if (i && !s.empty())
			tokens.push_back(s.substr(0, i));
	tokens.shrink_to_fit();
	return tokens;
}

auto
split_string_chars(
	string_view const string,
	string_view const delims
	)
	-> vector<string_view>
{
	return split_string(string, [delims](
		char const& c
		)
		-> bool
	{
		return delims.find(c) != delims.npos;
	});

	/* LEGACY CODE (you can't tell me it's not neat)
	// Return the closest delim
	auto const static min_find = [delims](
		string_view const& s
		)
		-> size_t
	{
		auto l = s.npos;
		for (auto const c : delims)
			if (auto f = s.find(c); f < l)
				l = f;
		return l;
	};

	// Count delims
	auto token_count = 0UL;
	for (auto const c : delims)
		token_count += count(string.begin(), string.end(), c);

	// Find tokens
	auto s = string;
	auto tokens = vector<string_view>();
	tokens.reserve(token_count + 1);
	for (auto pos = 0ULL; (pos = min_find(s)) != s.npos; s = s.substr(pos + 1))
		if (pos && !s.empty())
			tokens.push_back(s.substr(0, pos));
	tokens.shrink_to_fit();
	return tokens;
	*/
}

} // namespace luna

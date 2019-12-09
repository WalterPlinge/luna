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
	auto token_count = 0ULL;
	for (auto a = 0ULL, b = a; b <= string.size(); ++b)
	{
		if (b == string.size() || delim(string[b]))
		{
			if (b > a)
			{
				++token_count;
			}
			a = b + 1;
		}
	}
	auto tokens = vector<string_view>();
	tokens.reserve(token_count);
	for (auto a = 0ULL, b = a; b <= string.size(); ++b)
	{
		if (b == string.size() || delim(string[b]))
		{
			if (b > a)
			{
				tokens.push_back(string.substr(a, b - a));
			}
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
		char const c
		)
		-> bool
	{
		return c == delim;
	});
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
	auto token_count = 0ULL;
	for (auto i = 0ULL; !s.empty(); s = s.substr(i == s.npos ? s.size() : i + delim.size()))
	{
		if ((i = s.find(delim)))
		{
			++token_count;
		}
	}

	// Find tokens
	s           = string;
	auto tokens = vector<string_view>();
	tokens.reserve(token_count);
	for (auto i = 0ULL; !s.empty(); s = s.substr(i == s.npos ? s.size() : i + delim.size()))
	{
		if ((i = s.find(delim)))
		{
			tokens.push_back(s.substr(0, i));
		}
	}
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
	return split_string(string, [&delims](
		char const c
		)
		-> bool
	{
		return delims.find(c) != delims.npos;
	});
}

} // namespace luna

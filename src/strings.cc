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
	auto token_count = count_if(string.begin(), string.end(), delim) + 1;
	auto tokens      = vector<string_view>{};
	tokens.reserve(token_count);
	for (auto a = size_t{0}, b = a; b <= string.size(); ++b)
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
		char const& c
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
	auto token_count = size_t{1};
	for (auto i = size_t{0}; !s.empty(); s = s.substr(i == s.npos ? s.size() : i + delim.size()))
	{
		if ((i = s.find(delim)))
		{
			++token_count;
		}
	}

	// Find tokens
	s           = string;
	auto tokens = vector<string_view>{};
	tokens.reserve(token_count);
	for (auto i = size_t{0}; !s.empty(); s = s.substr(i == s.npos ? s.size() : i + delim.size()))
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
	return split_string(string, [delims](
		char c
		)
		-> bool
	{
			return delims.find(c) != delims.npos;
	});
}

} // namespace luna

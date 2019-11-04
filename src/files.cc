#include <luna/files.hh>

#include <fstream>

using namespace std;

namespace luna
{

auto
read_file(
	string_view filename
	)
	-> optional<string>
{
	auto file = ifstream(filename.data());
	if (!file.good())
		return nullopt;
	return string(istreambuf_iterator<char>(file), {});
}

auto
write_file(
	string_view content,
	string_view filename
	)
	-> bool
{
	auto file = ofstream(filename.data());
	if (!file.good())
		return false;
	file << content;
	return true;
}

} // namespace luna

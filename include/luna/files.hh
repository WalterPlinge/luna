#pragma once

#include <fstream>
#include <optional>
#include <string_view>

namespace luna
{

auto
read_file(
	std::string_view filename
	)
	-> std::optional<std::string>
{
	auto file = std::ifstream(filename.data());
	if (!file.good())
		return std::nullopt;
	return std::string(std::istreambuf_iterator<char>(file), {});
}

auto
write_file(
	std::string_view content,
	std::string_view filename
	)
	-> bool
{
	auto file = std::ofstream(filename.data());
	if (!file.good())
		return false;
	file << content;
	return true;
}

} // namespace luna

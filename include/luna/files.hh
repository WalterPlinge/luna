#pragma once

#include <optional>
#include <string_view>

namespace luna
{

auto
read_file(
	std::string_view filename
	)
	-> std::optional<std::string>;

auto
write_file(
	std::string_view content,
	std::string_view filename
	)
	-> bool;

} // namespace luna

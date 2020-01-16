#pragma once

#include <cstddef>
#include <cstdint>



#if defined LUNA_VARIABLE_DEFINES

	#define var auto
	#define val auto const

#endif



namespace luna::types
{

using Bool  = bool;
using Byte  = std::uint_least8_t;
using Int   = long long int;
using UInt  = unsigned long long int;
using Size  = std::size_t;
using Ptr   = std::ptrdiff_t;

using Float =
#if defined LUNA_LONG_DOUBLE
	long double;
#elif defined LUNA_DOUBLE
	double;
#else
	float;
#endif

using Char =
#if defined LUNA_WIDE_CHARS
	wchar_t;
#else
	char;
#endif



#if defined LUNA_SIZED_TYPES || defined LUNA_FAST_TYPES || defined LUNA_LEAST_TYPES

	using f32 = float;
	using f64 = double;
	using f80 = long double;

	#if defined LUNA_FAST_TYPES

		using i8  = std::int_fast8_t;
		using i16 = std::int_fast16_t;
		using i32 = std::int_fast32_t;
		using i64 = std::int_fast64_t;

		using u8  = std::uint_fast8_t;
		using u16 = std::uint_fast16_t;
		using u32 = std::uint_fast32_t;
		using u64 = std::uint_fast64_t;

	#elif defined LUNA_LEAST_TYPES

		using i8  = std::int_least8_t;
		using i16 = std::int_least16_t;
		using i32 = std::int_least32_t;
		using i64 = std::int_least64_t;

		using u8  = std::uint_least8_t;
		using u16 = std::uint_least16_t;
		using u32 = std::uint_least32_t;
		using u64 = std::uint_least64_t;

	#else

		using i8  = std::int8_t;
		using i16 = std::int16_t;
		using i32 = std::int32_t;
		using i64 = std::int64_t;

		using u8  = std::uint8_t;
		using u16 = std::uint16_t;
		using u32 = std::uint32_t;
		using u64 = std::uint64_t;

	#endif

#endif

} // namespace luna::types



namespace luna::types::literals
{

Bool  operator "" _bool (UInt);
Byte  operator "" _byte (UInt);
Int   operator "" _int  (UInt);
UInt  operator "" _uint (UInt);
Size  operator "" _size (UInt);
Ptr   operator "" _ptr  (UInt);
Float operator "" _float(long double);



#if defined LUNA_SIZED_TYPES

	f32 operator "" _f32(long double);
	f64 operator "" _f64(long double);
	f80 operator "" _f80(long double);

	i8  operator "" _i8 (UInt);
	i16 operator "" _i16(UInt);
	i32 operator "" _i32(UInt);
	i64 operator "" _i64(UInt);

	u8  operator "" _u8 (UInt);
	u16 operator "" _u16(UInt);
	u32 operator "" _u32(UInt);
	u64 operator "" _u64(UInt);

#endif

} // namespace luna::type_literals

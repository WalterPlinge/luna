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

inline Bool  operator "" _bool (UInt        x) { return Bool (x); }
inline Byte  operator "" _byte (UInt        x) { return Byte (x); }
inline Int   operator "" _int  (UInt        x) { return Int  (x); }
inline UInt  operator "" _uint (UInt        x) { return UInt (x); }
inline Size  operator "" _size (UInt        x) { return Size (x); }
inline Ptr   operator "" _ptr  (UInt        x) { return Ptr  (x); }
inline Float operator "" _float(long double x) { return Float(x); }



#if defined LUNA_SIZED_TYPES || defined LUNA_FAST_TYPES || defined LUNA_LEAST_TYPES

	inline f32 operator "" _f32(long double x) { return f32(x); };
	inline f64 operator "" _f64(long double x) { return f64(x); };
	inline f80 operator "" _f80(long double x) { return f80(x); };

	i8  operator "" _i8 (UInt x) { return i8 (x); };
	i16 operator "" _i16(UInt x) { return i16(x); };
	i32 operator "" _i32(UInt x) { return i32(x); };
	i64 operator "" _i64(UInt x) { return i64(x); };

	u8  operator "" _u8 (UInt x) { return u8 (x); };
	u16 operator "" _u16(UInt x) { return u16(x); };
	u32 operator "" _u32(UInt x) { return u32(x); };
	u64 operator "" _u64(UInt x) { return u64(x); };

#endif

} // namespace luna::type_literals

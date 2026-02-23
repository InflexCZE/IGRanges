// Copyright Ian Good

#pragma once

#include <ranges>

#include "IGRanges/Impl/Prologue.inl"

namespace IG::Ranges
{

/**
* Bypasses a specified number of elements in a sequence and then returns the remaining elements.
*
* Alias for `std::views::drop`:
*
* @usage
* SomeNumbers | Skip(N)
*/
[[nodiscard]] constexpr auto Skip(int count)
{
	return std::views::drop(count);
}

} // namespace IG::Ranges

#include "IGRanges/Impl/Epilogue.inl"
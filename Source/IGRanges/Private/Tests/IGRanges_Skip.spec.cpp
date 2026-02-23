#include "IGRanges/Skip.h"
#include "IGRanges/ToArray.h"
#include "IGRangesInternal.h"
#include "IGRanges.h"
#include "Misc/AutomationTest.h"
#include <functional>

using namespace IG::Ranges;

BEGIN_DEFINE_SPEC(FIGRangesSkipSpec, "IG.Ranges.Skip",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)
END_DEFINE_SPEC(FIGRangesSkipSpec)

void FIGRangesSkipSpec::Define()
{
	Describe("Skip", [this]
	{
		It("skips N elements and returns the rest", [this]
		{
			TArray<int32> Input = { 0, 1, 2, 3, 4 };
			TArray<int32> Result = Input | Skip(2) | ToArray();
			TestEqual("Count", Result.Num(), 3);
			TestEqual("[0]", Result[0], 2);
			TestEqual("[1]", Result[1], 3);
			TestEqual("[2]", Result[2], 4);
		});

		It("returns empty when skipping all elements", [this]
		{
			TArray<int32> Input = { 0, 1, 2 };
			TArray<int32> Result = Input | Skip(3) | ToArray();
			TestEqual("Count", Result.Num(), 0);
		});
		
		It("returns empty when skipping more elements", [this]
		{
			TArray<int32> Input = { 0, 1, 2 };
			TArray<int32> Result = Input | Skip(5) | ToArray();
			TestEqual("Count", Result.Num(), 0);
		});

		It("returns all elements when skipping zero", [this]
		{
			TArray<int32> Input = { 0, 1, 2 };
			TArray<int32> Result = Input | Skip(0) | ToArray();
			TestEqual("Count", Result.Num(), 3);
		});
	});
}
#include <gtest/gtest.h>

#include "ArgumentsParser.h"

TEST(ArgumentsParserTests, SortingArgument)
{
	ArgumentsParser noSortingArg({});
	EXPECT_EQ(Sorting::Ascending, noSortingArg.getSorting());

	ArgumentsParser descSortingArg(std::vector<std::wstring>({L"--sorting:desc"}));
	EXPECT_EQ(Sorting::Descending, descSortingArg.getSorting());

	ArgumentsParser emptySortingArg(std::vector<std::wstring>({ L"--sorting:" }));
	EXPECT_EQ(Sorting::Ascending, emptySortingArg.getSorting());

	ArgumentsParser anySortingArg(std::vector<std::wstring>({ L"--sorting:whatever" }));
	EXPECT_EQ(Sorting::Ascending, anySortingArg.getSorting());
}

TEST(ArgumentsParserTests, RemoveDuplicatesArgument)
{
	ArgumentsParser noArg({});
	EXPECT_FALSE(noArg.getRemoveDuplicates());

	ArgumentsParser removeArg(std::vector<std::wstring>({ L"--remove-duplicates" }));
	EXPECT_TRUE(removeArg.getRemoveDuplicates());
}

TEST(ArgumentsParserTests, InputFileArgument)
{
	ArgumentsParser noArg({});
	EXPECT_STREQ(L"input.txt", noArg.getInputFile().wstring().c_str());

	ArgumentsParser removeArg(std::vector<std::wstring>({ L"--input:input_file" }));
	EXPECT_STREQ(L"input_file", removeArg.getInputFile().wstring().c_str());
}

TEST(ArgumentsParserTests, OutputFileArgument)
{
	ArgumentsParser noArg({});
	EXPECT_STREQ(L"output.txt", noArg.getOutputFile().wstring().c_str());

	ArgumentsParser removeArg(std::vector<std::wstring>({ L"--output:output_file" }));
	EXPECT_STREQ(L"output_file", removeArg.getOutputFile().wstring().c_str());
}
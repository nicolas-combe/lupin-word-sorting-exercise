// lupin-word-sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "ArgumentsParser.h"
#include "WordsCatalog.h"

int wmain(int in_argc, wchar_t* in_argv[])
{
	std::vector<std::wstring> arguments;
	for (int a = 1; a < in_argc; ++a)
	{
		arguments.push_back(std::wstring(in_argv[a]));
	}

	ArgumentsParser processArguments(arguments);
	std::wcout << L"processing " << processArguments.getInputFile() << L" --> " << processArguments.getOutputFile()
		<< L":" << L"sorting " << (processArguments.getSorting() == Sorting::Ascending ? L"Ascending" : L"Descending")
		<< L", " << L"remove duplicates " << std::to_wstring(processArguments.getRemoveDuplicates()) << std::endl;

	// load input file
	std::wifstream inputStream(processArguments.getInputFile());
	if (inputStream.good() == false)
	{
		std::wcout << L"Bad input file!" << std::endl;
		return -1;
	}
	std::wstring data((std::istreambuf_iterator<wchar_t>(inputStream)), std::istreambuf_iterator<wchar_t>());
	WordsCatalog catalog(data);
	auto const output = catalog.process(processArguments);

	std::wofstream outputStream(processArguments.getOutputFile());
	if (outputStream.good() == false)
	{
		std::wcout << L"Bad output file!" << std::endl;
		return -1;
	}
	std::for_each(output.begin(), output.end(), [&outputStream](auto const& in_word) { outputStream << in_word << std::endl; });
}


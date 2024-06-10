#pragma once

#include <filesystem>
#include <string>

//! @brief sorting order enum
enum Sorting
{
	Ascending = 0,
	Descending = 1
};

//! @brief parse arguments to get values for processing
class ArgumentsParser
{
public:
	ArgumentsParser(std::vector<std::wstring> const& in_args)
	{
		std::for_each(in_args.begin(), in_args.end(), [this](std::wstring const& in_arg)
			{
				auto posDelimiter = in_arg.find(L':');
				if (posDelimiter == std::wstring::npos)
				{
					posDelimiter = in_arg.length();
				}
				if (posDelimiter <= in_arg.length())
				{
					auto command = posDelimiter == in_arg.length() ? in_arg : in_arg.substr(0, posDelimiter);
					auto value = posDelimiter == in_arg.length() ? L"" : in_arg.substr(posDelimiter + 1, in_arg.length() - (posDelimiter + 1));
					if (command == L"--sorting")
					{
						if (value == L"desc")
						{
							m_sorting = Sorting::Descending;
						}
					}
					else if (command == L"--remove-duplicates")
					{
						m_removeDuplicates = true;
					}
					else if (command == L"--input")
					{
						if (value.length() > 0)
						{
							m_inputFile = std::filesystem::path(value);
						}
					}
					else if (command == L"--output")
					{
						if (value.length() > 0)
						{
							m_outputFile = std::filesystem::path(value);
						}
					}
				}
			});
	}


	Sorting getSorting() const { return m_sorting; }

	bool getRemoveDuplicates() const { return m_removeDuplicates; }

	std::filesystem::path const& getInputFile() const { return m_inputFile; }

	std::filesystem::path getOutputFile() const { return m_outputFile; }

private:
	Sorting m_sorting = Sorting::Ascending;
	std::filesystem::path m_inputFile = L"input.txt";
	std::filesystem::path m_outputFile = L"output.txt";
	bool m_removeDuplicates = false;
};
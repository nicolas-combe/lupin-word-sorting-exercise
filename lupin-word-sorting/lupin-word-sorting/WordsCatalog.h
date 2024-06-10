#pragma once

#include <cwctype>
#include <list>
#include <memory>
#include <string>

//! @brief parse an input text to get list of words
class WordsCatalog
{
public:
	//! @brief ctor
	//! @param in_text input text
	WordsCatalog(std::wstring const& in_text)
		: m_inputText(in_text)
	{}

	//! @brief get input text
	std::wstring const getInputText() const { return m_inputText; }

	//! @brief get the whole list of words
	std::list<std::wstring> const& getList()
	{
		if (m_words == nullptr)
		{
			computeWordsList();
		}
		return *m_words;
	}

	//! @brief check if character is allowed
	//! @param in_c input character
	//! @return true if allowed, false otherwise
	static inline bool isAllowed(wchar_t in_c)
	{
		return std::iswalnum(in_c);
	}

private:

	//! @brief computes the whole list of words from input text
	void computeWordsList()
	{
		std::list<std::wstring> words;

		// search the first allowed character
		auto itStart = std::find_if(m_inputText.begin(), m_inputText.end(), [](wchar_t const& in_c) { return isAllowed(in_c); });
		while (itStart != m_inputText.end())
		{
			// search the next not allowed character
			auto itNext = std::find_if(itStart + 1, m_inputText.end(), [](wchar_t const& in_c) { return isAllowed(in_c) == false; });
			words.push_back(std::wstring(itStart, itNext));
			if (itNext == m_inputText.end())
			{
				break;
			}

			itStart = std::find_if(itNext + 1, m_inputText.end(), [](wchar_t const& in_c) { return isAllowed(in_c); });
		}
		m_words.reset(new std::list<std::wstring>(words.begin(), words.end()));
	}

private:
	//! @brief input text
	std::wstring const m_inputText;
	//! @brief list of all words
	std::unique_ptr<std::list<std::wstring>> m_words;
};
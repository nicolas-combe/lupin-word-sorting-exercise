#include <gtest/gtest.h>
#include <algorithm>

#include "WordsCatalog.h"

class WordsCatalogTests : public testing::Test
{
public:
	WordsCatalogTests() = default;
	virtual ~WordsCatalogTests() = default;

protected:
	std::wstring m_inputText = L"Cet exercice servira aussi de base pour la discussion � venir mardi prochain.\n" \
								L"L�exercice est le suivant.Il s�agit de cr�er une petite application capable de :\n" \
								L"\tRecevoir(ou lire) une liste de mots en entr�e\n" \
								L"\tLes trier par ordre croissant ou d�croissant, en fonction d�une option donn�e en argument\n" \
								L"\tSi une autre option est sp�cifi�e, l�application supprime alors les valeurs qui apparaissent plusieurs fois\n" \
								L"\tEnfin, afficher(ou sauvegarder) le r�sultat tri�, avec ou sans suppression des doublons comme demand�";
};

TEST_F(WordsCatalogTests, CanLoadListFromText)
{
	WordsCatalog words(m_inputText);
	EXPECT_STREQ(m_inputText.c_str(), words.getInputText().c_str());
}

TEST_F(WordsCatalogTests, SpaceIsNotAllowedCharacter)
{
	EXPECT_FALSE(WordsCatalog::isAllowed(L' '));
}

TEST_F(WordsCatalogTests, LoadAlphaNumericWords)
{
	WordsCatalog catalog(m_inputText);
	
	EXPECT_NE(0, catalog.getList().size());

	auto const& words = catalog.getList();

	std::for_each(words.begin(), words.end(), [](auto const& in_word) { std::wcout << in_word << std::endl; });

	std::list<std::wstring> not_words; 
	std::copy_if(words.begin(), words.end(), not_words.end(), [](std::wstring const& in_word)
		{
			// check if in_word contains only alphanumeric, no space and not empty
			return in_word.length() == 0 ||
				std::find_if(in_word.begin(), in_word.end(), [](wchar_t const& in_c) {
								return WordsCatalog::isAllowed(in_c) == false;
				}) != in_word.end();
		});

	EXPECT_EQ(0, not_words.size());
}
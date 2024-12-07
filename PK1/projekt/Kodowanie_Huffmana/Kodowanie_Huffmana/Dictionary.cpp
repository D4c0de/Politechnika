#include "Dictionary.h"

/**
 * @brief Constructor for Dictionary with specified size.
 * @param i Size of the dictionary.
 */
Dictionary::Dictionary(int i) :
    tab(i, DictionaryElement())
{
    for (int i = 0; i < tab.size(); i++)
    {
        tab[i].Character = i;
    }
}

/**
 * @brief Default constructor for Dictionary with size 255.
 */
Dictionary::Dictionary() :
    tab(255, DictionaryElement())
{
    for (int i = 0; i < tab.size(); i++)
    {
        tab[i].Character = i;
    }
}

/**
 * @brief Destructor for Dictionary.
 */
Dictionary::~Dictionary()
{
}

/**
 * @brief Decodes a given Huffman code to a character.
 * @param code Huffman code to decode.
 * @return Decoded character, or -1 if not found.
 */
char Dictionary::decode(std::string& code)
{
    for (size_t i = 0; i < tab.size(); i++)
    {
        if (tab[i].code == code) {
            return tab[i].Character;
        }
    }
    return -1;
}

/**
 * @brief Default constructor for DictionaryElement.
 */
DictionaryElement::DictionaryElement() :
    Quantity(0),
    code("")
{
}

/**
 * @brief Constructor for DictionaryElement with a pair of code and character.
 * @param p Pair of code and character.
 */
DictionaryElement::DictionaryElement(std::pair<std::string, char> p) :
    code(p.first),
    Character(p.second),
    Quantity(0)
{
}

/**
 * @brief Constructor for DictionaryElement with specified code and character.
 * @param c Code for the dictionary element.
 * @param ch Character for the dictionary element.
 */
DictionaryElement::DictionaryElement(std::string& c, char ch) :
    code(c),
    Character(ch),
    Quantity(0)
{
}

/**
 * @brief Destructor for DictionaryElement.
 */
DictionaryElement::~DictionaryElement()
{
}

/**
 * @brief Appends a given code to the existing code of the dictionary element.
 * @param code Code to append.
 */
void DictionaryElement::setCode(const std::string& code)
{
    this->code.append(code);
}

/**
 * @brief Sorts the dictionary based on the comparator and removes elements with Quantity equal to 0.
 */
void Dictionary::sort()
{
    std::sort(this->tab.begin(), this->tab.end(), this->comparator);
    for (int i = tab.size() - 1; i >= 0; i--)
    {
        if (tab[i].Quantity == 0) {
            tab.pop_back();
        }
        else
        {
            return;
        }
    }
}
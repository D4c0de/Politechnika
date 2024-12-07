#pragma once

#include <vector>
#include <string>
#include <algorithm>

/**
 * @struct DictionaryElement
 * @brief Represents an element in the Huffman coding dictionary.
 */
struct DictionaryElement
{
    std::string code; ///< Huffman code.
    int Quantity;     ///< Frequency or quantity of the character.
    char Character;   ///< Character represented by the code.

    /**
     * @brief Default constructor for DictionaryElement.
     */
    DictionaryElement();

    /**
     * @brief Constructor for DictionaryElement with a pair of code and character.
     * @param p Pair of code and character.
     */
    DictionaryElement(std::pair<std::string, char>);

    /**
     * @brief Constructor for DictionaryElement with specified code and character.
     * @param c Code for the dictionary element.
     * @param ch Character for the dictionary element.
     */
    DictionaryElement(std::string&, char);

    /**
     * @brief Destructor for DictionaryElement.
     */
    ~DictionaryElement();

    /**
     * @brief Post-increment operator for Quantity.
     * @param Unused parameter (int).
     * @return The previous value of Quantity.
     */
    int operator++(int)
    {
        int temp = Quantity;
        Quantity++;
        return temp;
    }

    /**
     * @brief Appends a given code to the existing code of the dictionary element.
     * @param newCode Code to append.
     */
    void setCode(const std::string& newCode);
};

/**
 * @class Dictionary
 * @brief Represents the Huffman coding dictionary.
 */
class Dictionary
{
private:
    /**
     * @brief Comparator function for sorting the dictionary based on Quantity in descending order.
     * @param a First DictionaryElement.
     * @param b Second DictionaryElement.
     * @return True if Quantity of a is greater than Quantity of b.
     */
    static bool comparator(const DictionaryElement& a, const DictionaryElement& b) {
        return a.Quantity > b.Quantity;
    }

public:
    /**
     * @brief Sorts the dictionary based on the comparator and removes elements with Quantity equal to 0.
     */
    void sort();

    std::vector<DictionaryElement> tab; ///< Vector representing the dictionary.

    /**
     * @brief Constructor for Dictionary with specified size.
     * @param i Size of the dictionary.
     */
    Dictionary(int);

    /**
     * @brief Default constructor for Dictionary with size 255.
     */
    Dictionary();

    /**
     * @brief Destructor for Dictionary.
     */
    ~Dictionary();

    /**
     * @brief Decodes a given Huffman code to a character.
     * @param code Huffman code to decode.
     * @return Decoded character, or -1 if not found.
     */
    char decode(std::string& code);
};
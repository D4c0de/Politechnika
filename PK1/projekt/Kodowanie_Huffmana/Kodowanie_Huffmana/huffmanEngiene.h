#pragma once
#include "FileIO.h"
#include "Dictionary.h"
#include "Graph.h"
#include <string>
#include <vector>

/**
 * @struct Engiene
 * @brief Represents the Huffman coding/decoding engine.
 */
struct Engiene
{
    /**
     * @brief Constructor for Engiene.
     * @param in Input file name.
     * @param out Output file name.
     * @param encode Flag indicating encoding operation.
     */
    Engiene(std::string in, std::string out, bool encode);

    /**
     * @brief Destructor for Engiene.
     */
    ~Engiene();

    FileIO* file; ///< Pointer to FileIO object.
    Dictionary* dictionary; ///< Pointer to Dictionary object.

    /**
     * @brief Counts the occurrences of characters in the input file and builds the frequency table.
     */
    void countChars();

    /**
     * @brief Sets the character code for a specific dictionary element.
     * @param id Index of the dictionary element.
     * @param code New character code to set.
     */
    void SetElement(int id, std::string& code);

    /**
     * @brief Retrieves the dictionary from the input file.
     */
    void GetDictionary();

    /**
     * @brief Decodes the input file using the Huffman coding.
     */
    void Decode();

    /**
     * @brief Writes the Huffman dictionary to the output file.
     */
    void writeDictionary();

    /**
     * @brief Encodes the input file using Huffman coding.
     */
    void code();
};
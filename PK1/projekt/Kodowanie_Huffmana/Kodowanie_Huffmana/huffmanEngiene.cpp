/**
 * @file HuffmanEngiene.cpp
 * @brief Implementation of the HuffmanEngiene class for Huffman coding/decoding.
 */

#include "HuffmanEngiene.h"


 /**
  * @brief Constructor for HuffmanEngiene.
  * @param in Input file name.
  * @param out Output file name.
  * @param encode Flag indicating encoding operation.
  */
Engiene::Engiene(std::string in, std::string out, bool encode)
    : file(new FileIO(in, out))
{
    if (encode)
    {
        dictionary = new Dictionary();
        countChars();
        dictionary->sort();
        graph g = graph(dictionary->tab);
        dictionary->tab = *g.dic;
        writeDictionary();
        file->resetFile(in);
        code();
    }
    else
    {
        dictionary = new Dictionary(0);
        GetDictionary();
        Decode();
    }
}

/**
 * @brief Counts the occurrences of characters in the input file and builds the frequency table.
 */
void Engiene::countChars()
{
        char c = file->getChar();
        while (c != -1)
        {
           
            dictionary->tab[c]++;
            c = file->getChar();
        }
}

/**
 * @brief Sets the character code for a specific dictionary element.
 * @param id Index of the dictionary element.
 * @param code New character code to set.
 */
void Engiene::SetElement(int id, std::string& code)
{
    dictionary->tab[id].setCode(code);
}

/**
 * @brief Retrieves the dictionary from the input file.
 */
void Engiene::GetDictionary()
{

    file->next = -1;
    std::pair<std::string, int> i = file->getDicElement();
    while (i.first != "end")
    {
        dictionary->tab.push_back(DictionaryElement(i));
        i = file->getDicElement();
    }
    return;
}

/**
 * @brief Decodes the input file using the Huffman coding.
 */
void Engiene::Decode()
{
    std::string code;
    while (file->getCode(&code))
    {
        char c = dictionary->decode(code);
        if (c != -1)
        {
            file->wr(c);
            code.clear();
        }
    }
}

/**
 * @brief Writes the Huffman dictionary to the output file.
 */
void Engiene::writeDictionary()
{
    std::string s;
    for (int i = 0; i < 255; i++)
    {
        if (!dictionary->tab[i].code.empty())
        {
            s.append(std::bitset<8>(i).to_string());
            int size = dictionary->tab[i].code.size();
            std::bitset<8> sizeBits(size - 1);
            s.append(sizeBits.to_string());
            s.append(dictionary->tab[i].code);
            file->wr(s);
            s.clear();
        }
    }
    s.append("11111111");
    file->wr(s);
    return;
}

/**
 * @brief Encodes the input file using Huffman coding.
 */
void Engiene::code()
{
    char c;
    while ((c = file->getChar()) != -1)
    {
        file->wr(dictionary->tab[c].code);
    }

}

/**
 * @brief Destructor for HuffmanEngiene.
 */
Engiene::~Engiene()
{
    delete dictionary;
    delete file;
}
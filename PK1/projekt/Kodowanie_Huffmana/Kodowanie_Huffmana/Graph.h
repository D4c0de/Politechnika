#pragma once
#include "Dictionary.h"
#include <vector>
#include <string>
#include <queue>

/**
 * @struct Node
 * @brief Represents a node in the Huffman tree.
 */
struct Node
{
    /**
     * @brief Default constructor for Node.
     */
    Node();

    /**
     * @brief Constructor for Node with specified value and character.
     * @param value Value or frequency of the node.
     * @param c Character represented by the node.
     */
    Node(int value, char);

    /**
     * @brief Destructor for Node.
     */
    ~Node();

    int value;           ///< Value or frequency of the node.
    Node* leftChild;     ///< Pointer to the left child node.
    Node* rightChild;    ///< Pointer to the right child node.
    char c;              ///< Character represented by the node.
};

/**
 * @class graph
 * @brief Represents the Huffman tree for encoding/decoding.
 */
class graph
{
public:
    /**
     * @brief Constructor for graph with a given vector of DictionaryElement.
     * @param tab Vector of DictionaryElement representing character frequencies.
     */
    graph(std::vector<DictionaryElement>&);

    /**
     * @brief Destructor for graph.
     */
    ~graph();

    /**
     * @brief Updates the dictionary with Huffman codes after tree initialization.
     */
    void updateDictionary();

    std::vector<DictionaryElement>* dic; ///< Pointer to the dictionary.

    /**
     * @brief Recursively traverses the Huffman tree and assigns Huffman codes to characters.
     * @param node Current node in the traversal.
     * @param code Huffman code built during traversal.
     */
    void req(Node* node, std::string* code);

private:
    /**
     * @brief Comparator function for sorting nodes based on value in descending order.
     * @param a First Node.
     * @param b Second Node.
     * @return True if value of a is greater than value of b.
     */
    static bool comparator(const Node& a, const Node& b) {
        return a.value > b.value;
    }

    Node firstNode;         ///< Root node of the Huffman tree.
    std::vector<Node> nodeTab; ///< Vector representing nodes for character frequencies.

    /**
     * @brief Initializes the Huffman tree based on the character frequencies in nodeTab.
     */
    void initialize();
};
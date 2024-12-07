#include "graph.h"

/**
 * @brief Default constructor for Node.
 */
Node::Node()
{
}

/**
 * @brief Constructor for Node with specified value and character.
 * @param value Value or frequency of the node.
 * @param c Character represented by the node.
 */
Node::Node(int value, char c) :
    value(value),
    c(c),
    leftChild(nullptr),
    rightChild(nullptr)
{
}

/**
 * @brief Destructor for Node.
 */
Node::~Node()
{
}

/**
 * @brief Constructor for graph with a given vector of DictionaryElement.
 * @param tab Vector of DictionaryElement representing character frequencies.
 */
graph::graph(std::vector<DictionaryElement>& tab)
{
    for (int i = 0; i < tab.size(); i++)
    {
        nodeTab.push_back(Node(tab[i].Quantity, tab[i].Character));
    }
    initialize();
    dic = new std::vector<DictionaryElement>(255);
    std::string* s = new std::string("");
    req(&firstNode, s);
    delete s;
}

/**
 * @brief Destructor for graph.
 */
graph::~graph()
{
    delete dic;
}

/**
 * @brief Recursively traverses the Huffman tree and assigns Huffman codes to characters.
 * @param node Current node in the traversal.
 * @param code Huffman code built during traversal.
 */
void graph::req(Node* node, std::string* code)
{
    bool t = true;
    if (node->leftChild != nullptr)
    {
        t = false;
        code->append("1");
        req(node->leftChild, code);
        code->pop_back();
    }
    if (node->rightChild != nullptr)
    {
        t = false;
        code->append("0");
        req(node->rightChild, code);
        code->pop_back();
    }
    if (t)
    {
        (*dic)[node->c].code = *code;
        (*dic)[node->c].Character = node->c;
    }
}

/**
 * @brief Initializes the Huffman tree based on the character frequencies in nodeTab.
 */
void graph::initialize()
{
    std::priority_queue<Node, std::vector<Node>, decltype(&comparator)> pq(comparator);

    // Populate the priority queue with nodes for each character frequency
    for (const auto& element : nodeTab)
    {
        pq.push(element);
    }
    Node* left;
    Node* right;
    // Build the Huffman tree
    while (pq.size() > 1)
    {
        // Extract two nodes with the lowest frequencies
        left = new Node(pq.top());
        pq.pop();
        right = new Node(pq.top());
        pq.pop();

        // Create a new internal node with the sum of their frequencies
        Node internalNode;
        internalNode.value = left->value + right->value;
        internalNode.leftChild = left;
        internalNode.rightChild = right;

        // Push the new internal node back into the priority queue
        pq.push(internalNode);
    }
    if (!pq.empty())
    {
        firstNode = pq.top();
    }
    else
    {
        throw std::exception("unknown error");
    }
}
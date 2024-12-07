/**
 * @file CommandLineInput.h
 * @brief Declaration of the CommandLineInput struct for handling command-line input.
 */

#pragma once

#include <exception>
#include <string>

 /**
  * @struct CommandLineInput
  * @brief Structure for handling command-line input parameters.
  */
struct CommandLineInput {
    std::string inputFileName; ///< Input file name.
    std::string outputFileName; ///< Output file name.
    bool encoding; ///< Flag indicating encoding operation.
    bool decoding; ///< Flag indicating decoding operation.

    /**
     * @brief Constructor for CommandLineInput, parses command-line arguments.
     * @param argc Number of command-line arguments.
     * @param argv Array of command-line argument strings.
     * @throw std::exception if there are missing or invalid options.
     */
    CommandLineInput(int argc, char* argv[]);
};

/**
 * @brief Constructor for CommandLineInput, parses command-line arguments.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @throw std::exception if there are missing or invalid options.
 */
inline CommandLineInput::CommandLineInput(int argc, char* argv[]) {
    encoding = false;
    decoding = false;
    if (argc < 2) {
        throw std::exception("Usage: -i input_file -o output_file -c for coding and/or -d for decoding");
    }

    // Processing command-line arguments
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-i") {
            if (i + 1 < argc) {
                inputFileName = argv[i + 1];
                ++i;
            }
            else {
                throw std::exception("Error: -i option requires the input file name.");
            }
        }
        else if (std::string(argv[i]) == "-o") {
            if (i + 1 < argc) {
                outputFileName = argv[i + 1];
                ++i;
            }
            else {
                throw std::exception("Error: -o option requires the output file name.");
            }
        }
        else if (std::string(argv[i]) == "-c") {
            encoding = true;
            ++i;
        }
        else if (std::string(argv[i]) == "-d") {
            decoding = true;
            ++i;
        }
    }

    // Check if all required options are provided
    if (inputFileName.empty() || outputFileName.empty() || (!decoding && !encoding)) {
        throw std::exception("Error: Missing required options.");
    }
    else {
        if (decoding && encoding) {
            throw std::exception("Error: You can't encode and decode at the same time.");
        }
    }
}
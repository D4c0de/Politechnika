#pragma once

#include <exception>
#include <string>
#include <vector>

struct CommandLineInput {
    std::string inputFileName;
    std::string outputFileName;
    // Konstruktor przyjmuj¹cy argumenty argc, argv
    CommandLineInput(int argc, char* argv[]);
};



inline CommandLineInput::CommandLineInput(int argc, char* argv[]) {
    if (argc < 2) {
        throw std::exception("-i input_file -o output_file <command> <value>");
    }

    // Przetwarzanie argumentów
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
    }

    // SprawdŸ, czy wszystkie wymagane opcje zosta³y podane
    if (inputFileName.empty() || outputFileName.empty()) {
        throw std::exception("Error: Missing required options.");
    }
}
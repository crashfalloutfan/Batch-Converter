#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string batchFilePath;
    std::string outputCppFile = "generated_program.cpp";

    // Ask user for the file path
    std::cout << "Please enter the file path to your batch file: ";
    std::getline(std::cin, batchFilePath);

    // Open the batch file to read its contents
    std::ifstream batchFile(batchFilePath);
    
    if (!batchFile.is_open()) {
        std::cerr << "Error: Could not open the batch file." << std::endl;
        return 1;
    }

    // Create a new C++ file to generate the code
    std::ofstream cppFile(outputCppFile);
    
    if (!cppFile.is_open()) {
        std::cerr << "Error: Could not create the C++ file." << std::endl;
        return 1;
    }

    std::cout << "Generating C++ file: " << outputCppFile << std::endl;

    // Write the content of the new C++ program
    cppFile << "#include <iostream>\n";
    cppFile << "#include <cstdlib>  // For system()\n\n";
    cppFile << "int main() {\n";
    
    std::string line;
    std::string combinedCommand;

    while (std::getline(batchFile, line)) {
        // Escape backslashes in the line to make sure the path works
        for (size_t pos = 0; pos < line.size(); ++pos) {
            if (line[pos] == '\\') {
                line.insert(pos, "\\");  // Add an extra backslash to escape it
                ++pos;  // Move past the escaped backslash
            }
        }

        // Escape double quotes within the line
        for (size_t pos = 0; pos < line.size(); ++pos) {
            if (line[pos] == '"') {
                line.insert(pos, "\\");  // Escape the double quote
                ++pos;
            }
        }

        // Append to combined command if this line is part of a `cd` or `start` command
        combinedCommand += line + " && ";  // Combine with '&&' so the commands are chained in one system() call
    }

    // Remove the last " && " from combinedCommand
    if (!combinedCommand.empty()) {
        combinedCommand = combinedCommand.substr(0, combinedCommand.size() - 4);
    }

    // Write the final system() call with the combined commands
    cppFile << "    system(\"" << combinedCommand << "\");\n";
    cppFile << "    return 0;\n";
    cppFile << "}\n";

    // Close the files
    batchFile.close();
    cppFile.close();

    std::cout << "C++ file has been generated successfully." << std::endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>

std::string convertBatchToCpp(const std::string& line) {
    std::unordered_map<std::string, std::string> commandMap = {
        {"ASSOC", "system(\"assoc\");"},
        {"ATTRIB", "system(\"attrib\");"},
        {"BREAK", "system(\"break\");"},
        {"BCDEDIT", "system(\"bcdedit\");"},
        {"CACLS", "system(\"cacls\");"},
        {"CALL", "system(\"call\");"},
        {"CD", "system(\"cd\");"},
        {"CHCP", "system(\"chcp\");"},
        {"CHDIR", "system(\"chdir\");"},
        {"CHKDSK", "system(\"chkdsk\");"},
        {"CHKNTFS", "system(\"chkntfs\");"},
        {"CLS", "system(\"cls\");"},
        {"CMD", "system(\"cmd\");"},
        {"COLOR", "system(\"color\");"},
        {"COMP", "system(\"comp\");"},
        {"COMPACT", "system(\"compact\");"},
        {"CONVERT", "system(\"convert\");"},
        {"COPY", "system(\"copy\");"},
        {"DATE", "system(\"date\");"},
        {"DEL", "system(\"del\");"},
        {"DIR", "system(\"dir\");"},
        {"DISKPART", "system(\"diskpart\");"},
        {"DOSKEY", "system(\"doskey\");"},
        {"DRIVERQUERY", "system(\"driverquery\");"},
        {"ECHO", "std::cout << \"<message>\" << std::endl;"},
        {"ENDLOCAL", "system(\"endlocal\");"},
        {"ERASE", "system(\"erase\");"},
        {"EXIT", "exit(0);"},
        {"FC", "system(\"fc\");"},
        {"FIND", "system(\"find\");"},
        {"FINDSTR", "system(\"findstr\");"},
        {"FOR", "system(\"for\");"},
        {"FORMAT", "system(\"format\");"},
        {"FSUTIL", "system(\"fsutil\");"},
        {"FTYPE", "system(\"ftype\");"},
        {"GOTO", "goto <label>;"},
        {"GPRESULT", "system(\"gpresult\");"},
        {"GRAFTABL", "system(\"graftabl\");"},
        {"HELP", "system(\"help\");"},
        {"ICACLS", "system(\"icacls\");"},
        {"IF", "if (condition) { /* command */ }"},
        {"LABEL", "system(\"label\");"},
        {"MD", "system(\"md\");"},
        {"MKDIR", "system(\"mkdir\");"},
        {"MKLINK", "system(\"mklink\");"},
        {"MODE", "system(\"mode\");"},
        {"MORE", "system(\"more\");"},
        {"MOVE", "system(\"move\");"},
        {"OPENFILES", "system(\"openfiles\");"},
        {"PATH", "system(\"path\");"},
        {"PAUSE", "system(\"pause\");"},
        {"POPD", "system(\"popd\");"},
        {"PRINT", "system(\"print\");"},
        {"PROMPT", "system(\"prompt\");"},
        {"PUSHD", "system(\"pushd\");"},
        {"RD", "system(\"rd\");"},
        {"RECOVER", "system(\"recover\");"},
        {"REM", "//"},
        {"REN", "system(\"ren\");"},
        {"RENAME", "system(\"rename\");"},
        {"REPLACE", "system(\"replace\");"},
        {"RMDIR", "system(\"rmdir\");"},
        {"ROBOCOPY", "system(\"robocopy\");"},
        {"SET", "system(\"set\");"},
        {"SETLOCAL", "system(\"setlocal\");"},
        {"SC", "system(\"sc\");"},
        {"SCHTASKS", "system(\"schtasks\");"},
        {"SHIFT", "system(\"shift\");"},
        {"SHUTDOWN", "system(\"shutdown\");"},
        {"SORT", "system(\"sort\");"},
        {"START", "system(\"start <application>\");"},
        {"SUBST", "system(\"subst\");"},
        {"SYSTEMINFO", "system(\"systeminfo\");"},
        {"TASKLIST", "system(\"tasklist\");"},
        {"TASKKILL", "system(\"taskkill\");"},
        {"TIME", "system(\"time\");"},
        {"TITLE", "system(\"title\");"},
        {"TREE", "system(\"tree\");"},
        {"TYPE", "system(\"type\");"},
        {"VER", "system(\"ver\");"},
        {"VERIFY", "system(\"verify\");"},
        {"VOL", "system(\"vol\");"},
        {"XCOPY", "system(\"xcopy\");"},
        {"WMIC", "system(\"wmic\");"},
    };

    std::string command = line;

    // Remove leading whitespace
    command.erase(0, command.find_first_not_of(" \t"));

    // Remove any leading "@" from the command
    if (command[0] == '@') {
        command.erase(0, 1);
    }

    // Split the command to separate the command word from its arguments
    std::istringstream iss(command);
    std::string commandWord;
    iss >> commandWord;

    // Convert the command word to uppercase for case insensitive matching
    std::transform(commandWord.begin(), commandWord.end(), commandWord.begin(), ::toupper);

    if (commandMap.find(commandWord) != commandMap.end()) {
        std::string args;
        std::getline(iss, args); // Get the rest of the line (arguments)
        return commandMap[commandWord] + args; // Append arguments if any
    } else {
        return "// Unknown command: " + line;
    }
}

int main() {
    std::string filepath;
    std::cout << "Enter the filepath of the batch file: ";
    std::getline(std::cin, filepath);

    std::ifstream batchFile(filepath);
    if (!batchFile.is_open()) {
        std::cerr << "Error: Unable to open the batch file. Please check the file path." << std::endl;
        std::cout << "Press Enter to exit...";
        std::cin.ignore();
        std::cin.get();
        return 1;
    }

    std::cout << "C++ Equivalent Code:" << std::endl;

    std::string line;
    while (std::getline(batchFile, line)) {
        std::cout << convertBatchToCpp(line) << std::endl;
    }

    batchFile.close();
    
    std::cout << "Conversion completed." << std::endl;
    std::cout << "Press Enter to exit...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}

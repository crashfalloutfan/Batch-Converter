#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <filesystem>


std::string translateBatchToCpp(const std::string& batchLine) {
    std::map<std::string, std::string> translations = {
        {"assoc", "system(\"assoc\");"},
        {"attrib", "system(\"attrib\");"},
        {"break", "system(\"break\");"},
        {"bcdedit", "system(\"bcdedit\");"},
        {"cacls", "system(\"cacls\");"},
        {"call", "system(\"call filename.bat\");"},
        {"cd", "std::filesystem::current_path();"},
        {"chcp", "system(\"chcp\");"},
        {"chdir", "std::filesystem::current_path();"},
        {"chkdsk", "system(\"chkdsk\");"},
        {"chkntfs", "system(\"chkntfs\");"},
        {"cls", "system(\"cls\");"},
        {"cmd", "system(\"cmd\");"},
        {"color", "system(\"color\");"},
        {"comp", "system(\"comp file1 file2\");"},
        {"compact", "system(\"compact\");"},
        {"convert", "system(\"convert\");"},
        {"copy", "system(\"copy source destination\");"},
        {"date", "system(\"date\");"},
        {"del", "std::remove(\"filename\");"},
        {"dir", "system(\"dir\");"},
        {"diskpart", "system(\"diskpart\");"},
        {"doskey", "system(\"doskey\");"},
        {"driverquery", "system(\"driverquery\");"},
        {"echo", "std::cout << "},
        {"endlocal", "system(\"endlocal\");"},
        {"erase", "std::remove(\"filename\");"},
        {"exit", "return 0;"},
        {"fc", "system(\"fc file1 file2\");"},
        {"find", "system(\"find string file\");"},
        {"findstr", "system(\"findstr string file\");"},
        {"for", "// Loop through files (use for loop in C++)"},
        {"format", "system(\"format drive:\");"},
        {"fsutil", "system(\"fsutil\");"},
        {"ftype", "system(\"ftype\");"},
        {"goto", "// Jump to label (not directly translatable)"},
        {"gpresult", "system(\"gpresult\");"},
        {"graftabl", "system(\"graftabl\");"},
        {"help", "system(\"help\");"},
        {"icacls", "system(\"icacls\");"},
        {"if", "// Conditional statement (use if in C++)"},
        {"label", "system(\"label\");"},
        {"md", "std::filesystem::create_directory(\"directory_name\");"},
        {"mkdir", "std::filesystem::create_directory(\"directory_name\");"},
        {"mklink", "system(\"mklink link target\");"},
        {"mode", "system(\"mode\");"},
        {"more", "system(\"more file\");"},
        {"move", "system(\"move source destination\");"},
        {"openfiles", "system(\"openfiles\");"},
        {"path", "system(\"path\");"},
        {"pause", "system(\"pause\");"},
        {"popd", "system(\"popd\");"},
        {"print", "system(\"print filename\");"},
        {"prompt", "system(\"prompt\");"},
        {"pushd", "system(\"pushd directory\");"},
        {"rd", "std::filesystem::remove(\"directory_name\");"},
        {"recover", "system(\"recover\");"},
        {"rem", "//"},
        {"ren", "std::rename(\"oldname\", \"newname\");"},
        {"rename", "std::rename(\"oldname\", \"newname\");"},
        {"replace", "system(\"replace file1 file2\");"},
        {"rmdir", "std::filesystem::remove(\"directory_name\");"},
        {"robocopy", "system(\"robocopy\");"},
        {"set", "std::string "},
        {"setlocal", "system(\"setlocal\");"},
        {"sc", "system(\"sc\");"},
        {"schtasks", "system(\"schtasks\");"},
        {"shift", "system(\"shift\");"},
        {"shutdown", "system(\"shutdown\");"},
        {"sort", "system(\"sort\");"},
        {"start", "system(\"start command\");"},
        {"subst", "system(\"subst\");"},
        {"systeminfo", "system(\"systeminfo\");"},
        {"tasklist", "system(\"tasklist\");"},
        {"taskkill", "system(\"taskkill\");"},
        {"time", "system(\"time\");"},
        {"title", "system(\"title\");"},
        {"tree", "system(\"tree\");"},
        {"type", "std::ifstream file(\"filename\"); while (std::getline(file, line)) std::cout << line << std::endl;"},
        {"ver", "system(\"ver\");"},
        {"verify", "system(\"verify\");"},
        {"vol", "system(\"vol\");"},
        {"xcopy", "system(\"xcopy\");"},
        {"wmic", "system(\"wmic\");"}
    };

    std::string cppLine;
    std::istringstream iss(batchLine);
    std::string command;
    iss >> command;

    if (translations.find(command) != translations.end()) {
        cppLine = translations[command];

        if (command == "echo") {
            std::string message = batchLine.substr(5);
            cppLine += "\"" + message + "\";\n";
        } else if (command == "set") {
            cppLine += batchLine.substr(4) + ";\n";
        } else if (command == "md" || command == "mkdir") {
            std::string dirName = batchLine.substr(3);
            cppLine += "std::filesystem::create_directory(\"" + dirName + "\");\n";
        } else if (command == "rd" || command == "rmdir") {
            std::string dirName = batchLine.substr(3);
            cppLine += "std::filesystem::remove(\"" + dirName + "\");\n";
        } else {
            cppLine += ";\n";
        }
    } else {
        cppLine = "// Unrecognized command: " + batchLine + "\n";
    }

    return cppLine;
}

int main() {
    std::string filepath;

    std::cout << "Enter the filepath of the batch file: ";
    std::getline(std::cin, filepath);

    if (!std::filesystem::exists(filepath)) {
        std::cerr << "Error: File does not exist at path: " << filepath << std::endl;
        return 1;
    }

    std::ifstream batchFile(filepath);
    if (!batchFile) {
        std::cerr << "Error: Unable to open file at path: " << filepath << std::endl;
        return 1;
    }

    std::string batchLine;
    std::cout << "\nC++ Equivalent Code:\n";

    while (std::getline(batchFile, batchLine)) {
        std::string cppLine = translateBatchToCpp(batchLine);
        std::cout << cppLine;
    }

    batchFile.close();
    return 0;
}

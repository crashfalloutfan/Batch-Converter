#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string convertBatchToCpp(const std::string& batchCommand) {
    // Handle batch commands and return corresponding C++ comments
    if (batchCommand == "ASSOC") {
        return "// Displays or modifies file extension associations.";
    } else if (batchCommand == "ATTRIB") {
        return "// Displays or changes file attributes.";
    } else if (batchCommand == "BREAK") {
        return "// Sets or clears extended CTRL+C checking.";
    } else if (batchCommand == "BCDEDIT") {
        return "// Sets properties in boot database to control boot loading.";
    } else if (batchCommand == "CACLS") {
        return "// Displays or modifies access control lists (ACLs) of files.";
    } else if (batchCommand == "CALL") {
        return "// Calls one batch program from another.";
    } else if (batchCommand == "CD") {
        return "// Displays the name of or changes the current directory.";
    } else if (batchCommand == "CHCP") {
        return "// Displays or sets the active code page number.";
    } else if (batchCommand == "CHDIR") {
        return "// Displays the name of or changes the current directory.";
    } else if (batchCommand == "CHKDSK") {
        return "// Checks a disk and displays a status report.";
    } else if (batchCommand == "CHKNTFS") {
        return "// Displays or modifies the checking of disk at boot time.";
    } else if (batchCommand == "CLS") {
        return "// Clears the screen.";
    } else if (batchCommand == "CMD") {
        return "// Starts a new instance of the Windows command interpreter.";
    } else if (batchCommand == "COLOR") {
        return "// Sets the default console foreground and background colors.";
    } else if (batchCommand == "COMP") {
        return "// Compares the contents of two files or sets of files.";
    } else if (batchCommand == "COMPACT") {
        return "// Displays or alters the compression of files on NTFS partitions.";
    } else if (batchCommand == "CONVERT") {
        return "// Converts FAT volumes to NTFS. You cannot convert the current drive.";
    } else if (batchCommand == "COPY") {
        return "// Copies one or more files to another location.";
    } else if (batchCommand == "DATE") {
        return "// Displays or sets the date.";
    } else if (batchCommand == "DEL") {
        return "// Deletes one or more files.";
    } else if (batchCommand == "DIR") {
        return "// Displays a list of files and subdirectories in a directory.";
    } else if (batchCommand == "DISKPART") {
        return "// Displays or configures Disk Partition properties.";
    } else if (batchCommand == "DOSKEY") {
        return "// Edits command lines, recalls Windows commands, and creates macros.";
    } else if (batchCommand == "DRIVERQUERY") {
        return "// Displays current device driver status and properties.";
    } else if (batchCommand == "ECHO") {
        return "// Displays messages, or turns command echoing on or off.";
    } else if (batchCommand == "ENDLOCAL") {
        return "// Ends localization of environment changes in a batch file.";
    } else if (batchCommand == "ERASE") {
        return "// Deletes one or more files.";
    } else if (batchCommand == "EXIT") {
        return "// Quits the CMD.EXE program (command interpreter).";
    } else if (batchCommand == "FC") {
        return "// Compares two files or sets of files, and displays the differences between them.";
    } else if (batchCommand == "FIND") {
        return "// Searches for a text string in a file or files.";
    } else if (batchCommand == "FINDSTR") {
        return "// Searches for strings in files.";
    } else if (batchCommand == "FOR") {
        return "// Runs a specified command for each file in a set of files.";
    } else if (batchCommand == "FORMAT") {
        return "// Formats a disk for use with Windows.";
    } else if (batchCommand == "FSUTIL") {
        return "// Displays or configures the file system properties.";
    } else if (batchCommand == "FTYPE") {
        return "// Displays or modifies file types used in file extension associations.";
    } else if (batchCommand == "GOTO") {
        return "// Directs the Windows command interpreter to a labeled line in a batch program.";
    } else if (batchCommand == "GPRESULT") {
        return "// Displays Group Policy information for machine or user.";
    } else if (batchCommand == "GRAFTABL") {
        return "// Enables Windows to display an extended character set in graphics mode.";
    } else if (batchCommand == "HELP") {
        return "// Provides Help information for Windows commands.";
    } else if (batchCommand == "ICACLS") {
        return "// Display, modify, backup, or restore ACLs for files and directories.";
    } else if (batchCommand == "IF") {
        return "// Performs conditional processing in batch programs.";
    } else if (batchCommand == "LABEL") {
        return "// Creates, changes, or deletes the volume label of a disk.";
    } else if (batchCommand == "MD") {
        return "// Creates a directory.";
    } else if (batchCommand == "MKDIR") {
        return "// Creates a directory.";
    } else if (batchCommand == "MKLINK") {
        return "// Creates Symbolic Links and Hard Links.";
    } else if (batchCommand == "MODE") {
        return "// Configures a system device.";
    } else if (batchCommand == "MORE") {
        return "// Displays output one screen at a time.";
    } else if (batchCommand == "MOVE") {
        return "// Moves one or more files from one directory to another.";
    } else if (batchCommand == "OPENFILES") {
        return "// Displays files opened by remote users for a file share.";
    } else if (batchCommand == "PATH") {
        return "// Displays or sets a search path for executable files.";
    } else if (batchCommand == "PAUSE") {
        return "// Suspends processing of a batch file and displays a message.";
    } else if (batchCommand == "POPD") {
        return "// Restores the previous value of the current directory saved by PUSHD.";
    } else if (batchCommand == "PRINT") {
        return "// Prints a text file.";
    } else if (batchCommand == "PROMPT") {
        return "// Changes the Windows command prompt.";
    } else if (batchCommand == "PUSHD") {
        return "// Saves the current directory then changes it.";
    } else if (batchCommand == "RD") {
        return "// Removes a directory.";
    } else if (batchCommand == "RECOVER") {
        return "// Recovers readable information from a bad or defective disk.";
    } else if (batchCommand == "REM") {
        return "// Records comments (remarks) in batch files or CONFIG.SYS.";
    } else if (batchCommand == "REN") {
        return "// Renames a file or files.";
    } else if (batchCommand == "RENAME") {
        return "// Renames a file or files.";
    } else if (batchCommand == "REPLACE") {
        return "// Replaces files.";
    } else if (batchCommand == "RMDIR") {
        return "// Removes a directory.";
    } else if (batchCommand == "ROBOCOPY") {
        return "// Advanced utility to copy files and directory trees.";
    } else if (batchCommand == "SET") {
        return "// Displays, sets, or removes Windows environment variables.";
    } else if (batchCommand == "SETLOCAL") {
        return "// Begins localization of environment changes in a batch file.";
    } else if (batchCommand == "SC") {
        return "// Displays or configures services (background processes).";
    } else if (batchCommand == "SCHTASKS") {
        return "// Schedules commands and programs to run on a computer.";
    } else if (batchCommand == "SHIFT") {
        return "// Shifts the position of replaceable parameters in batch files.";
    } else if (batchCommand == "SHUTDOWN") {
        return "// Allows proper local or remote shutdown of machine.";
    } else if (batchCommand == "SORT") {
        return "// Sorts input.";
    } else if (batchCommand == "START") {
        return "// Starts a separate window to run a specified program or command.";
    } else if (batchCommand == "SUBST") {
        return "// Associates a path with a drive letter.";
    } else if (batchCommand == "SYSTEMINFO") {
        return "// Displays machine specific properties and configuration.";
    } else if (batchCommand == "TASKLIST") {
        return "// Displays all currently running tasks including services.";
    } else if (batchCommand == "TASKKILL") {
        return "// Kill or stop a running process or application.";
    } else if (batchCommand == "TIME") {
        return "// Displays or sets the system time.";
    } else if (batchCommand == "TITLE") {
        return "// Sets the window title for a CMD.EXE session.";
    } else if (batchCommand == "TREE") {
        return "// Graphically displays the folder structure of a drive or path.";
    } else if (batchCommand == "TYPE") {
        return "// Displays the contents of a text file.";
    } else if (batchCommand == "VER") {
        return "// Displays the Windows version.";
    } else if (batchCommand == "VERIFY") {
        return "// Tells Windows whether to verify that files are written correctly.";
    } else if (batchCommand == "VOL") {
        return "// Displays a disk volume label and serial number.";
    } else {
        return "// Command not recognized.";
    }
}

int main() {
    std::vector<std::string> commands = {
        "ASSOC", "ATTRIB", "BREAK", "BCDEDIT", "CACLS", "CALL", "CD",
        "CHCP", "CHDIR", "CHKDSK", "CHKNTFS", "CLS", "CMD", "COLOR",
        "COMP", "COMPACT", "CONVERT", "COPY", "DATE", "DEL", "DIR",
        "DISKPART", "DOSKEY", "DRIVERQUERY", "ECHO", "ENDLOCAL", "ERASE",
        "EXIT", "FC", "FIND", "FINDSTR", "FOR", "FORMAT", "FSUTIL",
        "FTYPE", "GOTO", "GPRESULT", "GRAFTABL", "HELP", "ICACLS", "IF",
        "LABEL", "MD", "MKDIR", "MKLINK", "MODE", "MORE", "MOVE",
        "OPENFILES", "PATH", "PAUSE", "POPD", "PRINT", "PROMPT", "PUSHD",
        "RD", "RECOVER", "REM", "REN", "RENAME", "REPLACE", "RMDIR",
        "ROBOCOPY", "SET", "SETLOCAL", "SC", "SCHTASKS", "SHIFT",
        "SHUTDOWN", "SORT", "START", "SUBST", "SYSTEMINFO", "TASKLIST",
        "TASKKILL", "TIME", "TITLE", "TREE", "TYPE", "VER", "VERIFY", "VOL"
    };

    for (const auto& command : commands) {
        std::cout << convertBatchToCpp(command) << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

int acc = 0;
int ram[16] = {0};

void runPureSun(std::string input) {
    std::stringstream ss(input);
    std::string cmd;
    ss >> cmd;

    if (cmd == "ray") {
        std::string var, eq; int val;
        ss >> var >> eq >> val;
        acc = val;
        std::cout << "[CPU]: ACC = " << acc << std::endl;
    } 
    else if (cmd == "store") {
        int addr; ss >> addr;
        if(addr < 16) ram[addr] = acc;
    }
    else if (cmd == "shine") {
        int addr; ss >> addr;
        if(addr < 16) std::cout << ">> [DISPLAY]: " << ram[addr] << std::endl;
    }
    // NEW: Save current RAM state to a file
    else if (cmd == "save") {
        std::ofstream file("memory.bin");
        for(int i=0; i<16; i++) file << ram[i] << " ";
        file << acc;
        file.close();
        std::cout << "[SYSTEM]: RAM State Saved to Disk." << std::endl;
    }
    // NEW: Load previous RAM state from file
    else if (cmd == "restore") {
        std::ifstream file("memory.bin");
        if(file) {
            for(int i=0; i<16; i++) file >> ram[i];
            file >> acc;
            std::cout << "[SYSTEM]: RAM State Restored." << std::endl;
        }
    }
    else if (cmd == "clear") { system("cls"); }
    else if (cmd == "exit") { exit(0); }
}

int main() {
    SetConsoleTitleA("SUJANA PURE SUN OS - PERSISTENT");
    system("color 0a"); 
    std::cout << "--- SUJANA OS v12.0 (PERSISTENCE ENABLED) ---" << std::endl;
    std::string input;
    while (true) {
        std::cout << "sujana@pure_sun:~$ ";
        std::getline(std::cin, input);
        runPureSun(input);
    }
    return 0;
}

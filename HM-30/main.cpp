//
//  main.cpp
//  HM-30
//
//  Created by Дмитрий Сергеевич on 10.11.2023.
//

#include <iostream>
#include <fstream>
#include <string>

//task2
bool overwrite(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath, std::ios::trunc);
    if (!file.is_open()) {
        return false; // Если файл не существует, возвращаем false
    }
    file << content; // Записываем содержимое
    file.close();
    return true; // Возвращаем true, если замена прошла успешно
}






int main() {
    
    //task1
    std::ofstream file("data.txt", std::ios::app);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input == "end") {
            break;
        }
        file << input << std::endl;
    }

    file.close();

    std::ifstream readFile("data.txt");
    if (!readFile.is_open()) {
        std::cout << "Ошибка открытия файла" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(readFile, line)) {
        std::cout << line << std::endl;
    }

    readFile.close();

    if (remove("data.txt") != 0) {
        std::cout << "Ошибка удаления файла" << std::endl;
        return 1;
    }

    
    
    return 0;
}



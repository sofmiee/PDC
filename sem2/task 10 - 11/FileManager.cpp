#include "FileManager.hpp"
#include "Student.hpp"
#include <iostream>
#include <cstring>

using namespace std;

bool FileManager::save_to_file(const string& filename,
    const vector<Student*>& students,
    const vector<double>& allGrades) {
    
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл для записи: " << filename << endl;
        return false;
    }
    
    FileHeader header;
    strncpy(header.signature, DEFAULT_SIGNATURE, 4);
    header.signature[3] = '\0';
    header.version = CURRENT_VERSION;
    header.student_count = static_cast<uint32_t>(students.size());
    
    cout << "Размер структуры заголовка: " << get_header_size() << " байт" << endl;
    
    file.write(reinterpret_cast<char*>(&header), sizeof(header));
    
    uint32_t gradesCount = static_cast<uint32_t>(allGrades.size());
    file.write(reinterpret_cast<char*>(&gradesCount), sizeof(gradesCount));
    
    if (!allGrades.empty()) {
        file.write(reinterpret_cast<const char*>(allGrades.data()),
            allGrades.size() * sizeof(double));
    }
    
    file.close();
    cout << "Данные успешно сохранены в файл: " << filename << endl;
    return true;
}

bool FileManager::load_from_file(const string& filename,
    vector<Student*>& students,
    vector<double>& allGrades) {
    
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка: не удалось открыть файл для чтения: " << filename << endl;
        return false;
    }
    
    FileHeader header;
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    
    if (!check_signature(filename)) {
        cerr << "Ошибка: неверная сигнатура файла!" << endl;
        file.close();
        return false;
    }
    
    cout << "Заголовок файла:" << endl;
    cout << "  Сигнатура: " << header.signature << endl;
    cout << "  Версия: " << header.version << endl;
    cout << "  Количество студентов: " << header.student_count << endl;
    
    uint32_t gradesCount;
    file.read(reinterpret_cast<char*>(&gradesCount), sizeof(gradesCount));
    cout << "  Количество оценок: " << gradesCount << endl;
    
    allGrades.clear();
    if (gradesCount > 0) {
        allGrades.resize(gradesCount);
        file.read(reinterpret_cast<char*>(allGrades.data()),
            gradesCount * sizeof(double));
    }
    
    file.close();
    cout << "Данные успешно загружены из файла: " << filename << endl;
    return true;
}

bool FileManager::check_signature(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        return false;
    }
    
    char signature[4] = { 0 };
    file.read(signature, 4);
    file.close();
    
    return strcmp(signature, DEFAULT_SIGNATURE) == 0;
}

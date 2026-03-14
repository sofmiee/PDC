#include <iostream>
#include <windows.h>
#include <clocale>
#include <vector>
#include <fstream>
#include <cstdint>

using namespace std;

#pragma pack(push, 1)
struct FileHeader {
    char signature[4];     // сигнатура "GRD"
    uint16_t version;       // версия файла
    uint32_t student_count; // количество студентов
};
#pragma pack(pop)

//проверка корректности ввода оценок
double grade_check(int number) {
    double value;
    while (true) {
        cout << "Студент " << number << ": ";
        cin >> value;

        if (cin.fail() || value < 0 || value > 5) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка! Введите число от 0 до 5: ";
        } else {
            cin.ignore(100, '\n');
            return value;
        }
    }
}

//проверка ввода количества
int count_check() {
    int count;
    while (true) {
        cin >> count;
        if (cin.fail() || count <= 0) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка! Введите натуральное число: ";
        } else {
            cin.ignore(100, '\n');
            return count;
        }
    }
}

//функция сохранения в файл
bool save_to_file(const string& filename, const vector<double>& grades, int student_count) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return false;
    }
    
    //создаем заголовок
    FileHeader header;
    header.signature[0] = 'G';
    header.signature[1] = 'R';
    header.signature[2] = 'D';
    header.signature[3] = '\0';
    header.version = 1;
    header.student_count = student_count;
    
    //записываем заголовок
    file.write(reinterpret_cast<char*>(&header), sizeof(header));
    
    //записываем все оценки
    file.write(reinterpret_cast<const char*>(grades.data()), grades.size() * sizeof(double));
    
    file.close();
    cout << "Данные сохранены в файл " << filename << endl;
    return true;
}

//функция загрузки из файла
bool load_from_file(const string& filename, vector<double>& grades, int& student_count) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return false;
    }
    
    //читаем заголовок
    FileHeader header;
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    
    //проверка сигнатуры
    if (header.signature[0] != 'G' || header.signature[1] != 'R' || header.signature[2] != 'D') {
        cout << "Ошибка! Неверная сигнатура файла!" << endl;
        file.close();
        return false;
    }
    
    cout << "Сигнатура корректна" << endl;
    cout << "Версия файла: " << header.version << endl;
    cout << "Количество студентов: " << header.student_count << endl;
    
    student_count = header.student_count;
    
    //читаем оценки
    grades.resize(student_count);
    file.read(reinterpret_cast<char*>(grades.data()), student_count * sizeof(double));
    
    file.close();
    cout << "Данные загружены из файла " << filename << endl;
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "RUS");

    //выводим размер структуры (требование 3)
    cout << "Размер структуры заголовка: " << sizeof(FileHeader) << " байт" << endl;
    
    int choice;
    cout << "Выберите действие: 1 - запись, 2 - чтение: ";
    cin >> choice;
    
    if (choice == 1) {
        //запись в файл
        cout << "Введите количество студентов: ";
        int N = count_check();
        
        vector<double> grades(N);
        
        cout << "Введите средние баллы студентов (от 0 до 5): " << endl;
        for (int i = 0; i < N; i++) {
            grades[i] = grade_check(i + 1);
        }
        
        string filename;
        cout << "Введите имя файла для сохранения: ";
        cin >> filename;
        
        save_to_file(filename, grades, N);
        
    } else if (choice == 2) {
        //чтение из файла
        string filename;
        cout << "Введите имя файла для загрузки: ";
        cin >> filename;
        
        vector<double> grades;
        int N = 0;
        
        if (load_from_file(filename, grades, N)) {
            cout << "\nЗагруженные оценки студентов:" << endl;
            for (int i = 0; i < N; i++) {
                cout << "Студент " << i + 1 << ": " << grades[i] << endl;
            }
        }
    }

    return 0;
}

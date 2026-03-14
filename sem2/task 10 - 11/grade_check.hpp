#ifndef GRADE_CHECK_HPP
#define GRADE_CHECK_HPP

inline double grade_check(int number) {
    double value;
    while (true) {
        cout << "Оценка " << number << ": ";
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

#endif

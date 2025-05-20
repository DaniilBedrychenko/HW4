#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    srand(time(NULL));

    const int SIZE = 20;
    int arr[SIZE];

  
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 200 - 100;
        cout << arr[i] << " ";
    }
    cout << endl;

   
    int choice;
    cout << "\nОберіть дію:\n";
    cout << "1 - Вивести лише парні значення\n";
    cout << "2 - Вивести лише від'ємні значення\n";
    cout << "3 - Порахувати суму усіх елементів\n";
    cout << "4 - Порахувати середнє значення елементів масиву\n";
    cout << "5 - Перевірити наявність числа в масиві\n";
    cout << "6 - Вивести максимальне та мінімальне значення масиву\n";
    cout << "7 - Заповнити масив числами Фібоначчі\n";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Парні значення:\n";
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] % 2 == 0) {
                cout << arr[i] << " ";
            }
        }
        break;

    case 2:
        cout << "Від'ємні значення:\n";
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] < 0) {
                cout << arr[i] << " ";
            }
        }
        break;

    case 3: {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += arr[i];
        }
        cout << "Сума елементів: " << sum << endl;
        break;
    }

    case 4: {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += arr[i];
        }
        double avg = sum / SIZE;
        cout << "Середнє значення: " << avg << endl;
        break;
    }

    case 5: {
        int number;
        cout << "Введіть число для пошуку: ";
        cin >> number;
        int index;
        for (int i = 0; i < SIZE; i++) {
            if (arr[i] == number) {
                index = i;
            }
        }
        if (index >= 0) {
            cout << "Число знайдено на індексі: " << index << endl;
        }
        else {
            cout << "Число не є частиною масиву.\n";
        }
        break;
    }

    case 6: {
        int min = arr[0], max = arr[0];
        for (int i = 1; i < SIZE; i++) {
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];
        }
        cout << "Мінімальне значення: " << min << endl;
        cout << "Максимальне значення: " << max << endl;
        break;
    }

    case 7: {
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < SIZE; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        cout << "Числа Фібоначчі:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << arr[i] << " ";
        }
        break;
    }
    case 8: {
        int index, newValue;
        cout << "Введіть індекс (0-" << actualSize << "): ";
        cin >> index;
        if (index < 0 || index > actualSize) {
            cout << "Невірний індекс.\n";
            break;
        }
        cout << "Введіть нове число: ";
        cin >> newValue;

        // Посунення вправо
        for (int i = actualSize; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = newValue;
        actualSize++; // Збільшуємо розмір

        cout << "Новий масив:\n";
        for (int i = 0; i < actualSize; i++) {
            cout << arr[i] << " ";
        }
        break;
    }

    default:
        cout << "Невірний вибір.\n";
        break;
    }

    cout << endl;
    return 0;
}

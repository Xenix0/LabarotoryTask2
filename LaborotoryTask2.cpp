#include <iostream>
#include <chrono>
#include <time.h>
#include <ctime>
#include <cmath>
using namespace std;
using namespace chrono;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j]; // создали дополнительную переменную
                arr[j] = arr[j + 1]; // меняем местами
                arr[j + 1] = b; // значения элементов
            }
        }
    }
}

void cocktailSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        --end;

        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}

void combSort(int arr[], int n) {
    int swap, count = 0;
    float k = 1.247, S = n - 1;
    while (S >= 1)
    {
        for (int i = 0; i + S < n; i++)
        {
            if (arr[i] > arr[int(i + S)])
            {
                swap = arr[int(i + S)];
                arr[int(i + S)] = arr[i];
                arr[i] = swap;
            }
        }
        S /= k;
    }

    while (true)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = swap;
            }
            else count++;
        }
        if (count == n - 1)
            break;
        else
            count = 0;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Сдвигаем элементы массива, которые больше key, на одну позицию вперед
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) { //Функция для вывода массива
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quicksort(int arr[], int  end, int begin)
{
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}

int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -1;
}



void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Создаем временные массивы
    int* L = new int[n1];
    int* R = new int[n2];

    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы L[], если есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы R[], если есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Освобождаем выделенную память
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "rus");
    srand(time(0));
    const int n = 100;
    int arr[n];
    const int f = 99;
    const int min = -99;
    const int max = 99;
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }

    int k;
    do {
        cout << "1) Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99." << endl;
        cout << "2) Отсортировать заданный в пункте 1 массив […] сортировкой (от меньшего к большему). Определить время, затраченное на сортировку, используя библиотеку chrono." << endl;
        cout << "3) Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в отсортированном массиве и неотсортированном, используя библиотеку chrono." << endl;
        cout << "4) Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения в отсортированном и неотсортированном. Выводит индексы всех элементов, которые равны этому значению, и их количество. Подсчитайте время поиска." << endl;
        cout << "5) Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем." << endl;
        cout << "6) Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем." << endl;
        cout << "7) Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве. Реализуйте алгоритм бинарного поиска. Сравните скорость его работы с обычным перебором. " << endl;
        cout << "8) Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono." << endl;
        cout << "9) ИДЗ№2: Сортировка слиянием. Вывод времени выполнения сортировки слиянием в сравнении с сортировкой Quick sort. " << endl;

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
        nanoseconds result1;
        cout << "Введите номер задания: ";
        cin >> k;
        switch (k) {

        case 1: {
            cout << "Целочисленный массив со значениями от -99 до 99: " << endl;
            int arr1[n];
            for (int i = 0; i < n; i++) {
                arr1[i] = rand() % (max - min + 1) + min; //включая -99 и 99
            }
            printArray(arr1, n);
            break;
        }
        case 2: {
            cout << "Неотсортированный массив: " << endl;
            printArray(arr, n);
            auto start = steady_clock::now();
            quicksort(arr, f, 0);
            auto end = steady_clock::now();
            auto result = duration_cast<nanoseconds>(end - start);
            cout << "Отсортированный массив: " << endl;
            printArray(arr, n);
            cout << "Время выполнения сортировки Quick sort (быстрая сортировка): " << result.count() << " наносекунд." << endl;
            break;
        }

        case 3: {
            int arr3[n];
            for (int i = 0; i < n; i++) {
                arr3[i] = rand() % (max - min + 1) + min; //случайный массив
            }
            
            int min3 = arr3[0];
            int max3 = arr3[0];
            auto start2 = steady_clock::now();
            for (int i = 1; i < n; ++i) {
                if (arr3[i] < min3) {
                    min3 = arr3[i];
                }
                if (arr3[i] > max3) {
                    max3 = arr3[i];
                }
            }
            auto end2 = steady_clock::now();
            auto result2 = duration_cast<nanoseconds>(end2 - start2);

            int minArr3, maxArr3;
            quicksort(arr3, f, 0);
            auto start3 = steady_clock::now();
            minArr3 = arr3[0];
            maxArr3 = arr3[f];
            auto end3 = steady_clock::now();
            auto result3 = duration_cast<nanoseconds>(end3 - start3);
            cout << "Массив: " << endl;
            printArray(arr3, n);
            cout << "Минимальный элемент массива: " << minArr3 << endl;
            cout << "Максимальный элемент массива: " << maxArr3 << endl;
            cout << "Время поиска в неотсортированном массиве: " << result2.count() << " наносекунд." << endl;
            cout << "Время поиска в отсортированном массиве: " << result3.count() << " наносекунд." << endl;
        }
              break;
        case 4: {
            int arr4[n];
            int count = 0, count1 = 0;
            float mid, mid1;

            for (int i = 0; i < n; i++) {
                arr4[i] = rand() % (max - min + 1) + min; //включая -99 и 99
            }
            int min4 = arr4[0];
            int max4 = arr4[0];
            cout << "Неотсортированный массив: ";
            printArray(arr4, n);
            cout << endl;
            auto start4 = steady_clock::now();
            for (int i = 0; i < n; ++i) {
                if (arr4[i] < min4) {
                    min4 = arr4[i];
                }
                if (arr4[i] > max4) {
                    max4 = arr4[i];
                }
            }
            mid = round((min4 + max4) / 2);
            cout << "Среднее значение максимального и минимального элементов массива: " << mid << endl;
            for (int i = 0; i < n; i++) {
                if (arr4[i] == mid) {
                    cout << i << "-й элемент массива равен среднему значению" << endl;
                    count += 1;
                }
            }
            if (count == 0) {
                cout << "Такого элемента в массиве не найдено." << endl;
            }
            auto end4 = steady_clock::now();
            auto result4 = duration_cast<nanoseconds>(end4 - start4);
            cout << "Количество элементов массива, которые равны среднему значению: " << count << endl;
            cout << "Время поиска в неотсортированном массиве: " << result4.count() << " наносекунд." << endl;


            quicksort(arr4, f, 0);
            cout << "Отсортированный массив: " << endl;
            printArray(arr4, n);

            int minArr4, maxArr4;
            minArr4 = arr4[0];
            maxArr4 = arr4[f];
            mid1 = round((minArr4 + maxArr4) / 2);
            cout << "Среднее значение максимального и минимального элементов массива: " << mid1 << endl;
            auto start5 = steady_clock::now();
            if (binarySearch(arr4, mid1, 0, f) == -1) {
                cout << "Такого элемента в массиве не найдено." << endl;
            }
            else {
                for (int i = 0; i < n; i++) {
                    if (arr4[i] <= mid1) {
                        if (arr4[i] == mid1) {
                            cout << i << "-й элемент массива равен среднему значению" << endl;
                            count1 += 1;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            
            
            auto end5 = steady_clock::now();
            auto result5 = duration_cast<nanoseconds>(end5 - start5);
            cout << "Количество элементов массива, которые равны среднему значению: " << count << endl;
            cout << "Время поиска в отсортированном массиве: " << result5.count() << " наносекунд." << endl;
        }
              break;
        case 5: {
            int a5, count5 = 0;
            cout << "Введите число: ";
            cin >> a5;
            int arr5[n];
            for (int i = 0; i < n; i++) {
                arr5[i] = rand() % (max - min + 1) + min;
            }
            quicksort(arr5, f, 0);
            printArray(arr5, n);
            for (int i = 0; i < n; i++) {
                if (arr5[i] <= a5) {
                    if (arr5[i] < a5) {
                        count5 += 1;
                    }
                    else {
                        break;
                    }
                }
            }
            cout << "Количество элементов меньше введённого: " << count5 << endl;
        }
              break;
        case 6: {
            int a6, count6 = 0;
            cout << "Введите число: ";
            cin >> a6;
            int arr6[n];
            for (int i = 0; i < n; i++) {
                arr6[i] = rand() % (max - min + 1) + min;
            }
            quicksort(arr6, f, 0);
            printArray(arr6, n);
            for (int i = n - 1; i >= 0; i--) {
                if (arr6[i] >= a6) {
                    if (arr6[i] > a6) {
                        count6 += 1;
                    }
                    else {
                        break;
                    }
                }
            }
            cout << "Количество элементов больше введённого: " << count6 << endl;
        }
              break;
        case 7: {
            int a7, val;
            int arr7[n];
            bool flag = true;
            for (int i = 0; i < n; i++) {
                arr7[i] = rand() % (max - min + 1) + min;
            }
            quicksort(arr7, f, 0);
            printArray(arr7, n);
            cout << "Введите число, которое необходимо найти: ";
            cin >> a7;
            cout << endl;

            auto start6 = steady_clock::now();
            val = binarySearch(arr7, a7, 0, f);
            auto end6 = steady_clock::now();
            auto result6 = duration_cast<nanoseconds>(end6 - start6);

            auto start7 = steady_clock::now();
            for (int i = 0; i < n; i++) {
                if (arr7[i] == a7) {
                    val = arr7[i];
                    flag = true;
                    break;
                }
                else {
                    flag = false;
                }
            }
            if (flag == true) {
                cout << "Введенное число есть в массиве." << endl;

            }
            else {
                cout << "Введенного числа в массиве нет." << endl;
            }
            auto end7 = steady_clock::now();
            auto result7 = duration_cast<nanoseconds>(end7 - start7);
            cout << "Время бинарного поиска: " << result6.count() << " наносекунд." << endl;
            cout << "Время поиска перебором: " << result7.count() << " наносекунд." << endl;

        }
              break;
        case 8: {
            int a8, b8;
            cout << "Введите индексы элементов массива: ";
            cin >> a8;
            cout << " ";
            cin >> b8;
            cout << endl;
            const int n7 = 100;
            int arr8[n];
            for (int i = 0; i < n; i++) {
                arr8[i] = rand() % (max - min + 1) + min;
            }
            quicksort(arr8, f, 0);
            cout << "Изначальный массив: " << endl;
            printArray(arr8, n);
            auto start8 = steady_clock::now();
            swap(arr8[a8], arr8[b8]);
            auto end8 = steady_clock::now();
            auto result8 = duration_cast<nanoseconds>(end8 - start8);
            cout << "Массив после обмена переменных: " << endl;
            printArray(arr8, n);
            cout << "Скорость обмена: " << result8.count() << " наносекунд." << endl;
        }
              break;

        case 9: {
            int arr9[n], arr10[n];
            for (int i = 0; i < n; i++) {
                arr9[i] = rand() % (max - min + 1) + min;
                arr10[i] = arr9[i];
            }
            cout << "Неотсортированный массив: ";
            printArray(arr9, n);
            cout << endl;
            auto start9 = steady_clock::now();
            mergeSort(arr9, 0, f);
            auto end9 = steady_clock::now();
            auto result9 = duration_cast<nanoseconds>(end9 - start9);
            cout << "Отсортированный массив: ";
            printArray(arr9, n);
            cout << endl;
            auto start10 = steady_clock::now();
            quicksort(arr10, f, 0);
            auto end10 = steady_clock::now();
            auto result10 = duration_cast<nanoseconds>(end10 - start10);

            cout << "Время сортировки слиянием: " << result9.count() << endl;
            cout << "Время сортировки Quick sort: " << result10.count() << endl;

        }
              break;
        }
        cout << "Введите любое число чтобы продолжить" << endl;
    } while (cin >> k);

}

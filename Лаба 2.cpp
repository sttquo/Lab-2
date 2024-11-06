#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void generateArr(int arr[], const int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 199 - 99;
	}
}
void printArr(int arr[], const int size) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
void bubbleSort(int arr[], const int size) {

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}
void shakerSort(int arr[], const int size) {

	bool swapped = true;
	int start = 0;
	int end = size - 1;

	while (swapped) {

		swapped = false;

		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		++start;
	}

}
void compSort(int arr[], const int size) {

	float factor = 1.247;
	int distance = size - 1, count = 0;

	while (distance >= 1) {
		for (int i = 0; i + distance < size; i++) {

			if (arr[i] > arr[int(i + distance)]) {
				swap(arr[i], arr[i + distance]);
			}
		}
		distance /= factor;
	}

	while (true) {
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) {

				swap(arr[i], arr[i + 1]);

			}
			else count++;
		}
		if (count == size - 1)
			break;
		else
			count = 0;
	}
}
void insertionSort(int arr[], const int size) {

	int i, j, key;

	for (i = 0; i < size; ++i) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void quickSort(int* arr, int  end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];

	while (f <= l)
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
	if (begin < l)
		quickSort(arr, l, begin);
	if (f < end)
		quickSort(arr, end, f);
}
void findMaxMin(int arr[], const int size, int& maxElement, int& minElement) {
	minElement = arr[0];
	maxElement = arr[0];

	for (int i = 1; i < size; ++i) {
		if (arr[i] < minElement) {
			minElement = arr[i];
		}
		if (arr[i] > maxElement) {
			maxElement = arr[i];
		}
	}

}
void calculationAverageAndId(int arr[], const int size, int minElement, int maxElement) {
	int average = (minElement + maxElement) / 2;
	int count = 0;
	cout << "\nИндексы элементов, равных среднему значению: ";

	for (int i = 0; i < size; i++) {
		if (arr[i] == average) {
			count++;
			cout << i << " ";
		}
	}

	cout << "\nСреднее значение минимального и максимального элемента массива: " << average
		<< "\nКоличество элементов, равных среднему значению: " << count << endl;
}
bool binarySearch(int arr[], int size, int value) {
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == value)
		{
			return true;
		}
		else if (arr[mid] < value)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	return false; // Элемент не найден
}
bool linearSearch(int arr[], int size, int value) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}
	return false;
}

int main() {
	setlocale(LC_ALL, "RU");

	const int size = 100;
	int arr[size], taskNumber;
	int maxElement, minElement, value;

	generateArr(arr, size);
	cout << "Исходный массив:\n";
	printArr(arr, size);

	while (true)
	{
		cout << "\nВыберите нужное действие\n\n[0] Переформировать массив\n[1] Отсортировать массив\n[2] Найти MAX и MIN элемент массива\n[3] Вывод среднего значения MAX и MIN элементов\n[-1] Выйти из программы\n";
		int firstAction;
		cin >> firstAction;

		switch (firstAction) {
		case 0:
		{
			generateArr(arr, size);
			printArr(arr, size);
			break;
		}
		case 2:
		{
			auto start = high_resolution_clock::now();
			findMaxMin(arr, size, maxElement, minElement);
			auto stop = high_resolution_clock::now();

			cout << "\nМинимальный элемент: " << minElement << "\nМаксимальный элемент: " << maxElement;
			auto duration = duration_cast<nanoseconds>(stop - start);
			cout << "\nВремя поиска MAX и MIN в неотсортированном массиве: " << duration.count() << " нс";

			quickSort(arr, 0, size - 1);

			auto startSortArr = high_resolution_clock::now();
			findMaxMin(arr, size, maxElement, minElement);
			auto stopSortArr = high_resolution_clock::now();

			auto durationSortArr = duration_cast<nanoseconds>(stopSortArr - startSortArr);
			cout << "\nВремя поиска MAX и MIN в отсортированном массиве: " << durationSortArr.count() << " нс" << endl;
			break;
		}
		case 3:
		{
			auto start = high_resolution_clock::now();
			//findMaxMin(arr, size, maxElement, minElement);
			calculationAverageAndId(arr, size, minElement, maxElement);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(stop - start);
			cout << "\nВремя поиска в неотсартированном массиве: " << duration.count() << endl;

			quickSort(arr, 0, size - 1);

			auto startSortArr = high_resolution_clock::now();
			//findMaxMin(arr, size, maxElement, minElement);
			calculationAverageAndId(arr, size, minElement, maxElement);
			auto stopSortArr = high_resolution_clock::now();
			auto durationSortArr = duration_cast<nanoseconds>(stopSortArr - startSortArr);
			cout << "\nВремя поиска в отсортированном массиве: " << durationSortArr.count() << endl;
			break;
		}
		case 1:
		{

			cout << "\nВыберите вид сортировки\n\n[1] Bubble sort\n[2] Shaker sort\n[3] Comp sort\n[4] Insertion sort\n[5] Quick sort\n[-1] Выход в главное меню\n";
			int typeOfSort;
			cin >> typeOfSort;
			if (typeOfSort == -1)
				break;
			switch (typeOfSort)
			{
			case 1:
			{
				auto start = high_resolution_clock::now();
				bubbleSort(arr, size);
				auto stop = high_resolution_clock::now();

				cout << "Массив после сортировки:\n";
				printArr(arr, size);

				auto duration = duration_cast<nanoseconds>(stop - start);
				cout << "\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
				break;
			}
			case 2:
			{
				auto start = high_resolution_clock::now();
				shakerSort(arr, size);
				auto stop = high_resolution_clock::now();

				cout << "Массив после сортировки:\n";
				printArr(arr, size);

				auto duration = duration_cast<nanoseconds>(stop - start);
				cout << "\n\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
				break;
			}
			case 3:
			{
				auto start = high_resolution_clock::now();
				compSort(arr, size);
				auto stop = high_resolution_clock::now();

				cout << "Массив после сортировки:\n";
				printArr(arr, size);

				auto duration = duration_cast<nanoseconds>(stop - start);
				cout << "\n\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
				break;
			}
			case 4:
			{
				auto start = high_resolution_clock::now();
				insertionSort(arr, size);
				auto stop = high_resolution_clock::now();

				cout << "Массив после сортировки:\n";
				printArr(arr, size);

				auto duration = duration_cast<nanoseconds>(stop - start);
				cout << "\n\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
				break;
			}
			case 5:
			{
				auto start = high_resolution_clock::now();
				quickSort(arr, size - 1, 0);
				auto stop = high_resolution_clock::now();

				cout << "Массив после сортировки:\n";
				printArr(arr, size);

				auto duration = duration_cast<nanoseconds>(stop - start);
				cout << "\n\nВремя, затраченное на выполнение сортировки: " << duration.count() << " наносекунд";
				break;
			}
			case -1:
			{
				break;
			}
			}
			int secondAction;
			do
			{
				cout << "\nВыберите действие:\n\n[1] Найти MAX и MIN элемент массива\n[2] Вывод среднего значения MAX и MIN элементов\n[3] Вывод колличества элементов <A\n[4] Вывод колличества элементов >B\n[5] Поиск числа\n[6] Поменять местами элементы массива\n[7] ИДЗ\n[-1] Выход из программы\n";
				cin >> secondAction;

				switch (secondAction)
				{
				case 1:
				{
					auto start = high_resolution_clock::now();
					findMaxMin(arr, size, maxElement, minElement);
					auto stop = high_resolution_clock::now();

					cout << "\nМинимальный элемент: " << minElement << "\nМаксимальный элемент: " << maxElement;
					auto duration = duration_cast<nanoseconds>(stop - start);
					cout << "\nВремя поиска MAX и MIN: " << duration.count();
					break;
				}
				case 2:
				{
					auto start = high_resolution_clock::now();
					findMaxMin(arr, size, maxElement, minElement);
					calculationAverageAndId(arr, size, minElement, maxElement);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<nanoseconds>(stop - start);
					cout << "\nВремя поиска: " << duration.count();
					break;
				}
				case 3:
				{
					int count = 0, A;
					cout << "Введите число A: ";
					cin >> A;
					for (int i = 0; i < size; ++i)
					{
						if (arr[i] < A)
						{
							++count;
						}
					}
					cout << "Колличество элементов меньше '" << A << "': " << count << "\n";
					break;
				}
				case 4:
				{
					int count = 0, B;
					cout << "Введите число B: ";
					cin >> B;
					for (int i = 0; i < size; ++i)
					{
						if (arr[i] > B)
						{
							++count;
						}
					}
					cout << "Колличество элементов больше '" << B << "': " << count << "\n";
					break;
				}
				case 5:
				{
					cout << "Введите число для поиска: ";
					cin >> value;

					auto startBin = high_resolution_clock::now();
					bool binary = binarySearch(arr, size, value);
					auto stopBin = high_resolution_clock::now();
					auto durationBin = duration_cast<nanoseconds>(stopBin - startBin);

					auto startLin = high_resolution_clock::now();
					bool linear = linearSearch(arr, size, value);
					auto stopLin = high_resolution_clock::now();
					auto durationLin = duration_cast<nanoseconds>(stopLin - startLin);

					cout << "Binary search: " << (binary ? "Найдено" : "Не найдено") << " Время вывода: " << durationBin.count() << "\n";
					cout << "Linear search: " << (linear ? "Найдено" : "Не найдено") << " Время вывода: " << durationLin.count() << "\n";
					break;
				}
				case 6:
				{
					printArr(arr, size);
					cout << "\nВведите индексы элементов, которые вы хохите поменять местами\n";
					int firstElement, secondElement;
					cout << "Элемент 1: ";
					cin >> firstElement;
					cout << "Элемент 2: ";
					cin >> secondElement;
					int swapElement = arr[firstElement];
					arr[firstElement] = arr[secondElement];
					arr[secondElement] = swapElement;
					printArr(arr, size);
					break;
				}
				case 7:
				{
					int value, randomNumber = rand() % 9 + 1;
					int count1 = size, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;

					cout << "Введите значение на которое вы хотите уменьшить каждый нечетный элемент: ";
					cin >> value;
					for (int i = 0; i < size; i++)
						for (int n = 0; n < size; n++)
							if (i == 2 * n + 1)
							{
								arr[i] = arr[i] - value;
								arr[i] = arr[i] * randomNumber;
							}
					for (int i = 0; i < size; i++)
						if (arr[i] % 2 == 0)
							count2 = count2 + 1;
					for (int i = 0; i < size; i++)
						if (arr[i] % 3 == 0)
							count3 = count3 + 1;
					for (int i = 0; i < size; i++)
						if (arr[i] % 4 == 0)
							count4 = count4 + 1;
					for (int i = 0; i < size; i++)
						if (arr[i] % 5 == 0)
							count5 = count5 + 1;
					for (int i = 0; i < size; i++)
						if (arr[i] % 6 == 0)
							count6 = count6 + 1;
					for (int i = 0; i < size; i++)
						if (arr[i] % 7 == 0)
							count7 = count7 + 1;
					for (int i = 0; i < size; i++)
						if (arr[i] % 8 == 0)
							count8 = count8 + 1;
					for (int i = 0; i < size; i++)
						if (arr[i] % 9 == 0)
							count9 = count9 + 1;

					printArr(arr, size);
					cout << "\nДелятся на 1: " << count1 << "\nДелятся на 2: " << count2 << "\nДелятся на 3: " << count3 << "\nДелятся на 4: " << count4 << "\nДелятся на 5: " << count5
						<< "\nДелятся на 6: " << count6 << "\nДелятся на 7: " << count7 << "\nДелятся на 8: " << count8 << "\nДелятся на 9: " << count9;
					break;
				}
				}
			} while (secondAction != -1);
		}
		case -1:
		{
			return 0;
		}


		}
	}

	return 0;
}
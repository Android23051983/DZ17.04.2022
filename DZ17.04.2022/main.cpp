#include<iostream>

using std::cin;
using std::cout;
using std::endl;


void FillRand(int arr[], int SIZE);	//заполняет массив случайными числами
void Sort(int arr[], int SIZE);		//сортирует массив
void Sum(int arra[], int arrb[], int arrc[], int SIZE);		//возвращает сумму элементов массива
int Sum(int arr[], const int SIZE);
double Avg(int arr[], int SIZE);		//возвращает среднее арифметическое элементов массива
int minValueIn(int arr[], int SIZE, int arg);//возвращает минимальное значение из массива
int maxValueIn(int arr[], int SIZE, int arg);//возвращает максимальное значение из массива
void shiftLeft(int arr[], int SIZE, int i, int indent);//выполняет циклический сдвиг массива на заданное число элементов влево
void shiftRight(int arr[], int SIZE, int i, int indent);//выполняет циклический сдвиг массива на заданное число элементов вправо
void UniqueRand(int arr[], int SIZE, int i);//заполняет массив уникальными случайными числами
void Print(int arr[], int SIZE);	//выводит массив на экран
void Print(int avg);//выводит любой аргумент (переменную) на экран



void main()
{
	setlocale(LC_ALL, "");
	int SIZE;
	int i = 0;
	int min = 0;
	int max = 0;
	int Summ = 0;
	int arg = 0;
	int avg = 0;
	int buffer = 0;
	int indent = 0;
	int massiv = 0;
	int r = 0;
	cout << "Введите SIZE: "; cin >> SIZE;
	int* arr = new int[SIZE];
	FillRand(arr, SIZE);
	Print(arr, SIZE);
	Sort(arr, SIZE);
	Print(arr, SIZE);
	Sum(arr, arr, arr, SIZE);
	Print(arr, SIZE);
	avg = Avg(arr, SIZE);
	Print(avg);
	cout << Avg(arr, SIZE) << endl;;
	min = minValueIn(arr, SIZE, arg);
	Print(min);
	max = maxValueIn(arr, SIZE, arg);
	Print(max);
	shiftLeft(arr, SIZE, i, indent);
	Print(arr, SIZE);
	shiftRight(arr, SIZE, i, indent);
	Print(arr, SIZE);
	UniqueRand(arr, SIZE, i);
	Print(arr, SIZE);

	
	delete[] arr;
}

void FillRand(int arr[], int SIZE)
{
	for (int i = 0; i <= SIZE; i++)
	{
		arr[i] = rand()%100;
	}
	cout << "заполняет массив случайными числами" << endl;

}

void Sort(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++ )
	{
		for (int j = i + 1; j <= SIZE; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
	cout << "сортирует массив" << endl;
}

void Sum(int arra[], int arrb[],int arrc[], int SIZE)
{
	for (int i = 0; i <= SIZE; i++)
	{
		 arrc[i] = arra[i] + arrb[i];
	}
	//cout << "возвращает сумму элементов массива" << endl;
	cout << "Суммирует два массива, и результат сохраняет в третий массив" << endl;
}

int Sum(int arr[], const int SIZE)
{
	cout << "возвращает сумму элементов массива" << endl;
	int sum = 0;
	for (int i = 0; i < SIZE; i++)sum += arr[i];
	return sum;
}

double Avg(int arr[], int SIZE)
{
	/*int Summ = 0;
	for (int i = 0; i < SIZE; i++)
	{
		Summ = Summ + arr[i];
	}
	double avg = Summ / SIZE;
	cout << "возвращает среднее арифметическое элементов массива" << endl;
	return avg;*/
	cout << "возвращает среднее арифметическое элементов массива" << endl;
	return Sum(arr, SIZE) / (double)SIZE;
}

int minValueIn(int arr[], int SIZE, int min)
{
	min = arr[0];
	for (int i = 0; i < SIZE; i++)
	{
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	cout << "возвращает минимальное значение из массива" << endl;
	return min;
}

int maxValueIn(int arr[], int SIZE, int max)
{
	max = arr[0];
	for (int i = 0; i < SIZE; i++)
	{
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	cout << "возвращает максимальное значение из массива" << endl;
	return max;
}

void shiftLeft(int arr[], int SIZE, int i, int indent)
{
	cout << "выполняет циклический сдвиг массива на заданное число элементов влево" << endl;
	cout << "Введите чсло для сдвига: "; cin >> indent;
	for (int i = 0; i < indent; i++)
	{
		int buffer = arr[SIZE - 1];
		for (int i = SIZE - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}

void shiftRight(int arr[], int SIZE, int i, int indent)
{
cout << "выполняет циклический сдвиг массива на заданное число элементов вправо" << endl;
cout << "Введите чсло для сдвига: "; cin >> indent;
for (int i = 0; i < indent; i++)
{
	int buffer = arr[0];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[SIZE - 1] = buffer;
}
//SIZE = SIZE + indent;
////cout << "SIZE = " << SIZE;
//arr[SIZE];
//
//for (i = SIZE-1; i >= 0; i--)
//{
//	
//		arr[i] = arr[i - indent];
//
//}
//
//for (int i = 0; i < indent; i++)
//{
//	arr[i] = 0;
//}
//do
//{
//	cout << "Введите номер массива начиная с 0 (число выше " << SIZE - 1 << " для перехода: "; cin >> i;
//	cout << i << " - " << arr[i] << endl;
//} while (i <= SIZE - 1);
}

void UniqueRand(int arr[], int SIZE, int i)
{
	cout << "заполняет массив случайными числами от 0 до 9" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand()%10;
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << "Приведение массива к уникальному виду" << endl;
	int j;
	for (i = 0; i < SIZE; i++) {
		for (j = i + 1; j < SIZE; j++) {
			if (arr[i] == arr[j]) {
				arr[j]++;

			}
		}
	}
}

void Print(int arr[], int SIZE)
{
	int choice = 0;
	int i = 0;
	cout << "Выберите вариан вывода массива (1-вывод по номеру, не 1 - вывод всего массива): "; cin >> choice;
	if (choice == 1)
	{
		do
		{
			cout << "Введите номер массива начиная с 0 (число выше " << SIZE << " для перехода: "; cin >> i;
			cout << i << " - " << arr[i] << endl;
		} while (i <= SIZE);
	}
	else
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << i+1 << " - " << arr[i] << endl;
		}
	}
			cout << endl;
}

void Print(int arg)
{
	cout << "Вывод на экран " << arg << endl;
	cout << endl;
}

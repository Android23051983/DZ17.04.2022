#include<iostream>

using std::cin;
using std::cout;
using std::endl;


void FillRand(int arr[], int SIZE);	//��������� ������ ���������� �������
void Sort(int arr[], int SIZE);		//��������� ������
void Sum(int arra[], int arrb[], int arrc[], int SIZE);		//���������� ����� ��������� �������
int Sum(int arr[], const int SIZE);
double Avg(int arr[], int SIZE);		//���������� ������� �������������� ��������� �������
int minValueIn(int arr[], int SIZE, int arg);//���������� ����������� �������� �� �������
int maxValueIn(int arr[], int SIZE, int arg);//���������� ������������ �������� �� �������
void shiftLeft(int arr[], int SIZE, int i, int indent);//��������� ����������� ����� ������� �� �������� ����� ��������� �����
void shiftRight(int arr[], int SIZE, int i, int indent);//��������� ����������� ����� ������� �� �������� ����� ��������� ������
void UniqueRand(int arr[], int SIZE, int i);//��������� ������ ����������� ���������� �������
void Print(int arr[], int SIZE);	//������� ������ �� �����
void Print(int avg);//������� ����� �������� (����������) �� �����



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
	cout << "������� SIZE: "; cin >> SIZE;
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
	cout << "��������� ������ ���������� �������" << endl;

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
	cout << "��������� ������" << endl;
}

void Sum(int arra[], int arrb[],int arrc[], int SIZE)
{
	for (int i = 0; i <= SIZE; i++)
	{
		 arrc[i] = arra[i] + arrb[i];
	}
	//cout << "���������� ����� ��������� �������" << endl;
	cout << "��������� ��� �������, � ��������� ��������� � ������ ������" << endl;
}

int Sum(int arr[], const int SIZE)
{
	cout << "���������� ����� ��������� �������" << endl;
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
	cout << "���������� ������� �������������� ��������� �������" << endl;
	return avg;*/
	cout << "���������� ������� �������������� ��������� �������" << endl;
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
	cout << "���������� ����������� �������� �� �������" << endl;
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
	cout << "���������� ������������ �������� �� �������" << endl;
	return max;
}

void shiftLeft(int arr[], int SIZE, int i, int indent)
{
	cout << "��������� ����������� ����� ������� �� �������� ����� ��������� �����" << endl;
	cout << "������� ���� ��� ������: "; cin >> indent;
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
cout << "��������� ����������� ����� ������� �� �������� ����� ��������� ������" << endl;
cout << "������� ���� ��� ������: "; cin >> indent;
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
//	cout << "������� ����� ������� ������� � 0 (����� ���� " << SIZE - 1 << " ��� ��������: "; cin >> i;
//	cout << i << " - " << arr[i] << endl;
//} while (i <= SIZE - 1);
}

void UniqueRand(int arr[], int SIZE, int i)
{
	cout << "��������� ������ ���������� ������� �� 0 �� 9" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand()%10;
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << "���������� ������� � ����������� ����" << endl;
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
	cout << "�������� ������ ������ ������� (1-����� �� ������, �� 1 - ����� ����� �������): "; cin >> choice;
	if (choice == 1)
	{
		do
		{
			cout << "������� ����� ������� ������� � 0 (����� ���� " << SIZE << " ��� ��������: "; cin >> i;
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
	cout << "����� �� ����� " << arg << endl;
	cout << endl;
}

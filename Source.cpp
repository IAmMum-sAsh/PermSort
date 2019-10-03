#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

bool prov(int* Array, int n) {
	int flag = 1;
	for (int i = 0; i < n - 1; i++) {
		if (Array[i] <= Array[i + 1]) { flag++; }
	}
	//for (int i = 0; i < n; i++) { cout << Array[i] << " "; } cout << "\n";
	if (flag == n) { return true; }
	else { return false; }
}

int* sort(int* Array, int N, int n) {
	for (int i = 0; i < n - N; i++) {
		swap(Array[N], Array[N + i]);
		if (prov(Array, n)) { break; }
		N += 1;
		sort(Array, N, n);
		if (prov(Array, n)) { break; }
		N -= 1;
		swap(Array[N], Array[N + i]);
		if (prov(Array, n)) { break; }
	}
	return Array;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n, N = 0;
	cout << "Введите кол-во элементов одномерного массива для сортировки, не превышающее 1000: "; cin >> n;
	int* arr = new int[n];
	cout << "Введите " << n << " элементов одномерного массива для сортировки через enter\n"; for (int i = 0; i < n; i++) { cout << i + 1 << ": "; cin >> arr[i]; }

	char ch;
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;
	start = std::chrono::high_resolution_clock::now();

	if (!prov(arr, n)) { sort(arr, N, n); }
	cout << "\nКонечный ответ: ";
	for (int i = 0; i < n; i++) { cout << arr[i] << " "; }

	stop = std::chrono::high_resolution_clock::now();
	int time = std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();
	std::cout << "\nВремя: " << time / 3600 << " часов " << (time % 360) / 60 << " минут " << time % 60 << " секунд\n";

	return 0;
}
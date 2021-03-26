#include <iostream>

using namespace std;

int main()
{
	int* time = new int(10);
	int n = 20;
	int* arr = new int(n);
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 2000;
		cout << arr[i] << " ";
	}
	cout << endl;
	int buf;
	for (int i = n; i > 1; i--) {
		bool flag = false;
		int sh = 0;
		for (int j = 0; j < i / 2;) {
			int largest = j, left = 2 * j + 1, right = 2 * j + 2;
			if (arr[left] > arr[largest]) {
				buf = arr[left];
				arr[left] = arr[largest];
				arr[largest] = buf;
				flag = true;
			}
			if (right < i) {
				if (arr[right] > arr[largest]) {
					buf = arr[right];
					arr[right] = arr[largest];
					arr[largest] = buf;
					flag = true;
				}
			}
			if (flag && j > 0) {
				j = (j - 1) / 2;
				sh++;
				flag = false;
			}
			else {
				j = j + 1 + sh;
				sh = 0;
			}
		}
		buf = arr[i - 1];
		arr[i - 1] = arr[0];
		int k;
		int index;
		for (k = 0; k < i/2;) {
			index = k;
			int left = k * 2 + 1;
			int right = k * 2 + 2;
			if (right < i) {
				if (arr[left] > arr[right]) {
					arr[k] = arr[left];
					k = left;
				}
				else {
					arr[k] = arr[right];
					k = right;
				}
			}
			else {
				arr[k] = arr[left];
				k = left;
			}
		}
		arr[index]=buf;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
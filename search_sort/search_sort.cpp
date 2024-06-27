	#include<iostream>
	#include<conio.h>
	using namespace std;

//====================================S O R T==========================================

	class sort {
	public:
		int* arr;
		int capacity;
//=====================================
		sort(int array[], int num);
		void bubble_sort();
		void insetion_sort();
		int partition(int start, int end);
		void quick_sort(int start, int end);
		void merge(int const left, int const mid, int const right);
		void merge_sort(int const begin, int const end);
	};
	sort::sort(int array[], int num) {
		arr = array;
		capacity = num;
	}
	void sort::bubble_sort() {
		int i, j;
		for (i = 0; i < (capacity - 1); i++)
			for (j = 0; j < (capacity - i - 1); j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);
		int k;
		for (k = 0; k < capacity; k++)
			cout << arr[k] << " ";
		cout << endl;
	}
	void sort::insetion_sort() {
		int i, key, j;
		for (i = 1; i < capacity; i++) {
			key = arr[i];
			j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
		int k;
		for (k = 0; k < capacity; k++)
			cout << arr[k] << " ";
		cout << endl;
	}
	int sort::partition( int start, int end) {
		int pivot = arr[start];

		int count = 0;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] <= pivot)
				count++;
		}
		int pivotIndex = start + count;
		swap(arr[pivotIndex], arr[start]);
		int i = start, j = end;
		while (i < pivotIndex && j > pivotIndex) {

			while (arr[i] <= pivot) {
				i++;
			}

			while (arr[j] > pivot) {
				j--;
			}

			if (i < pivotIndex && j > pivotIndex) {
				swap(arr[i++], arr[j--]);
			}
		}
		return pivotIndex;
	}
	void sort::quick_sort(int start, int end){
		if (start >= end)
			return;
		int p = partition(start, end);
		quick_sort(start, p - 1);
		quick_sort(p + 1, end);
	}
	void sort::merge(int left, int mid, int right) {
			int subArrayOne = mid - left + 1;
			int subArrayTwo = right - mid;
			auto* leftArray = new int[subArrayOne],* rightArray = new int[subArrayTwo];
			for (auto i = 0; i < subArrayOne; i++)
				leftArray[i] = arr[left + i];
			for (auto j = 0; j < subArrayTwo; j++)
				rightArray[j] = arr[mid + 1 + j];

			auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
			int indexOfMergedArray = left;
			while (indexOfSubArrayOne < subArrayOne
				&& indexOfSubArrayTwo < subArrayTwo) {
				if (leftArray[indexOfSubArrayOne]
					<= rightArray[indexOfSubArrayTwo]) {
					arr[indexOfMergedArray]
						= leftArray[indexOfSubArrayOne];
					indexOfSubArrayOne++;
				}
				else {
					arr[indexOfMergedArray]
						= rightArray[indexOfSubArrayTwo];
					indexOfSubArrayTwo++;
				}
				indexOfMergedArray++;
			}
			while (indexOfSubArrayOne < subArrayOne) {
				arr[indexOfMergedArray]
					= leftArray[indexOfSubArrayOne];
				indexOfSubArrayOne++;
				indexOfMergedArray++;
			}
			while (indexOfSubArrayTwo < subArrayTwo) {
				arr[indexOfMergedArray]
					= rightArray[indexOfSubArrayTwo];
				indexOfSubArrayTwo++;
				indexOfMergedArray++;
			}
			delete[] leftArray;
			delete[] rightArray;
	}
	void sort::merge_sort(int begin, int end) {
		if (begin >= end)
			return;
		int mid = begin + (end - begin) / 2;
		merge_sort(begin, mid);
		merge_sort( mid + 1, end);
		merge(begin, mid, end);
	}

//==================================S E A R C H========================================
	
	class search {
	public:
		int* arr;
		int capacity;
		int element;
//======================================================
		search(int array[], int num, int searchnum);
		void linear_search();
		void binary_search();
	};
	search::search(int array[], int num, int searchnum) {
		arr = array;
		capacity = num;
		element = searchnum;
	}
	void search::linear_search() {
		int i;
		for (i = 0; i < capacity; i++)
			if (arr[i] == element)
				cout << "Element is present at index:" << i;
		cout << "Element is not present in array";
	}
	void search::binary_search() {
		int low = 0;
		int high = (capacity - 1);
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] == element)
				cout << "Element is present at index:" << mid;
			if (arr[mid] < element)
				low = mid + 1;
			else
				high = mid - 1;
		}
		cout << "Element is not present in array";
		
	}

//====================================M A I N===========================================

	int main() {

		return 0;
	}

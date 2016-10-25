// Jacob Poole
// David Zheng
// Ryan Ulep
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>

using namespace std;
const int NUMBERS_SIZE = 50000;
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;

int partition_midpoint(int numbers[], int i, int k){
	int l = 0;
	int h = 0;
	int midpoint = 0;
	int pivot = 0;
	int temp = 0;
	bool done = false;

	midpoint = i + (k - i) / 2;
	pivot = numbers[midpoint];

	l = i;
	h = k;

	while(!done){
		while(numbers[l] < pivot){
			++l;
		}
		while(pivot < numbers [h]){
			--h;
		}
		if(l >= h){
			done = true;
		}
		else{
			temp = numbers[l];
			numbers[l] = numbers[h];
			numbers [h] = temp;

			++l;
			--h;
		}
	}
	return h;
}

void Quicksort_midpoint(int numbers[], int i, int k){
	int j = 0;
	if (i >= k){
		return;
	}
    j = partition_midpoint(numbers, i, k);

    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j+1, k);

    return;

}

int partition_medianOfThree(int numbers[], int i, int k){
	int l = 0;
	int h = 0;
	int midpoint = 0;
	int median = 0;
	int pivot = 0;
	int temp = 0;
	bool done = false;

	midpoint = i + (k - i) / 2;
	if(numbers[i] < numbers[midpoint] && numbers[i] < numbers[k]){
		if(numbers[k] < numbers[midpoint]){
			median = k;
		}
		else{
			median = midpoint;
		}
	}
	else if(numbers[k] < numbers[i] && numbers[k] < numbers[midpoint]){
		if(numbers[i] < numbers[midpoint]){
			median = i;
		}
		else{
			median = midpoint;
		}
	}
	else{
		if(numbers[i] < numbers[k]){
			median = i;
		}
		else{
			median = k;
		}
	}

	pivot = numbers[median];

	l = i;
	h = k;

	while(!done){
		while(numbers[l] < pivot){
			++l;
		}
		while(pivot < numbers [h]){
			--h;
		}
		if(l >= h){
			done = true;
		}
		else{
			temp = numbers[l];
			numbers[l] = numbers[h];
			numbers [h] = temp;

			++l;
			--h;
		}
	}
	return h;
}


void Quicksort_medianOfThree(int numbers[], int i, int k){
	int j = 0;
	if (i >= k){
		return;
	}
    j = partition_medianOfThree(numbers, i, k);

    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j+1, k);

    return;

}

void InsertionSort(int numbers[], int numbersSize) {
   int i = 0;
   int j = 0;
   int temp = 0;  

   for (i = 1; i < numbersSize; ++i) {
      j = i;
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         --j;
      }
   }
   
   return;
}

int genRandInt(int low, int high) {
   return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int main(){
	int arr1[NUMBERS_SIZE];
	int arr2[NUMBERS_SIZE];
	int arr3[NUMBERS_SIZE];
	int elapsedTime;
	
	fillArrays(arr1, arr2, arr3);
	clock_t Start = clock();
	Quicksort_midpoint(arr1, 0, NUMBERS_SIZE - 1);
	clock_t End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << "Time for quicksort midpoint: " << elapsedTime << " milliseconds." << endl;
	
	clock_t Start2 = clock();
	Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE - 1);
	clock_t End2 = clock();
    elapsedTime = (End2 - Start2)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << "Time for quicksort median: " << elapsedTime << " milliseconds."  << endl;
	
	clock_t Start3 = clock();
	InsertionSort(arr3, NUMBERS_SIZE);
	clock_t End3 = clock();
    elapsedTime = (End3 - Start3)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
	cout << "Time for insertion sort: " << elapsedTime << " milliseconds."  << endl;
}
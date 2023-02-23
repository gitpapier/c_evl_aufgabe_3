#include <stdio.h>
#include <stdlib.h>

void printer(int value[], int numOfElements) {
	for (int i = 0; i < numOfElements; i++) {
		printf("|%d|", value[i]);
	}
	printf("\n");
}

int combine(int folge1[], int folge2[], int* combined) {
	for (int i = 0; i < 10; i++) {
		combined[i] = folge1[i];
		combined[i + 10] = folge2[i];
	}
	return 0;
}

int sorter(int value[], int numOfElements) {
	int temp = value[0];
	while (numOfElements--) {
		for (int i = 0; i < numOfElements; i++) {
			if (value[i] > value[i + 1]) {
				temp = value[i + 1];
				value[i + 1] = value[i];
				value[i] = temp;
			}

		}

	}
	return 0;
}

int checkSorted(int value[], int size) {
	for (int i = 0; i < size-1; i++) {
		if (value[i] > value[i + 1]) {
			return 1;
		}
	}
	return 0;
}

int* allocateArray(int *givenSize) {
	int size = givenSize;
	int correctInput = 1;
	printf("Please Enter the size of your Sequence. \n");
	scanf_s("%d", &givenSize);
	if (size == 0) {
		printf("Your input contained something that was no integer.\n");
		exit(1);
	}
	printf("Creating an Array with %d Elements.\n", size);
	
	int* sequenceArray = malloc(size * sizeof(int));

	printf("\nSequence created! Please enter your numbers in ascending order. Confirm each number with <ENTER>\n");
	do {
		for (int i = 0; i < size; i++) {
			scanf_s("%d%*c", &sequenceArray[i]);
		}
		printf("Array Elements are: ");
		for (int i = 0; i < size; i++) {
			printf("'%d'", sequenceArray[i]);
		}
		printf(".\n");
		if (checkSorted(sequenceArray, size) == 1) {
			printf("Error. Your Sequence was not sorted.\n");
		}
		else {
			correctInput = 0;
		}
	} while (correctInput == 1);
	return sequenceArray;
}

int main() {
	int numberOfElements = 0;
	char temp;
	int *combined;
	int correctInput=1;
	int sizeOne = 0;
	int* sequenceOne;
	int** sequenceOnePtr =& sequenceOne;
	int sizeTwo = 0;
	int* sequenceTwo;
	int** sequenceTwoPtr = &sequenceTwo;
	
	sequenceOne = allocateArray(sizeOne);
	printf("SizeOne==%d", sizeOne);
	sequenceTwo = allocateArray(sizeTwo);

	numberOfElements = sizeOne + sizeTwo;
	combined = (int*)malloc(numberOfElements * sizeof(int));
	combine(sequenceOnePtr, sequenceTwoPtr, combined);
	printf("Combined Array: ");
	for (int i = 0; i < numberOfElements; i++) {
		printf("'%d'", combined[i]);
	}

	free(sequenceOne);
	free(sequenceTwo);
	free(combined);
	return 0;

}
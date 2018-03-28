#pragma once

namespace sorting
{
	class SortAlogs
	{
	public:

		/***************************************
				MERGE SORT
		***************************************/

		static int mergeSort(int* input, int size)
		{
			if (size == 1)
			{
				return *input;
			}
			else
			{
				int mid = size/2;
				int rightShift = size % 2;
				mergeSort(input,mid);
				mergeSort(input+mid,mid+rightShift);			
				merge(input, input, input+mid, mid, mid+rightShift);
			}
		}

		static void merge(int* dest, int* left, int* right, int leftSize, int rightSize)
		{
			int* tempLeft = new int[leftSize];
			for (int i = 0; i < leftSize; i++)
			{
				tempLeft[i] = left[i];
			}
			
			int* tempRight = new int[rightSize];
			for (int i = 0; i < rightSize; i++)
			{
				tempRight[i] = right[i];
			}

			int leftIndex = 0;
			int rightIndex = 0;
			int destSize = leftSize + rightSize;
			int i = 0;
			for (; i < destSize && 
				   leftIndex < leftSize &&
				   rightIndex < rightSize; i++)
			{
				if (tempLeft[leftIndex] <= tempRight[rightIndex])					 
				{
					dest[i] = tempLeft[leftIndex];
					leftIndex++;
				}
				else 
				{
					dest[i] = tempRight[rightIndex];
					rightIndex++;
				}
			}

			while (leftIndex != leftSize)
			{
				dest[i++] = tempLeft[leftIndex];
				leftIndex++;
			}

			while (rightIndex != rightSize)
			{
				dest[i++] = tempRight[rightIndex];
				rightIndex++;
			}

			delete [] tempLeft;
			delete [] tempRight;
		}

		static void testMergeSort()
		{
			using namespace std;

			int input1[16] = {6,1,7,2,8,8,9,10,45,0,5,67,23,10,12,2};
			SortAlogs::mergeSort(input1, 16);
			for (int i = 0; i < 16; i++)
				cout << input1[i] << endl;
	
			cout << " Test 1 finished " 
				 << endl
				 << endl 
				 << endl;

			int input2[5] = {6,1,7,4,3};
			sorting::SortAlogs::mergeSort(input2, 5);
			for (int i = 0; i < 5; i++)
				cout << input2[i] << endl;
	
			cout << " Test 2 finished " 
				 << endl 
				 << endl
				 << endl;

			int input3[17] = {6,1,7,2,8,8,9,10,45,0,5,67,23,10,12,2,11};
			sorting::SortAlogs::mergeSort(input3, 17);
			for (int i = 0; i < 17; i++)
				cout << input3[i] << endl;
	
			cout << " Test 3 finished " 
				 << endl
				 << endl 
				 << endl;
		}

		/***************************************
				BUBLE SORT
		***************************************/
		static void bubleSort(int* input, int size)
		{
		    //	for 
            for (int i = 0 ; i < size; i++)
            {
                int minVal = input[i];
                int minValPos = i;

                for (int j = i + 1; j < size; j++)
                {
                    if (input[j] < minVal)
                    {
                        minVal = input[j];
                        minValPos = j;
                    }                    
                }

                input[minValPos] = input[i];
                input[i] = minVal;
            }
		}

        static void testBubleSort()
		{
            using namespace std;

			int input1[16] = {6,1,7,2,8,8,9,10,45,0,5,67,23,10,12,2};
			SortAlogs::bubleSort(input1, 16);
			for (int i = 0; i < 16; i++)
				cout << input1[i] << endl;
	
			cout << " Test 1 finished " 
				 << endl
				 << endl 
				 << endl;

			int input2[5] = {6,1,7,4,3};
			sorting::SortAlogs::bubleSort(input2, 5);
			for (int i = 0; i < 5; i++)
				cout << input2[i] << endl;
	
			cout << " Test 2 finished " 
				 << endl 
				 << endl
				 << endl;

			int input3[17] = {6,1,7,2,8,8,9,10,45,0,5,67,23,10,12,2,11};
			sorting::SortAlogs::bubleSort(input3, 17);
			for (int i = 0; i < 17; i++)
				cout << input3[i] << endl;
	
			cout << " Test 3 finished " 
				 << endl
				 << endl 
				 << endl;
        }

   		/***************************************
				INSERTION SORT
		***************************************/
		static void insertionSort(int* input, int size)
		{
            for (int i = 1; i < size; i++)
            {
                int key = input[i];
                int j = i - 1;

                while (j >= 0 && input[j] > key)
                {
                    input[j+1] = input[j];
                    j = j - 1;                   
                }

                input[j+1] = key;
            }
        }

        static void testInsertionSort()
		{
            using namespace std;

			int input1[16] = {6,1,7,2,8,8,9,10,45,0,5,67,23,10,12,2};
			SortAlogs::insertionSort(input1, 16);
			for (int i = 0; i < 16; i++)
				cout << input1[i] << endl;
	
			cout << " Test 1 finished " 
				 << endl
				 << endl 
				 << endl;

			int input2[5] = {6,1,7,4,3};
			sorting::SortAlogs::insertionSort(input2, 5);
			for (int i = 0; i < 5; i++)
				cout << input2[i] << endl;
	
			cout << " Test 2 finished " 
				 << endl 
				 << endl
				 << endl;

			int input3[17] = {6,1,7,2,8,8,9,10,45,0,5,67,23,10,12,2,11};
			sorting::SortAlogs::insertionSort(input3, 17);
			for (int i = 0; i < 17; i++)
				cout << input3[i] << endl;
	
			cout << " Test 3 finished " 
				 << endl
				 << endl 
				 << endl;
        }
	};
}


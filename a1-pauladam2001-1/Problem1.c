#include <stdio.h>

void read_vector(int array[100], int* size){
    /* Reads the size of the vector and <size> elements from the keyboard
     * Input: array[] - the vector in which we will store the integers; *size - here we will store the size of the array
     * Output: returns nothing; the size and the elements of the array through parameters
    */
    int i;
    printf("Size of the string: ");
    scanf_s("%d", size);
    printf("The array elements:\n");
    for(i = 0; i < *size ; i++){
        printf("\tElement %d : ", i + 1);
        scanf_s("%d", &array[i]);
    }
}

void print_vector(int array[100], int size){
    /* Prints the elements of the vector in the console
     * Input: array[] - the vector; size - its size
     * Output: nothing
    */
    int i;
    printf("Array elements are:\n");
    for(i = 0; i< size; i++)
        printf("%d ", array[i]);
    printf("\n\n");
}

int prime_number(int number){
    /* Checks if a number is prime or not
     * Input: number - the integer that will be checked
     * Output: returns 1 if the number is prime, 0 otherwise
    */
    int i;
    if(number <= 1)
        return 0;

    for(i = 2; i <= number / 2; i++)
        if(number % i == 0)
            return 0;

    return 1;
}

int prime_numbers_smaller_than_n(int n, int list_of_primes[]){
    /* Generates all the prime numbers smaller than n
     * Input: n - given natural number; list_of_primes[] - the prime numbers will be stored in this vector
     * Output: returns the size of the vector; the vector through parameters
    */
    int i, size = 0;
    for(i = 2; i < n; i++)
        if(prime_number(i))
            list_of_primes[size++] = i;

    return size;
}

void requirement_a_ui(){
    int n, list_of_primes[1000], size;
    printf("n=");
    scanf_s("%d", &n);
    size = prime_numbers_smaller_than_n(n, list_of_primes);
    print_vector(list_of_primes, size);
}

void longest_increasing_contig_subseq(int array[], int size, int* start_index, int* final_index){
    /* Finds the longest increasing contiguous subsequence, such the sum of that any 2 consecutive elements is a prime number
     * Input: array[] - a given vector of numbers; size - its size; *start_index - the index where the longest sequence will start, -1 otherwise;
       *final_index - the index where the longest sequence will end, -1 otherwise
     * Output: returns nothing; the start_index and the final_index through parameters
    */
    int maximum = 0, sum_of_2_consec_nr;
    for(int index = 0; index < size - 1; index++){
        int local_maximum = 0;
        for(int j = index; j < size - 1; j++){
            sum_of_2_consec_nr = array[j] + array[j + 1];
            if(prime_number(sum_of_2_consec_nr) && array[j] < array[j+1])
                local_maximum += 1;
            else
                break;
            if(local_maximum > maximum) {
                maximum = local_maximum;
                *start_index = index;
                *final_index = j + 1;
            }
        }
    }
}

void requirement_b_ui(int array[], int size){
    int start_index = -1, final_index = -1;
    longest_increasing_contig_subseq(array, size, &start_index, &final_index);      //THAT'S C++
    if(start_index == -1 && final_index == -1)
        printf("There is no such sequence!");
    else{
        printf("The longest increasing contiguous subsequence is:\n");
        for (int index = start_index; index <= final_index; index++)
            printf("%d ", array[index]);
        printf("\nThe length of this subsequence is: %d\n\n", final_index - start_index + 1);
    }
}

int gcd(int number1, int number2){
    while (number1 != number2){
        if (number1 > number2)
            number1 -= number2;
        else
            number2 -= number1;
    }
    return number1;
}

void longest_subseq_ex2(int array[], int size, int* start_index, int* final_index){
    int maximum = 0;
    for(int index = 0; index < size - 1; index++){
        int local_maximum = 0;
        for(int j = index; j < size - 1; j++){
            if(gcd(array[j], array[j+1]) == 1)
                local_maximum += 1;
            else
                break;
            if(local_maximum > maximum) {
                maximum = local_maximum;
                *start_index = index;
                *final_index = j + 1;
            }
        }
    }
}

void requirement_b_ex2_ui(int array[], int size){
    int start_index = 0, final_index = 0;
    int* start_index_pointer = &start_index;
    int* final_index_pointer = &final_index;
    longest_subseq_ex2(array, size, start_index_pointer, final_index_pointer);          //THAT'S C
    if(start_index == -1 && final_index == -1)
        printf("There is no such sequence!");
    else{
        printf("The longest contiguous subsequence is:\n");
        for (int index = start_index; index <= final_index; index = index + 1)
            printf("%d ", array[index]);
        printf("\nThe length of this subsequence is: %d\n\n", final_index - start_index + 1);
    }
}

int main(){

    //int option, array[100], size = -1;

    //int option, array[100] = {0,0,0,4,5,6,7,8}, size = 8;
    //int option, array[100] = {0,0,0,6,5,7,8,4}, size = 8;
    //int option, array[100] = {1,2,3,4,5,6,7,8}, size = 8;
    //int option, array[100] = {0,2,0,3,0,5,6,7}, size = 8;
    //int option, array[100] = {2,3,4,6,8}, size = 5;
    //int option, array[100] = {3,5,15,20,21,23}, size = 6;
    int option, array[100] = {3,5,15,20,21,23,24,46,1,5}, size = 10;

    do{

        printf("\n1. Read a vector of numbers from the console;");
        printf("\n2. Generate all the prime numbers smaller than a given natural number n;");
        printf("\n3. Given a vector of numbers, find the longest increasing contiguous subsequence, such the sum of that any 2 consecutive elements is a prime number;");
        printf("\n4. Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime;");
        printf("\n0. Exit program.");
        printf("\n\n Your option: ");
        scanf_s("%d", &option);

        switch(option){

            case 1:{
                read_vector(array, &size);
                printf("\n\n");
                print_vector(array, size);
                break;
            }
            case 2:{
                requirement_a_ui();
                break;
            }
            case 3:{
                if(size == -1)
                    printf("\nYou need to read a vector of numbers first!\n");
                else
                    requirement_b_ui(array, size);
                break;
            }
            case 4:{
                if(size == -1)
                    printf("\nYou need to read a vector of numbers first!\n");
                else
                    requirement_b_ex2_ui(array, size);
                break;
            }
            case 0:{
                printf("\nSee you later!");
                break;
            }
            default:{
                printf("\nThis is not a command!\n");
                break;
            }
        }
    }while(option!=0);

    return 0;
}

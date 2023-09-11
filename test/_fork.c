#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to perform addition
int performAddition(int a, int b) {
	return a + b;
}

// Function to perform subtraction
int performSubtraction(int a, int b) {
	return a - b;
}

// Function to perform multiplication
int performMultiplication(int a, int b) {
	return a * b;
}

int main() {
	int num1 = 10;
	int num2 = 5;
	int result_addition, result_subtraction, result_multiplication;
	pid_t pid_addition, pid_subtraction, pid_multiplication;

	printf("Parallel Math Operations\n");

	// Create child process for addition
	pid_addition = fork();

	if (pid_addition == -1) {
		perror("Fork failed");
		return 1;
	} else if (pid_addition == 0) {
		// Child process for addition
		result_addition = performAddition(num1, num2);
		printf("Child (Addition): %d + %d = %d\n", num1, num2, result_addition);
		return result_addition;
	}

	// Create child process for subtraction
	pid_subtraction = fork();

	if (pid_subtraction == -1) {
		perror("Fork failed");
		return 1;
	} else if (pid_subtraction == 0) {
		// Child process for subtraction
		result_subtraction = performSubtraction(num1, num2);
		printf("Child (Subtraction): %d - %d = %d\n", num1, num2, result_subtraction);
		return result_subtraction;
	}

	// Create child process for multiplication
	pid_multiplication = fork();

	if (pid_multiplication == -1) {
		perror("Fork failed");
		return 1;
	} else if (pid_multiplication == 0) {
		// Child process for multiplication
		result_multiplication = performMultiplication(num1, num2);
		printf("Child (Multiplication): %d * %d = %d\n", num1, num2, result_multiplication);
		return result_multiplication;
	}

	// Parent process waits for all child processes to complete
	int status;
	waitpid(pid_addition, &status, 0);
	waitpid(pid_subtraction, &status, 0);
	waitpid(pid_multiplication, &status, 0);

	// Sum the results from child processes
	int total_result = result_addition + result_subtraction + result_multiplication;
	printf("Parent: Sum of Results = %d\n", total_result);

	return 0;
}


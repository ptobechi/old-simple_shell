#include <stdio.h>
#include <string.h>

void printTokens(const char *str, const char *delimiter) {
	char *token;

	// Use strtok to tokenize the string
	token = strtok(str, delimiter);

	// Loop through and print tokens
	while (token != NULL) {
		printf("Token: %s\n", token);
		token = strtok(NULL, delimiter);
	}
}

int main() {
	const char *inputString = "Hello,World,This,is,a,test";
	const char *delimiter = ",";

	printTokens(inputString, delimiter);

	return 0;
}


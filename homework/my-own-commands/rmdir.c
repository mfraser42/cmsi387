#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int result = syscall(84, argv[1]);
	
	// Was attempting to allow optional arguments, so it can remove multiple directories at once. C does not support that apparently?
	
	if(result == -1) {
		char *errorMessage = "There is a problem with removing the directory.\nBe sure to check the name is correctly written.\n";
		syscall(1, 2, errorMessage, strlen(errorMessage));
	}
}

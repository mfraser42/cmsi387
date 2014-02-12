#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int result = syscall(84, argv[1]);
	
	if(result == -1) {
		char *errorMessage = "There is a problem with removing the directory.\nBe sure to check the name is correctly written\n";
		syscall(4, 2, errorMessage, strlen(errorMessage));
	}
}

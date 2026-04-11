*This project has been created as part of the 42 curriculum by jshim.*

# get_next_line

## Description

`get_next_line` is a function that reads a file descriptor and returns one line at a time each time the function is called.

The goal of this project is to understand how file descriptors work and how to read files efficiently using a buffer.
It also focuses on dynamic memory allocation, static variables, and handling partial reads.

The function continues reading from the file descriptor until a newline character (`\n`) or the end of file is reached. Each call returns the next line from the file, including the newline character if it exists.

Prototype:

```bash
char *get_next_line(int fd);
```

Return values:

* The next line read from the file descriptor
* `NULL` if there is nothing left to read or if an error occurs

## Instructions

### Compilation

Note: This project does not include a `main()` function. To test the function, you need to create your own `main.c` file. But I made a example `main.c` and `test.txt` for you. enjoy!

**Mandatory Part** Compile the program with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

**Bonus Part** Compile the program with:

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```

You may change the buffer size by modifying the value of `BUFFER_SIZE` during compilation.

Example:

```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c main.c
```

### Usage Example

Example program:

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
```

Run the program:

```
./a.out
```

## Algorithm Explanation

The implementation uses a static backup array to store remaining data for each file descriptor.

```
static char *backup[1024];
```

### Reading from the file

The function reads from the file descriptor using a buffer of size `BUFFER_SIZE`.
The read data is appended to the existing backup string until a newline character is found or the end of the file is reached.

Steps:

1. Allocate a buffer of size `BUFFER_SIZE + 1`
2. Read from the file descriptor using `read()`
3. Append the read content to the backup string
4. Continue until a newline character is found

### Extracting a line

Once a newline or end of file is detected:

1. The position of the newline character is located
2. The line is copied into a new string
3. The remaining part of the string is saved back into the backup storage

Example:

```
backup = "Hello\nWorld"
```

After extraction:

```
returned line -> "Hello\n"
remaining backup -> "World"
```

### Memory management

Temporary buffers are freed after use.
The previous backup string is also freed before assigning the new joined string.

When the backup becomes empty, it is freed and set to `NULL` to avoid memory leaks.

## Resources

### Documentation

Linux `read()` manual
[https://man7.org/linux/man-pages/man2/read.2.html](https://man7.org/linux/man-pages/man2/read.2.html)

File descriptor explanation
[https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)

Static variables in C
[https://www.geeksforgeeks.org/static-variables-in-c/](https://www.geeksforgeeks.org/static-variables-in-c/)

Dynamic memory allocation in C
[https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)

### AI Usage

AI was used to help detect and fix memory leaks during debugging of the program.
The implementation and algorithm design were written manually.

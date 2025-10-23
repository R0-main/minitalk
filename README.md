# minitalk

`minitalk` is a small C program that demonstrates how to print colourful messages to the terminal using the custom [`ft_fprintf`](dependencies/ft_libc/includes/ft_fprintf.h) helper provided by the bundled `ft_libc` library. The project currently serves as a minimal scaffold that can be extended to experiment with additional messaging features.

## Project Layout

```
.
├── Makefile            # Build orchestration
├── README.md           # Project documentation
├── dependencies/
│   └── ft_libc/        # External utility library providing ft_fprintf and friends
└── src/
    └── main.c          # Program entry point
```

## Requirements

- A POSIX-compatible environment with `gcc`
- GNU `make`
- Git (only required on the first build to fetch the `ft_libc` submodule automatically)

## Building the Project

```bash
make
```

The Makefile will fetch (if necessary) and compile the `ft_libc` dependency, build the object files under `objects/`, and produce the `minitalk` executable in the repository root.

To remove build artefacts, run:

```bash
make clean
```

To remove both the artefacts and the executable, run:

```bash
make fclean
```

For a fresh rebuild, use:

```bash
make re
```

## Running

After building, execute the program with:

```bash
./minitalk
```

You should see a red message printed to standard output, confirming that `ft_fprintf` is working correctly.

## Code Example

The core of the project lives in [`src/main.c`](src/main.c). The following example shows how the program uses `ft_fprintf` to print a coloured string:

```c
#include "ft_fprintf.h"
#include <colors.h>
#include <stdlib.h>

int main(void)
{
        ft_fprintf(STDOUT_FILENO, RED "Hello, colourful world!\n" RESET);
        return (EXIT_SUCCESS);
}
```

To experiment with different colours, include the relevant colour macros from `colors.h` and adjust the format string:

```c
ft_fprintf(STDOUT_FILENO, GREEN "Success!\n" RESET);
```

Feel free to replace the message body or extend the program with additional logic—`make re` will quickly rebuild your changes.

## Troubleshooting

- **`git` permission errors while fetching `ft_libc`** – Ensure your environment has access to GitHub via SSH, or pre-clone `dependencies/ft_libc` manually.
- **Missing `colors.h` or `ft_fprintf.h`** – Double-check that the dependency clone completed successfully and that the include paths in the Makefile point to `dependencies/ft_libc/includes`.

## License

This repository does not currently declare a license. Please consult the repository owner before using it in another project.

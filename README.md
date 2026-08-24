A custom, minimalist Unix command-line interpreter (shell) developed in C as part of the Holberton School low-level programming curriculum. It replicates basic functionalities of the standard `sh` shell, supporting both interactive and non-interactive modes.

## Requirements

- **Operating System:** Ubuntu 20.04 LTS
- **Compiler:** `gcc` using options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Coding Style:** Betty style guidelines

## Compilation

To compile the shell, run the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
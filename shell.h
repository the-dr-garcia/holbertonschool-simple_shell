#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

/**
 * struct list_s - singly linked list
 * @dir: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure for path directories
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

#endif /* SHELL_H */

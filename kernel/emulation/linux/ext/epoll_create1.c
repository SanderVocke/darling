#include "./sys/epoll.h"
#include "../errno.h"
#include "../base.h"
#include <asm/unistd.h>

extern long cerror(int __err);

int epoll_create1 (int __flags)
{
	int rv;

	rv = LINUX_SYSCALL(__NR_epoll_create1, __flags);
	if (rv < 0)
	{
		cerror(rv);
		return -1;
	}

	return rv;
}


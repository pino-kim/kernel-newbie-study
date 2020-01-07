/* SPDX-License-Identifier: GPL-2.0-or-later */
/* Generic task switch macro wrapper.
 *
 * It should be possible to use these on really simple architectures,
 * but it serves more as a starting point for new ports.
 *
 * Copyright (C) 2007 Red Hat, Inc. All Rights Reserved.
 * Written by David Howells (dhowells@redhat.com)
 */
#ifndef __ASM_GENERIC_SWITCH_TO_H
#define __ASM_GENERIC_SWITCH_TO_H

#include <linux/thread_info.h>

/*
 * Context switching is now performed out-of-line in switch_to.S
 */
extern struct task_struct *__switch_to(struct task_struct *,
				       struct task_struct *);
// 이전테스크의 구조체와 다음테스크의 구조체를 교체 후last 에 덮어쓴다. 
#define switch_to(prev, next, last)					\
	do {								\
		((last) = __switch_to((prev), (next)));			\
	} while (0)

#endif /* __ASM_GENERIC_SWITCH_TO_H */

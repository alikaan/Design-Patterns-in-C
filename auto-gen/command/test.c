/**
 *   2014-05-19
 * anonymouse(anonymouse@email)
 *
 * Copyright (C) 2000-2014 All Right Reserved
 * 
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 *
 * Auto generate for Design Patterns in C
 */
#include <stdio.h>
#include <stdlib.h>

#include <mycommon.h>
#include <myobj.h>
#include <mytrace.h>
#include <test_suite.h>
#include "flipup.h"
#include "flipdown.h"
#include "light.h"
#include "switcher.h"

static int test_main(void)
{
	struct switcher *sw;
	struct light *light;
	struct flipup *up;
	struct flipdown *down;
	_MY_TRACE_STR("test::main()\n");
	
	sw = malloc(sizeof(*sw));
	switcher_init(sw);

	light = malloc(sizeof(*light));
	light_init(light);

	up = malloc(sizeof(*up));
	flipup_init(up, light, 10);

	down = malloc(sizeof(*down));
	flipdown_init(down, light, 3);

	switcher_append(sw, &up->command);
	switcher_append(sw, &down->command);

	switcher_execute(sw);

	return 0;
}

static int test_main_entry(char *output, size_t sz)
{
	test_main();
	return 0;
}

void main_entry_test(void);
void main_entry_test(void)
{
	my_test_suite_add(test_main_entry, "Test command");
}

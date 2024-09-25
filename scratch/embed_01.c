// Ruby Agent -- a finger exercise in injection
// Copyright (C) 2024 Josef Philip Bernhart

#include <ruby.h>

int main(int argc, char* argv[])
{
	/* construct the VM */
	ruby_init();

	/* Ruby goes here */

	/* destruct the VM */
	return ruby_cleanup(0);
}

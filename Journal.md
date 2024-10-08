# Journal

This document is a journal, it documents the thought process and certain decisions
which are not in the code or notes. The most recent entry is on the top.

# 26. September 2024

The actual code which sets up the registers for the `mmap` syscall in the second
example of the [blog article](https://blog.f0b.org/2022/05/process-injection-on-linux-injecting-into-processes/)
is the following.

```
	regs2.rax = 9;		/* sys_mmap */
	regs2.rdi = 0;
	regs2.rsi = len;
	regs2.rdx = 5;		/* PROT_READ | PROT_EXEC */
	regs2.r10 = 0x22;	/* MAP_PRIVATE | MAP_ANONYMOUS */
	regs2.r8 = -1;
	regs2.r9 = 0;
```

The opcode for calling the `mmap` syscall is called `SYSCALL` and seems to be only
part of the intel 64 opcodes, I wondered where it was in the opcode lists, as I
was still familiar with the old calling style. Seems to be a "fast call" opcode,
whatever that means.

And regarding design, what do I want? A ruby interpreter inside a ruby interpreter
or a payload which reads the ruby interpreters internals in a light-weight fashion?


# 25. September 2024

Came home after doodling on a sheet of paper of how this simple finger exercise 
could be done. I have never implemented something, which "injected" itself into
other processes. This is normally the realm of trojans, viruses, root kits or other
nasty software.

So, for interacting with other processes there is this extensive and interesting
[blog article](https://blog.f0b.org/2022/05/process-injection-on-linux-injecting-into-processes/)
into which I need to dig into, as I have in the back of my head still a clue about
`ptrace` and `mmap` calls for hooking into other processes. I have seen how other
people dit stuff like that or mentioned it, but when it comes to me I normally
did not have the energy or enough "criminal energy" to play around with it.
Because I have not seen a usecase where people would want that besides criminal
exploits. **BUT** I was wrong, on the front of debugging, tracing and monitoring tools
stunts like that are something which can bring value. To play around with that
this project is just a finger exercise or in old terms "a hack".

The next piece in the puzzle is [embedding Ruby in C](https://silverhammermba.github.io/emberb/embed/).

I copied `scratch/embed_01.c` together just to get an embedded interpreter example
running and to refresh my dusted knowledge of gcc and make. Based on that I can
then write something, I have not yet an idea. The thing should be to get a tracer
process and a tracee process running, the tracee represents an interpreter like
just a cruby script and the tracer hooks into that one for instrumentation, with
something really simple.

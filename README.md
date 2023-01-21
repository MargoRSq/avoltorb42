<h1> École 42 projects </h1>
42 is a future-proof computer science training to educate the next generation of software engineers. The 42 program takes a project-based approach to progress and is designed to develop technical and people skills that match the expectations of the labor market.


<div style="display: flex;">
  <a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cld6fz08500210flcee07spu2/stats?cursusId=9&coalitionId=96" alt="avoltorb's 42 stats" /></a>
  <a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cld6fz08500210flcee07spu2/stats?cursusId=21&coalitionId=89" alt="avoltorb's 42 stats" /></a>
</div>


<h3>Sections</h3>

- [libft (Grade: 125/125)](#libft-grade-125125)
- [get\_next\_line (Grade: 125/125)](#get_next_line-grade-125125)
- [ft\_printf (Grade: 125/125)](#ft_printf-grade-125125)
- [so\_long (Grade: 115/125)](#so_long-grade-115125)
- [minitalk (Grade: 125/125)](#minitalk-grade-125125)
- [push\_swap (Grade: 125/125)](#push_swap-grade-125125)
- [philosophers (Grade: 125/125)](#philosophers-grade-125125)

## libft (Grade: 125/125)
This project is about understanding the way these functions work, implementing and learning to use them.

**Mandatory part**

- Implement the following functions
  - `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `strlen`, `memset`, `bzero`, `memcpy`, `memmove`, `strlcpy`, `strlcat`, `toupper`, `tolower`, `strchr`, `strrchr`, `strncmp`, `memchr`, `memcmp`, `strnstr`, `atoi`

- In order to implement the two following functions, `malloc()` used:
  - `calloc`
  - `strdup`

**Bonus part**
- Implement the following functions
  - `ft_lstnew`, `ft_lstmap`, `ft_lstiter`, `ft_lstclear`, `ft_lstdelone`, `ft_lstadd_back`, `ft_lstlast`, `ft_lstsize`, `ft_lstadd_front`, `ft_lstnew`

## get_next_line (Grade: 125/125)
This project is about programming a function that returns a line read from a file descriptor.

**Mandatory part**
- Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return `NULL` 

**Bonus part**
- `get_next_line()` can manage multiple file descriptors at the same time


## ft_printf (Grade: 125/125)
The key a successful ft_printf is a well-structured and extensible code.

**Mandatory part**
- Implement the following conversions:
   - `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%` 

**Bonus part**
- Manage any combination of the following flags: `-0.` and the field minimum width under all conversions.
- Manage all the following flags: `# +` (Yes, one of them is a space)


## so_long (Grade: 115/125)
This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements.
  <img src="https://sun9-east.userapi.com/sun9-32/s/v1/ig2/ZjsCd8o_K9arYXn-OWA2RYeata5_Pakw-VFjaw0T4JAbZq6rvc7QwrsK-loaCUMgn-b61CalvZZ53hqZlFfeDESa.jpg?size=762x342&quality=96&type=album" height="300" />

**Mandatory part**
- Draw a map, sprites, textures
- Implement simple game logic

**Bonus part**
- Create enemies and maybe animate them


## minitalk (Grade: 125/125)
The purpose of this project is to code a small data exchange program using UNIX signals

**Mandatory part**
- Create a communication program in the form of a `client` and a `server`.
- Only use these two signals: `SIGUSR1` and `SIGUSR2`.

**Bonus part**
- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support

## push_swap (Grade: 125/125)
Write a program in C called `push_swap` which calculates and displays on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

- You have 2 stacks named a and b.
  - **At the beginning:**
  - The `stack a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
  - The `stack b` is empty.
**Mandatory part**

- The goal is to sort in ascending order numbers into stack a only using those operations:
  - s - swap first 2 elems of the stack, p - push to the top, r - shift down elements on 1
    - `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`

**Bonus part**
- The `checker` program

## philosophers (Grade: 125/125)
This project is a training to multi-threads/multi-process programming with the use of mutex and semaphore. 
It contains 2 different programs simulating a twist of the famous Dining Philosophers problem.

**Mandatory part**
- Solve the problem using `threads` and `mutex`

**Bonus part**
- Solve the problem using `forks` and `semaphores`

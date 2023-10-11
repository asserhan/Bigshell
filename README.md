# Bigshell
42 project, recoding our own little bash. A program capable of parsing a prompt and launching executables with arguments, along with a few built-in functions.

This project was one of the most challenging yet indulging projects of the 42 curriculum that I have faced so far, when you have to deal with many test cases and when you get to learn many things, from software architecture, system calls, file descriptors… to team coordination, management, and work distribution.

## The Challenge 

This was probably the biggest project I've done so far, as well as the first one I did as a group.  The goal was to create a mini version of bash, I say mini but it was still a huge project.  We had to learn how bash takes arguments, parses them, and executes them.I took the execution part, while the parsing part was taken by the other team member, We had to incorporate the following features:
- Display a promt while waiting for a new commmand.
- Have a working history.
- Find and launch executables (using the `PATH` variable or an absolute path).
- Handle `'` (single) and `"` (double) **quotes** like in bash.
- Implement **redirections** such as:
  - `<` redirect input.
  - `>` redirect output.
  - `<<` heredoc (doesn't affect history).
  - `>>` redirect output in append mode.
- Implement `|` (**pipes**).
- Handle **environment variables**.
- Handle `$?`.
- `ctrl-C`, `ctrl-D`, and `ctrl-\` should behave like in bash.
- Recreate the following **builtins**:
  - `echo` with option `-n`.
  - `cd` with only a relative or absolute path.
  - `pwd` (no flags).
  - `export` (no flags).
  - `unset` (no flags).
  - `env` (no flags or arguments).
  - `exit` (no flags).

### What Is Bash and How Does It Work?
The shell is a program that the user can use to interact with an operating system's services. Bash is the GNU shell, and is currently the most common shell program.  We took the challenge of recreating bash very literally, so the first thing we did was learn how bash actually works with the help of [this article](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf).  Essentially it breaks down the process into 4 steps: `lexer` → `parser` → `expander` → `executor`, which we replicated in our project. 
![bash steps](https://user-images.githubusercontent.com/68693691/193665518-0c0c7fec-38a9-4f6c-91ca-fef606abfb0d.png)
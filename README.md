## pipex

This project will let you discover in detail a UNIX mechanism that you already know
by using it in your program.

### Prerequisites

Your program will be executed as follows:
  ```sh
   ./pipex file1 cmd1 cmd2 file2
  ```
It must take 4 arguments:
* file1 and file2 are file names.
* cmd1 and cmd2 are shell commands with their parameters.


It must behave exactly the same as the shell command below:
  ```sh
   $> < file1 cmd1 | cmd2 > file2
  ```
<p align="right">(<a href="#top">back to top</a>)</p>

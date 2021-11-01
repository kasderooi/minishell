# minishell

minishell was my second big C project and my first group project. My teammate on this project was Niel van Aacken.

## Project description

Minishell is a program which behaves a lot like bash.  
It should:  
- prompt the user
- be able to execute executables in, or relative to, the $PATH variable 
- execute bin commands
- execute the builtins; echo, cd, pwd, export, unset, env and exit
- handle | pipes
- handle redirections <, <<, >>, >
- handle ' and "
- handle environmental variables and $?
- handle ctrl-c ctrl-d ctrl-\

## How to use
> Execute the following commands:

```shell
git clone https://github.com/kasderooi/minishell.git
cd minishell
make
./minishell
```

> use the program as you should with bash, the options are limited to as stated above

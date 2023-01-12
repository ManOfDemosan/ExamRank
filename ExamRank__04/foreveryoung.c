#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void ft_redirect(int oldfd, int newfd)
{
    if (oldfd != newfd)
    {
        dup2(oldfd, newfd);
        close(oldfd);
    }
    return ;
}

int ft_error(char *str)
{
    for (int i = 0; str[i]; ++i)
    {
        write(STDERR_FILENO, &str[i], 1);
    }
    return 1;
}

void ft_exec(char **cmd, int i, char **envp)
{
    cmd[i] = NULL;
    execve(cmd[0], cmd, envp);
    ft_error("ft_error: cannot execute ");
    ft_error(cmd[0]);
    ft_error("\n");
    exit(1);
}

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    int i = 0;
    int pid = 0;
    int in_fd = dup(STDIN_FILENO);
    int fd[2];

    while (argv[i] && argv[i + 1])
    {
        argv = argv + i + 1;
        i = 0;
        while(argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        if (argv == &argv[i])
            break;
        if (strcmp(argv[0], "cd") == 0)
        {
            if (i != 2)
                ft_error("ft_error: cd: bad arguments\n");
            else if (chdir(argv[1]) != 0)
            {
                ft_error("ft_error: cd: cannot change directory to ");
                ft_error(argv[1]);
                ft_error("\n");
            }
        }
        else if (argv[i] == NULL || strcmp(argv[i], ";") == 0)
        {
            ft_redirect(in_fd, STDIN_FILENO);
            pid = fork();
            if (pid < 0)
                exit(ft_error("fatal\n"));
            else if (pid == 0)
                ft_exec(argv, i, envp);
            else
                waitpid(0, 0, 0);
        }
        else if (strcmp(argv[i], "|") == 0)
        {
            if (pipe(fd) < 0)
                exit(ft_error("fatal\n"));
            pid = fork();
            if (pid < 0)
                exit(ft_error("fatal\n"));
            else if (pid == 0)
            {
                close(fd[0]);
                ft_redirect(in_fd, STDIN_FILENO);
                ft_redirect(fd[1], STDOUT_FILENO);
                ft_exec(argv, i, envp);
            }
            else
            {
                close(fd[1]);
                ft_redirect(fd[0], in_fd);
                waitpid(0, 0, 0);
            }
        }
    }
    close(in_fd);
    return (0);
}
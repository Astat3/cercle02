#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h> // Ajouté pour perror
#define READ 0
#define WRITE 1


/*ps aux | grep bash | grep -v "grep"*/

int main(void)
{
	int pid, pid2;
	int fd1[2], fd2[2];
	char *ps_cmd[] = {"ps", "aux", NULL};
	char *grep_cmd[]= {"grep", "bash", NULL};
	char *second_grep_cmd[] = {"grep", "-v", "grep", NULL};

	if(pipe(fd1) == -1)
	{
		perror("Error Pip");
		return 1;		
	}
	pid = fork();

	if (pid == 0) // child process
	{
		if (pipe(fd2) == -1)
		{
			perror("Error 2e pip");
			return 1;
		}
		pid2 = fork();// child childproces

		if (pid2 == 0) // if child child process
		{
			dup2(fd2[0], STDIN_FILENO);
			close(fd2[1]);
			close(fd2[0]);
			close(fd1[0]);
			close(fd1[1]);
			execve("/usr/bin/grep", second_grep_cmd, NULL);
			perror("Error grep -v");
			return 1;
		}
		else
		{
			dup2(fd1[READ], STDIN_FILENO);
			dup2(fd2[WRITE], STDOUT_FILENO);
			close(fd2[1]);
			close(fd2[0]);
			close(fd1[0]);
			close(fd1[1]);
			execve("/usr/bin/grep", grep_cmd, NULL);
			perror("Error grep -v");
			return 1;
		}
	}
	else
	{
			dup2(fd1[WRITE], STDOUT_FILENO); // ps aux
			close(fd1[1]);
			close(fd1[0]);
			execve("/bin/ps", ps_cmd, NULL);
			perror("Error child");
			return 1;
	}
}

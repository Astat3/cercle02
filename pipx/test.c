#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h> // Ajouté pour perror

//try to reproduce cat infile.txt | grep "a"

int main(void)
{
	int pid = 0;
	char *cat_cmd[] = {"cat","infile.txt", NULL};
	char *grep_cmd[] = {"wc", "-l", NULL};
	int pipfd[2];

	pipe(pipfd);
	if (pipe(pipfd) == -1)
		perror("Error Pip");
	pid = fork();
	if(pid == -1)
		perror("Error Fork");
	if (pid == 0)// child process
	{
		dup2(pipfd[0], STDIN_FILENO);
		close(pipfd[1]);// ne sert a rien
		close(pipfd[0]); // car dup
		execve("/usr/bin/wc", grep_cmd, NULL);
		perror("Error de grep");
		return 1;
	}
	else
	{
		dup2(pipfd[1], STDOUT_FILENO);
		close(pipfd[1]);
		close(pipfd[0]);
		execve("/bin/cat", cat_cmd, NULL);
		perror("Cat error");
		return 1;
	}

}

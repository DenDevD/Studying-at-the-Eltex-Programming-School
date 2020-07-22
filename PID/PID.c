#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
    pid_t branch_pid[2];
    pid_t small_branch_pid[2];
    int branch, small_branch;
    int axe = 2;

    for (branch = 0; branch < 2; branch++)
    {
        if ((branch_pid[branch] = fork()) == 0)
        {
            for (small_branch = 0; small_branch < axe; small_branch++)
            {
                if ((small_branch_pid[small_branch] = fork()) == 0)
                {
                    printf("small branch pid = %d, ppid = %d\n", getpid(), getppid());
                    return 0;
                }

                waitpid(small_branch_pid[small_branch], NULL, WUNTRACED);
            }
            printf("branch pid = %d, ppid = %d\n", getpid(), getppid());
            return 0;
        }
        waitpid(branch_pid[branch], NULL, WUNTRACED);
        axe--;
    }
    printf("Tree pid = %d\n", getpid());
    return 0;
}
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;


int main() {
    int ret, fd = open("alex", O_WRONLY | O_CREAT | O_TRUNC);
    char buf[20] = "hello";
    write(fd, buf, 4);
    close(fd);

    fd = open("alex", O_RDONLY);
    char ans[20], ch;
    while ((ret = read (fd, &ch, 1)) > 0)
	{
		putchar (ch);
	}
    return 0;
}

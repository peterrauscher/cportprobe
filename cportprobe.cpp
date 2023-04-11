#include <stdio.h>
#include <string.h>
#include <unistd.h>

void usage(FILE *fp, const char *path)
{
  const char *basename = strrchr(path, '/');
  basename = basename ? basename + 1 : path;
  fprintf(fp, "usage: %s [OPTION]\n", basename);
  fprintf(fp, "  -h, --help\t\t"
              "Print this help message.\n");
  fprintf(fp, "  --host string[]\t"
              "List of hosts to scan for open ports (comma-separated).\n");
  fprintf(fp, "  --port string[]\t"
              "List of ports to scan (comma-separated).\n");
}

int main(int argc, char *argv[])
{
}

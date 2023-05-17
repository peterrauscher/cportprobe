#include <string.h>
#include <iostream>
#include <boost/asio.hpp>

boost::asio::io_context ioContext;
boost::asio::ip::tcp::socket ioSocket(ioContext);

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

bool test_port_open(const std::string &hostaddr, unsigned short portnum)
{
  boost::asio::ip::tcp::endpoint _endpoint(boost::asio::ip::address::from_string(hostaddr), portnum);

  boost::system::error_code errorCode;
  ioSocket.connect(_endpoint, errorCode);

  return !errorCode;
}

int main(int argc, char *argv[])
{
  std::string hostaddr = "0.0.0.0";
  unsigned short port = 39577;

  if (test_port_open(hostaddr, port))
  {
    std::cout << "Port " << port << " is open" << std::endl;
  }
  else
  {
    std::cout << "Port " << port << " is closed" << std::endl;
  }
  return 0;
}
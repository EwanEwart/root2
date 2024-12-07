#include <iostream>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>

int cin_with_timeout
(
      std::string & inp
   ,  std::string const prompt=""
   ,  time_t seconds = 5
)
{
   fd_set fds;
   FD_ZERO(&fds);
   FD_SET(STDIN_FILENO, &fds);

   struct timeval timeout;
   timeout.tv_sec = seconds; // specify the timeout in seconds
   timeout.tv_usec = 0;      // specify the timeout in micro seconds

   std::cout << prompt << (prompt.size()?" ... ":"");
   std::cout.flush();

   /*
   Check the first NFDS descriptors each
   in READFDS     (if not NULL) for read readiness,
   in WRITEFDS    (if not NULL) for write readiness, and
   in EXCEPTFDS   (if not NULL) for exceptional conditions.
   If TIMEOUT is not NULL, time out after waiting the interval specified therein.

   Returns the number of ready descriptors, or -1 for errors.

   This function is a cancellation point and therefore not marked with __THROW.
   */
   /*
   extern int select
   (
        int __nfds
      , fd_set          *  __restrict __readfds
      , fd_set          *  __restrict __writefds
      , fd_set          *  __restrict __exceptfds
      , struct timeval  *  __restrict __timeout
   );
   */
   int ready = select(1, &fds, NULL, NULL, &timeout);

   if (ready == -1)
   {
      perror("select");
      return -1;
   }
   else if (ready > 0)
   {
      if (FD_ISSET(STDIN_FILENO, &fds))
      {
         char buffer[100];
         std::cin.getline(buffer, 100);
         inp=buffer;
      }
      return 0;
   }
   else
   {
      std::cout << '\n' << "Input timed out" << std::endl;
      return -1;
   }
}

// test bed
int main() // thread started by the C++ runtime
{
   std::string inp; // returned input
   // auto rtn = cin_with_timeout(inp);
   // auto rtn = cin_with_timeout(inp,"Your input");
   auto rtn = cin_with_timeout(inp,"Your input",8);

   std::cout << "Input was: \"" << inp << '"' << std::endl;

   return rtn;
}

#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

using SOCKET = int; // alias

using namespace std;

// int main(int argc, char const * argv[])
int cpp14_Chapter12_nw01() // entry point
{
   int rtn {};
   addrinfo hints {};
   hints.ai_family   = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
   addrinfo *servinfo {};
   auto rc = getaddrinfo   // 0 == success
   (
        "www.google.com"   // <-- : node : Hostname string to resolve like "www.example.com"
      , "80"               // <-- : service : Service name like "http" or port number like "80"
      , &hints             // <-- : hints : Options controlling returned socket types, families, etc
      , &servinfo          // --> : res : Pointer to linked list of resolved addresses and parameters
   );

   // netdb.h : error defines
   // #define EAI_AGAIN	  -3	/* Temporary failure in name resolution.  */
   // cout << "---> servinfo == " << servinfo << endl; // debug
   if(rc) { // error
      cout << "---> Connection failed ("<< rc <<") : check your url or port or both" << endl;
      return -1;
   }


   SOCKET sockfd
   {
      socket
      (
           servinfo->ai_family
         , servinfo->ai_socktype
         , servinfo->ai_protocol
      )
   };

   int connectionResult{ connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) };

   if (connectionResult == -1)
   {
      cout << "---> Connection failed!" << endl;
      return -1;
   }
   else
   {
      cout << "---> Connection successful!" << endl;
   }

   if(servinfo) {
      freeaddrinfo(servinfo);
      cout << "---> freed servinfo" << endl;
   }

   return 0;
}

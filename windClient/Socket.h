// Definition of the Socket class
// Copyright © 2002, Rob Tougher.
#ifndef Socket_class
#define Socket_class


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>


const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 1000;

class Socket
{
 public:
  Socket();
  virtual ~Socket();

  // Server initialization
  bool create();
  bool bind ( const int port );
  bool listen() const;
  bool accept ( Socket& ) const;

  // Client initialization
  bool connect ( const std::string host, const int port );

  // Data Transimission
  bool send ( const std::string ) const;
  int send_bytes ( unsigned char bytes[], int num_bytes);
  int recv ( std::string& ) const;
  int recv_bytes (unsigned char *buf ) const;
  void set_non_blocking ( const bool );
  bool is_valid() const { return m_sock != -1; }

 private:

  int m_sock;
  sockaddr_in m_addr;
  fd_set readfds,testfds;	
};


#endif

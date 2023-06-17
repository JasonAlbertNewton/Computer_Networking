 #include "socket.cpp"
 #include <unistd.h>
 #include <sys/param.h>
 #include <rpc/types.h>
 #include <getopt.h>
 #include <strings.h>
 #include <time.h>
 #include <signal.h>


//gloabal values
volatile int timerexpired = 0; 
int success = 0; 
int failed = 0; 
int bytes = 0; 

int http10 = 1; 

const int METHOD_GET = 0;
const int METHOD_HEAD = 1;
const int METHOD_OPTIONS =2; 
const string PROGRAM_VERSION = "1.5"


int method = METHOD_GET; 
int clients = 1; 
int force = 0;
int force_reload =0 ; 
int proxyport = 80; 


#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


// the function build and return a sock with the input of host location and client port location4 

//family is IPV4
//
//This function first define a socket address with the name of a and the hostent with hp 
//and the it start fill in the information and get the ip address from the host 
//further if it is null of course return error else get the addr from the hp which is the client port
//and the last of course connect it
//sock is a set of number which is the number of file profolio
int Socket(const char *host , int clientPort){
    
    int sock;
    unsigned long inaddr; 
    struct sockaddr_in ad;  
    struct hostent *hp; 

    memset (&ad , 0 , sizeof(ad));
    ad.sin_family = AF_INET;

    inaddr = inet_addr(host);

    if (inaddr != INADDR_NONE)
        memcpy(&ad.sin_addr, &inaddr , sizeof(inaddr));
    else
    {
        //get the ip with the domain name
        hp = gethostbyname(host); 
        
        if (hp == NULL)
            return -1; 
        
        memcpy(&ad.sin_addr , hp -> h_addr , hp->h_length); 
    }

    //convert  
    ad.sin_port = htons(clientPort);
   
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock < 0)
        return sock;
    if (connect (sock , (struct sockaddr *)&ad , sizeof(ad))<0)
        return -1; 
    return sock;
}

#include <stdio.h>      
#include <sys/types.h>
#include <ifaddrs.h>
#include <netinet/in.h> 
#include <string.h> 
#include <arpa/inet.h>

int main (int argc, const char * argv[]) {
    struct ifaddrs *ifAddrStruct=NULL;
    struct ifaddrs *ifa=NULL;
    void *tmpAddrPtr=NULL;

    if (argc<2)
    {
	    printf("Usage: %s <interface_name>\n", argv[0]);
	    return 0;
    }

    getifaddrs(&ifAddrStruct);

    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4
            // is a valid IP4 Address
	    if (strncmp(ifa->ifa_name, argv[1], strlen(argv[1]))==0)
	    {
            	tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            	char addressBuffer[INET_ADDRSTRLEN];
            
		inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            	printf("IP Address of %s is %s\n", ifa->ifa_name, addressBuffer);
	    }	
    	}
    }
    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);
    return 0;
}

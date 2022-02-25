#include <pwd.h>        // getpwuid
#include <stdlib.h>     // malloc
#include <limits.h>     // HOST_NAME_MAX
#include <unistd.h>     // exec and fork

#include "hostInfo.h"

char* getUserName(){
  uid_t uid = geteuid();
  struct passwd* pw = getpwuid(uid);
  if (pw){
    return pw->pw_name;
  }
  return "";
}


char* getHostname(){
    char* hostname =  (char*) malloc(sizeof(char) * HOST_NAME_MAX + 1);
    gethostname(hostname, HOST_NAME_MAX + 1);
    return hostname;
}

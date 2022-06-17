#include <lib/driver/egami.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

#include <sys/un.h>
#include <string.h>
#include <dirent.h>
#include <sys/reboot.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <lib/base/init.h>
#include <lib/base/init_num.h>
#include <lib/base/eerror.h>

eEGAMI *eEGAMI::instance= 0;

eEGAMI *eEGAMI::getInstance()
{
	return instance;
}

eEGAMI::~eEGAMI()
{
	return;
}

eEGAMI::eEGAMI()
{
	ASSERT(!instance);
	instance = this;

}

/** detecting whether base is starts with str
 
bool eEGAMI::startsWith (const char* base, const char* str) 
{
	return (strstr(base, str) - base) == 0;
}

 detecting whether base is ends with str
 
bool eEGAMI::endsWith (const char* base, const char* str) 
{
	int blen = strlen(base);
	int slen = strlen(str);
	return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}


* Check if a file exist using stat() function
* return 1 if the file exist otherwise return 0

bool eEGAMI::fileExists(const char *filename) 
{
	std::ifstream ifile(filename);
	return (bool)ifile;
}
*/
bool eEGAMI::FileExists(const string& file)
{
    std::ifstream in(file);
    if (in)
    {
        in.close();
        return true;
    }
    else
    {
        return false
    }
}	

bool eEGAMI::checkkernel()		
{	
	if(fileExists("/etc/hostname"))
	{
		eDebug("[EGAMI] Starting EGAMI OS...");
		return 0;
	}
	else
	{
		sync();
		reboot(RB_AUTOBOOT);
		return 0;
	}
}

#ifndef __egami_h
#define __egami_h

#include <lib/base/object.h>
#include <lib/python/connections.h>

class eEGAMI 
{
	static eEGAMI *instance;

#ifdef SWIG
	eEGAMI();
	~eEGAMI();
#endif
public:
#ifndef SWIG
	eEGAMI();
	~eEGAMI();
#endif	
	//eEGAMI();
	static eEGAMI *getInstance();
	bool FileExists(const string& file);
	//bool endsWith(const char* base, const char* str);
	//bool startsWith(const char* base, const char* str);
	//char* ReadProcEntry(const char *filename);
	bool checkkernel();
};

#endif

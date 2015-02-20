#ifndef _MAIN_H
#define _MAIN_H

class handler
{
public:
	static void error_callback(int error, const char *description)
	{
		fputs(description, stderr);
	}

	handler();
	~handler();

private:
	
};

#endif
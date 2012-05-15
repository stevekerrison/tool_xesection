// Copyright (c) 2012, Steve Kerrison, All rights reserved
// This software is freely distributable under a derivative of the
// University of Illinois/NCSA Open Source License posted in
// LICENSE.txt and at <http://github.xcore.com/>

#include "XE.h"
#include <iostream>
#include <stdlib.h>

void print_usage(std::ostream &o, const char *myname)
{
	o << "Usage: " << myname << " xefile [n]" << std::endl;
	o << "\tWhere n is the section to dump." << std::endl;
	return;
}

int main(int argc, const char *argv[])
{
	XE *xe;
	if (argc == 2 || argc == 3)
	{
		xe = new XE(argv[1]);
		if (!*xe)
		{
			std::cerr << "ERROR: Couldn't read file `" << argv[1] << "`, does it exist and is it an XE file?" << std::endl;
			return 2;
		}
	}
	if (argc == 2) //Dump section details
	{
		int i = 0;
		std::vector<const XESector *> sectors = xe->getSectors();
		for(std::vector<const XESector *>::iterator it = sectors.begin(); it != sectors.end(); ++it) {
			std::cout << "Sector " << i++ << ": type: " << (*it)->getType() << ", length: " << (*it)->getLength() << std::endl;
		}
	}
	else if (argc == 3) //Extract a section
	{
		xe->dumpSector(std::cout,atoi(argv[2]));
	}
	else
	{
		print_usage(std::cerr,argv[0]);
		return 1;
	}
	return 0;
}

#ifndef FILE_HANDLER
#define FILE_HANDLER

#include <iostream>
#include <sstream>
#include <list>

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>

#include "xmlinterp.hh"

using namespace std;
using namespace xercesc;

bool ExecPreprocesor(const char *fileName, stringstream &StrmCmds);
bool ReadXMLFile(const char* sFileName, Configuration &rConfig);

#endif
#pragma once

#include "XMLParser.h"

class XMLFacade
{
public:
	std::unique_ptr<XMLParser> parser;

	XMLFacade();
	~XMLFacade();

	std::vector<std::shared_ptr<ParserData>>loadScene(const char* path);
	std::vector<std::shared_ptr<ParserData>> getEquipmentDataList(const char* path);
	std::vector<std::shared_ptr<ParserData>> getNPCDataList(const char* path);
};
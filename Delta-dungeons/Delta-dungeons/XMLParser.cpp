#include "XMLParser.h"

using namespace rapidxml;

/// <summary>
/// The XMLParser contains the logic to parse an .xml file into ParserData objects.
/// </summary>

/// <summary>
/// parseXML makes use of rapidxml. rapidxml is used to parse the given xml file path into ParserData objects. By selecting the right nodes, the nodes information can be saved in a new ParserData object.
/// </summary>
/// <param name="path">The location of the .xml file that will be parsed.</param>
/// <returns>A list of ParserData objects that can be used to create Tiles</returns>

std::vector<std::shared_ptr<ParserData>> XMLParser::parseXML(const std::string& path)
{
	std::vector<std::shared_ptr<ParserData>> parserDataList;
	rapidxml::file<> xmlFile(path.c_str());
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node("tilemap");

	for (xml_node<>* child = node->first_node(); child; child = child->next_sibling())
	{
		for (xml_node<>* tile = child->first_node(); tile; tile = tile->next_sibling())
		{
			std::shared_ptr<ParserData> p = std::make_shared<ParserData>(tile->first_attribute("x")->value(), tile->first_attribute("y")->value(), tile->first_attribute("tile")->value());
			parserDataList.emplace_back(p);
		}
	}

	return parserDataList;
}

std::vector<std::shared_ptr<PokemonParserData>> XMLParser::loadPokemon(const std::string& path)
{
	std::vector<std::shared_ptr<PokemonParserData>> parserDataList;
	rapidxml::file<> xmlFile(path.c_str());
	rapidxml::xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	xml_node<>* node = doc.first_node("Pokemons");

	for (xml_node<>* pokemon = node->first_node(); pokemon; pokemon = pokemon->next_sibling())
	{
		std::shared_ptr<PokemonParserData> p = std::make_shared<PokemonParserData>(pokemon->first_attribute("name")->value(), pokemon->first_attribute("encounterRate")->value());
		parserDataList.emplace_back(p);
	}

	return parserDataList;
}
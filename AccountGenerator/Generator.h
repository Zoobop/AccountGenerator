#pragma once

#include <string>

#include "Structures/List.h"
#include "Utility/Random.h"

namespace AccountDatabase {

	class Generator
	{
	public:

		Generator() = default;

		static std::string GenerateEmail() 
		{
			const std::string emailUser = s_Users[mtk::Random::RandInt(0, (int)s_Users.Size()-1)].data();
			const std::string emailProvider = s_EmailProviders[mtk::Random::RandInt(0, (int)s_EmailProviders.Size()-1)].data();
			return emailUser + emailProvider;
		}

		static std::string GenerateUsername() 
		{
			const std::string userFirst = s_Users[mtk::Random::RandInt(0, (int)s_Users.Size()-1)].data();
			const std::string userLast = s_Users[mtk::Random::RandInt(0, (int)s_Users.Size()-1)].data();
			return userFirst + userLast;
		}

		static std::string GeneratePassword()
		{
			char passwordBuffer[s_PasswordLength];
			for (auto i = 0; i < s_PasswordLength; i++) 
			{
				int control = mtk::Random::RandInt(0, 2);
				const auto& symbolString = s_Symbols[control];
				passwordBuffer[i] = symbolString[mtk::Random::RandInt(0, (int)symbolString.size()-1)];
			}
			return passwordBuffer;
		}

	private:
		static const mtk::List<std::string_view> s_Users; 
		static const mtk::List<std::string_view> s_EmailProviders;
		static const mtk::List<std::string_view> s_Symbols;
		static constexpr int s_PasswordLength = 10;

	};

	const mtk::List<std::string_view> Generator::s_Users = {
			"fruitloops",
			"basket123",
			"zeronine",
			"help124",
			"seven32",
			"lookupjuice",
			"forklift69",
			"applejacks1",
			"runapp00",
			"getgood247",
			"dontdie19",
			"kelplin",
			"noresponse",
			"noreply",
			"daredevil",
			"cyclops45",
			"odyssey",
			"bowofdeath",
			"howtolie",
			"opopdock",
			"docker9",
			"report77",
			"finderkeeper",
			"sendhelp",
			"kleener",
			"dawkpaw",
			"doglover90",
			"cattrainer",
			"jupiter34",
			"flagstaff",
			"container",
			"fireworks",
			"unguarded",
			"deafening",
			"childlike",
			"interpret",
			"goosander",
			"dimwitted",
			"northwest",
			"starboard",
			"important",
			"plausible",
			"negotiate",
			"according",
			"underwear",
			"wandering",
			"variation",
			"reluctant",
			"overworld",
			"virtually",
			"immigrate",
			"housecoat",
			"distorted",
			"trackball",
			"cofferdam",
			"direction",
			"telephone",
			"synagogue",
			"satellite",
			"cormorant",
			"pistachio",
			"prettying",
			"ornaments",
			"loathsome",
			"cluttered",
			"regarding",
			"disappear",
			"inspiring",
			"extension",
			"liberated",
			"glowstone",
			"substance",
			"exhausted",
			"quarterly",
			"woodchuck",
			"appraiser",
			"miserable",
			"zygomatic",
			"deter",
			"cotton",
			"lighten",
			"intensity",
			"pair",
			"does",
			"telescope",
			"opossum",
			"grey",
			"booger",
			"ingredient",
			"peacock",
			"passage",
			"turtle",
			"college",
			"drowned",
			"obey",
			"ominous",
			"limit",
			"annoy",
			"lingering",
			"jumprope",
			"smiling",
			"whopping",
			"slide",
			"thundering",
			"piquant",
			"gloria",
			"yawning",
			"flippant",
			"motorboat",
			"junkie",
			"late",
			"peel",
			"juices",
			"whistle",
			"quiver",
			"chutney",
			"occipital",
			"crucial",
			"lone",
			"meniscus",
			"allianz",
			"next",
			"puffy",
			"shark",
			"potential",
			"hateful",
			"ponie",
			"spades",
			"dozen",
			"extraneous",
			"dapper",
				};
	const mtk::List<std::string_view> Generator::s_EmailProviders	= {
			"@gmail.com",
			"@yahoo.com",
			"@hotmail.com",
			"@outlook.com",
			"@aol.com",
			"@yandex.com",
			"@icloud.com"
		};
	const mtk::List<std::string_view> Generator::s_Symbols = {
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"0123456789",
		"!@#$%^&*-+?" 
	};

}
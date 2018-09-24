#include "webhook.h"

namespace SleepyDiscord {
	//Webhook::Webhook(const std::string * rawJSON) : Webhook(json::getValues(rawJSON->c_str(), fields)) {}

	//Webhook::Webhook(const nonstd::string_view& rawJSON) : Webhook(json::getValues(rawJSON.data(), fields)) {}

	//Webhook::Webhook(const json::Values values) :
	//	//variable           condition modifier value              felid         else
	//	Parent    (                    values[index(fields, "id"        )]     ),
	//	serverID  (setIfElse(isDefined,values[index(fields, "guild_id"  )], "")),
	//	channelID (                    values[index(fields, "channel_id")]     ),
	//	user      (User     (          values[index(fields, "user"      )]    )),
	//	name      (setIfElse(isDefined,values[index(fields, "name"      )], "")),
	//	avatar    (setIfElse(isDefined,values[index(fields, "avatar"    )], "")),
	//	token     (                    values[index(fields, "token"     )]     )
	//{}

	//const std::initializer_list<const char*const> Webhook::fields = {
	//	"id", "guild_id", "channel_id", "user", "name", "avatar", "token"
	//};

	Webhook::Webhook(const json::Value & json) :
		Webhook(json::fromJSON<Webhook>(json)) {
	}
	Webhook::Webhook(const nonstd::string_view & json) :
		Webhook(json::fromJSON<Webhook>(json)) {
	}
}

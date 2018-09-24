#include "json_wrapper.h"
#include <stdexcept>

namespace SleepyDiscord { namespace json {
	//Values getValues(const char* source, std::initializer_list<const char *const> const &names) {
	//	if (*source == 0) return std::vector<nonstd::string_view>{};
	//	const size_t numOfValues = names.size();
	//	std::vector<JSON_findMuitipleStruct>values(numOfValues);
	//	size_t ii = -1;
	//	for (const char *const name : names)
	//		values[++ii] = { name, 0, strlen(name), 0 };
	//	JSON_find(numOfValues, source, &values[0]);
	//	std::vector<nonstd::string_view> targets;
	//	targets.reserve(numOfValues);
	//	for (size_t i = 0; i < numOfValues; i++) {
	//		if (0 < values[i].namePosition) {
	//			targets.emplace_back(source + values[i].namePosition, values[i].valueLength);
	//		} else {
	//			targets.emplace_back(std::string(""));
	//		}
	//	}
	//	return targets;
	//}

	//Value getValue(const char* source, const char * name) {
	//	JSON_findMuitipleStruct value = { name, 0, strlen(name), 0 };
	//	JSON_find(1, source, &value);
	//	return nonstd::string_view(source + value.namePosition, value.valueLength);
	//}

	//Values getArray(const Value& _source) {
	//	const char* source = _source.data();
	//	if (source[0] != '[' || source[1] == ']') return Values();

	//	//get size of array and change size of target array
	//	const size_t sourceLength = _source.length();
	//	size_t arraySize = 0;
	//	size_t position = 1;
	//	for (; position < sourceLength; position++) {
	//		switch (source[position]) {
	//		case '"': JSON_skipString(source, &position); break;
	//		case '{': JSON_skipObject(source, &position); break;
	//		case '[': JSON_skipObject(source, &position); break;
	//		case ',': ++arraySize; break;
	//		default: break;
	//		}
	//	}
	//	for (bool loop = true; loop;) {	//count last variable
	//		switch (source[--position]) {
	//		case '[': return Values(); break;	//empty array
	//		case ' ': break;
	//		case ']': break;
	//		default:
	//			loop = false;
	//			++arraySize;
	//			break;
	//		}
	//	}
	//	Values target(arraySize);

	//	//fill the vector with variables
	//	position = 1;
	//	for (size_t index = 0; index < arraySize && position < sourceLength; ++position) {	//variables should be the same type, right?
	//		switch (source[position]) {
	//		case '"': {
	//			const size_t size = JSON_measureString(source, &position) - 1;	//the -1 removes the "
	//			target[index++] = nonstd::string_view(source + position + 1, size);
	//			position += size + 1;	//the +1 should skip the "
	//		} break;	//This should make a string, and the +1 and -1 removes the two "
	//		case '{': {
	//			const size_t size = JSON_measureObject(source, &position) + 1;	//the +1 adds a }
	//			target[index++] = nonstd::string_view(source + position, size);
	//			position += size;
	//		} break;
	//		case '-': case '0': case '1': case '2': case '3': case '4':
	//		case '5': case '6': case '7': case '8': case '9': {
	//			const size_t oldPosition = position;
	//			for (bool loop = true; loop && position < sourceLength;) {
	//				++position;
	//				switch (source[position]) {
	//					case '-': case '0': case '1': case '2': case '3': case '4':
	//					case '5': case '6': case '7': case '8': case '9':
	//						break;
	//					default:
	//						loop = false;
	//				}
	//			}
	//			const size_t size = position - oldPosition;
	//			target[index++] = nonstd::string_view(source + oldPosition, size);
	//		} break;
	//		}
	//	}
	//	return target;
	//}

	const std::string createJSON(std::initializer_list<std::pair<std::string, std::string>> json) {
		std::string target;
		target.reserve(2);	//revents crash
		for (std::pair<std::string, std::string> pair : json) {
			if (pair.second != "") {
				target += ",\"" + pair.first + "\":" + pair.second;
			}
		}
		target[0] = '{';
		target.push_back('}');
		return target;
	}

	const std::string string(const std::string s) {
		return s != "" ? '\"' + s + '\"' : "";
	}

	const std::string UInteger(const uint64_t num) {
		return std::to_string(num & 0x3FFFFFFFFFFFFF);   //just in case numbers are larger then 53 bits
	}

	const std::string optionalUInteger(const uint64_t num) {
		return num ? UInteger(num) : "";
	}

	const std::string integer(const int64_t num) {
		return std::to_string(num & 0x803FFFFFFFFFFFFF);  //just in case numbers are larger then 53 bits
	}

	const std::string optionalInteger(const int64_t num) {
		return num ? integer(num) : "";
	}

	const std::string boolean(const bool boolean) {
		return boolean ? "true" : "false";
	}
}}
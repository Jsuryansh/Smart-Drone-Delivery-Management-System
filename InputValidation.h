#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <string>

bool readPositiveInt(const std::string &prompt, int &value);
bool readNonNegativeInt(const std::string &prompt, int &value);
bool readDoubleValue(const std::string &prompt, double &value);
bool readBatteryValue(const std::string &prompt, double &value);
bool readNonEmptyLine(const std::string &prompt, std::string &value);

#endif

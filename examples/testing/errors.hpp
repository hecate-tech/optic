#ifndef ERRORS_H
#define ERRORS_H

#include <string>

// Example:
//
// error* func() {
// 	if (1 > 2) {
// 		return errors.New("Uh oh!");
// 	}
//
// 	return NULL;
// }

using std::string;

class error {
   public:
	// Returns the internal error message
	virtual char* Error() = 0;
	// optional unwrapper?
};

// xerrors namespace is not supposed to be exposed to the user, but only used by
// the errors class and other error related tools.
namespace xerrors {
class stringError : public error {
   private:
	// stores the internal error message.
	char* message;

   public:
	char* Error() override { return message; }

	stringError() = delete;  // Delete the default initializer.
	stringError(const string msg) {
		// Copy the std::string to a char* (c string).
		message = new char[msg.length() + 1];
		strcpy(message, msg.c_str());
	}
};
}  // namespace xerrors

class errors {
   public:
	// New returns a string error that fulfills the error abstract class.
	error* New(string str) { return new xerrors::stringError(str); }
} errors;  // Using a global errors object to use instead of static.

#endif  // ERRORS_H
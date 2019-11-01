#include <iostream>
#include <optional>
#include <string>

using std::string;

class error {
   public:
	virtual char* Error() = 0;
	// optional unwrapper.
};

namespace xerrors {

class stringError : public error {
   private:
	// const string message;
	char* message;

   public:
	char* Error() override { return message; }

	stringError() = delete;
	stringError(string msg) {
		message = new char[msg.length() + 1];
		strcpy(message, msg.c_str());
	}
};

}  // namespace xerrors

class errors {
   public:
	error* New(string str) { return new xerrors::stringError(str); }
} errors;

error* func() {
	if (5 > 2) {
		std::cout << "returning error " << std::endl;
		return errors.New("Uh oh!");
	}

	return NULL;
}

int main() {
	auto t = func();
	if (t != NULL) {
		std::cout << "created:" << t->Error() << std::endl;
	} else {
		std::cout << "error nil" << std::endl;
	}

	return 0;
}
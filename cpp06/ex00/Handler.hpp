#ifndef HANDLER_HPP
#define HANDLER_HPP
#include <iostream>

class Handler {
	protected:
		Handler* m_nextHandler;
  public:
    Handler(void);
    Handler(const Handler& other);
    Handler& operator=(const Handler& other);
    ~Handler(void);

		virtual void handle(const std::string& str) = 0;
		void setNextHandler(Handler* nextHandler);
};

#endif

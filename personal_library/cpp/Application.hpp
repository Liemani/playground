#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <map>
#include <stack>

// example
//  MethodProvider methodProvider = MethodProvider();
//  Application application = Application(methodProvider);
//  application.commandMethodDictionary["command"] = &MethodProvider::method;
//  ...
//  application.execute();

template <typename MethodProvider>
class Application {

public :
  typedef std::string Command;
  typedef void* (MethodProvider::*Method)(void);
  typedef std::map<Command, Method> CommandMethodDictionary;

private :
  typedef void* (Application::*BuiltinMethod)(void);
  typedef std::map<Command, BuiltinMethod> CommandBuiltinMethodDictionary;

  MethodProvider& methodProvider;

  std::stack<ViewController> viewControllerStack;

  int invoke(const Command& command);

  void willBeTerminated();

  CommandBuiltinMethodDictionary commandBuiltinMethodDictionary;

  void setUpBuiltinCommand();

  // builtin command
  void* printManual();
  void* printBuiltinCommand();
  void* listCommand();

public :
  CommandMethodDictionary commandMethodDictionary;

  bool isOn;

  Application(MethodProvider& methodProvider);

  void setUpCommand(CommandMethodDictionary commandMethodDictionary);

  void execute();

};

template <typename MethodProvider>
Application<MethodProvider>::Application(MethodProvider& methodProvider) :
  isOn(true),
  methodProvider(methodProvider) {
  this->setUpBuiltinCommand();
}



template <typename MethodProvider>
int Application<MethodProvider>::invoke(const Command& command) {
  typename Application::CommandBuiltinMethodDictionary::iterator builtinMethodIterator = this->commandBuiltinMethodDictionary.find(command);

  if (builtinMethodIterator != this->commandBuiltinMethodDictionary.end()) {
    (this->*(builtinMethodIterator->second))();

    return 0;
  }

  typename Application::CommandMethodDictionary::iterator methodIterator = this->commandMethodDictionary.find(command);

  if (methodIterator != this->commandMethodDictionary.end()) {
    (this->methodProvider.*(methodIterator->second))();

    return 0;
  }

  return 1;
}

template <typename MethodProvider>
void Application<MethodProvider>::setUpBuiltinCommand() {
  this->commandBuiltinMethodDictionary["h"] = &Application::printManual;
  this->commandBuiltinMethodDictionary["help"] = &Application::printManual;
  this->commandBuiltinMethodDictionary["man"] = &Application::printManual;
  this->commandBuiltinMethodDictionary["list"] = &Application::listCommand;
}

template <typename MethodProvider>
void* Application<MethodProvider>::printManual() {
  this->printBuiltinCommand();

  return NULL;
}

template <typename MethodProvider>
void* Application<MethodProvider>::printBuiltinCommand() {
  std::cout << "[builtin command list]" << std::endl;

  CommandBuiltinMethodDictionary& dictionary = this->commandBuiltinMethodDictionary;
  for (typename Application::CommandBuiltinMethodDictionary::iterator iterator = dictionary.begin();
      iterator != dictionary.end();
      ++iterator) {
    std::cout << iterator->first << std::endl;
  }

  return NULL;
}

template <typename MethodProvider>
void* Application<MethodProvider>::listCommand() {
  std::cout << "[command list]" << std::endl;

  CommandMethodDictionary& dictionary = this->commandMethodDictionary;
  for (typename Application::CommandMethodDictionary::iterator iterator = dictionary.begin();
      iterator != dictionary.end();
      ++iterator) {
    std::cout << iterator->first << std::endl;
  }

  return NULL;
}

template <typename MethodProvider>
void Application<MethodProvider>::setUpCommand(CommandMethodDictionary commandMethodDictionary) {
  this->commandMethodDictionary = commandMethodDictionary;
}

template <typename MethodProvider>
void Application<MethodProvider>::execute() {
  Command command;

  while (this->isOn) {
    std::cout << "enter command(man for manual) : ";
    std::getline(std::cin, command);

    if (not std::cin.good()) {
      this->willBeTerminated();
      break;
    }

    int statusCode = this->invoke(command);
    if (statusCode != 0)
      std::cout << "unknown command [" << command << "]" << std::endl;

    std::cout << std::endl;
  }
}

template <typename MethodProvider>
void Application<MethodProvider>::willBeTerminated() {
  std::cout << std::endl << "application terminated" << std::endl;
  this->isOn = false;
}

#endif // APPLICATION_HPP

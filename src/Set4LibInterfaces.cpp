#include "Set4LibInterfaces.hh"

Set4LibInterfaces::Set4LibInterfaces(/* args */)
{
}

Set4LibInterfaces::~Set4LibInterfaces()
{
}

void Set4LibInterfaces::AddLib(std::string Cmd)
{
    std::shared_ptr<LibInterface> LibPlugin = std::make_shared<LibInterface>(Cmd.c_str());
    insert(std::pair<std::string, std::shared_ptr<LibInterface>> (LibPlugin->getCmdName(), LibPlugin));
}

std::shared_ptr<LibInterface> Set4LibInterfaces::operator [] (std::string Cmd)
{
    return at(Cmd);
}

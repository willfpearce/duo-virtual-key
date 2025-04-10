#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <windows.h>

namespace fs = std::filesystem;

int main()
{
  TCHAR pathBuffer[MAX_PATH] = {0};
  GetModuleFileName(NULL, pathBuffer, MAX_PATH);
  fs::path p(pathBuffer);
  p.remove_filename();
  p.append("virtual-fido");

  std::string command = "start cmd /k \"cd /d " + p.generic_string() + " && go run ./cmd/demo start\"";
  return system(command.c_str());
}
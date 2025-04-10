#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <windows.h>

namespace fs = std::filesystem;

int main()
{
  if (system("go version >nul 2>&1"))
  {
    MessageBox(NULL, TEXT("Go is not installed or not in PATH."), TEXT("Error"), MB_OK | MB_ICONERROR);
    return 1;
  }

  TCHAR pathBuffer[MAX_PATH] = {0};
  GetModuleFileName(NULL, pathBuffer, MAX_PATH);
  fs::path p(pathBuffer);
  p.remove_filename();
  p.append("virtual-fido");

  std::string command = "start cmd /k \"cd /d " + p.generic_string() + " && go run ./cmd/demo start\"";
  return system(command.c_str());
}
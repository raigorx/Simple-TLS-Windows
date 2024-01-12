#include <stdio.h>
#include <windows.h>

void NTAPI __stdcall TLSCallbacks(PVOID DllHandle, DWORD dwReason,
                                  PVOID Reserved);

#pragma comment(linker, "/INCLUDE:_tls_used")

//  Same as code block TLS
//  EXTERN_C
//  #pragma const_seg(".CRT$XLB")
//  const
//  PIMAGE_TLS_CALLBACK _tls_callback = TLSCallbacks;

//  begin code block TLS
#pragma const_seg(".CRT$XLB")
EXTERN_C const PIMAGE_TLS_CALLBACK _tls_callback = TLSCallbacks;
//  end code block TLS

void NTAPI __stdcall TLSCallbacks(PVOID, DWORD dwReason, PVOID) {
  if (dwReason == DLL_PROCESS_ATTACH) {
    MessageBox(nullptr, L"TLS Callback (process attach)", L"", 0);
    wprintf(L"TLS Callback (process attach)\n");
  }
  if (dwReason == DLL_THREAD_ATTACH) {
    MessageBox(nullptr, L"TLS Callback (thread attach)", L"", 0);
    wprintf(L"TLS Callback (thread attach)\n");
  }
}

int main() {
  printf("Main function!\n");
  return EXIT_SUCCESS;
}

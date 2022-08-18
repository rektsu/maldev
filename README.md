# maldev
Repository to play with malware development and learn new techniques


# Basic Process Injection

One of the most basic malware technique, shellcode generated by msfvenom, and a wrapper to inject the sc in the (known) benign process and execute it. It has no real application further than a PoC for learning purposes since these API calls are signed by most AV's, shellcode is flagged with meterpreter therefore most AV's will flag as malicious and you the process ID is given by argument therefore you need to know previously the process ID to inject the shellcode.

1. WinAPI calls 
            - -> OpenProcess
            - -> VirtualAllocEx
            - -> WriteProcessMemory
            - -> CreateRemoteThread
            - -> CloseHandle



![basic_code_injection7](https://user-images.githubusercontent.com/15212130/185273472-bb480270-e881-419a-bdc6-0eb7f565df81.png)






![basic_code_injection4](https://user-images.githubusercontent.com/15212130/185273216-1eee928d-24ec-44c3-be21-f26561c15920.png)

![basic_code_injection5](https://user-images.githubusercontent.com/15212130/185273217-69763a38-2051-468b-82a6-8e44e40d2adc.png)
![basic_code_injection6](https://user-images.githubusercontent.com/15212130/185273376-0e38f199-b5be-40ce-97d7-f745b081d8b2.png)


# Before Shellcode encryption with XOR

![Before Shellcode Encryption with XOR](https://user-images.githubusercontent.com/15212130/185264181-caa24c96-6e91-430c-93f5-f61734dbe86a.png)


# After Shellcode encryption with XOR

![After Shellcode Encryption with XOR](https://user-images.githubusercontent.com/15212130/185264203-b9d33897-9335-41bf-af99-2b5f3d03f2d9.png)

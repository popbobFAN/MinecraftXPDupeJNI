gcc -c "-IC:\Program Files\Java\jdk1.8.0_311\include\win32" "-IC:\Program Files\Java\jdk1.8.0_311\include" src\dllmain.c
gcc -shared -o DUPEALERT.dll dllmain.o
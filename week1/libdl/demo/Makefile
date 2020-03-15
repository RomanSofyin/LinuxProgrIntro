all: exe

exe: main.c
	 gcc main.c -o hello -fPIC -ldl

lib: hello.c
	 gcc hello.c -o libHello.so -fPIC -shared

clean:
	 -rm hello libHello.so 2>/dev/null

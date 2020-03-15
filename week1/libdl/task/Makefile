all: exe

exe: solution.c
	 gcc solution.c -o solution -fPIC -ldl -Wl,-rpath -Wl,./

lib: testLib.c
	 gcc testLib.c -o libTestLib.so -fPIC -shared

clean:
	 -rm solution libTestLib.so 2>/dev/null

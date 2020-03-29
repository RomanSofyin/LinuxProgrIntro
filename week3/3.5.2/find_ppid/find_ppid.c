/*
Разработать программу solution, которая осуществляет поиск родительского PID
текущего процесса в файловой системе proc и выводит найденное значение на консоль. 
Результат, возвращаемый функций должен быть выведен отдельной строкой
(должен оканчиваться символом перевода строки \n) в stdio.

Пример вызова:
./solution
13221

Пример из 2.4.10:
void print_process_parents(pid_t pid) {
    pid_t current = pid;
    while (current != 1 ) {
        printf("%d\n",current);
        current = get_parent_pid(current)
    }
    printf("%d (init) \n",current);
}

Note: конечно намного эффективнее использовать getppid().

Подразумевается использование файла /proc/$$/status, который имеет ppid процесса с PID=$$:
roman@DESKTOP-AFO4O38:/proc/7$ cat status
Name:   bash
State:  S (sleeping)
Tgid:   7
Pid:    7
PPid:   6                       <----
TracerPid:      0
*/

void main() {
    
}
## Notes on session_task__scan_arr_of_struct_and_print_it task

in this code I face some problems
1- when I want to scan a char the char doesn't scan unless I add a white space before the %c
[source](https://stackoverflow.com/questions/29557448/c-program-doesnt-work-scanf-char)
(first answer)
2- I use fgets to scan the string and scanf to scan char and numbers, but scanf by default
add a new line after it and the fgets after it and it take this new line as input instead of the name,so
I add getchar() fun to get this new line and fgets work properly
[source](https://www.codingninjas.com/blog/2021/07/27/solved-the-problem-with-using-fgets-after-scanf/#:~:text=Because%20of%20this%20issue%2C%20the,getchar()%20after%20scanf().)
